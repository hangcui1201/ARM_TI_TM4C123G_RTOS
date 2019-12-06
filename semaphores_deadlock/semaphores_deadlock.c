/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Semaphore.h>

/* TI-RTOS Header files */
#include <ti/drivers/GPIO.h>

/* Board Header file */
#include "Board.h"

extern Semaphore_Handle redSem, greenSem;

void blueController(void) // Idle thread runs
{
    int i;
    while(1)
    {
        GPIO_toggle(Board_LED0);
        for(i=0;i<1000000;i++){}
    }

}


void redController(UArg srg0, UArg arg1) //priority 2, deadlock with greenController
{
    int i;
    while(1)
    {
        Semaphore_pend(greenSem, BIOS_WAIT_FOREVER);
        GPIO_toggle(Board_LED2);
        for(i=0;i<1000000;i++){}
        Semaphore_post(redSem);
    }

}

void greenController(UArg srg0, UArg arg1) //priority 1, deadlock with redController
{
    int i;
    while(1)
    {
        Semaphore_pend(redSem, BIOS_WAIT_FOREVER);
        GPIO_toggle(Board_LED1);
        for(i=0;i<1000000;i++){}
        Semaphore_post(greenSem);
    }
}


int main(void)
{
    Board_initGeneral();
    Board_initGPIO();

    BIOS_start();

    return (0);
}
