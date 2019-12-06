/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

/* TI-RTOS Header files */
#include <ti/drivers/GPIO.h>

/* Board Header file */
#include "Board.h"


void greenController(UArg arg0, UArg arg1)
{
    int i;
    while(1)
    {
        GPIO_toggle(Board_LED1);
        Task_sleep(500); //500ms
//        for(i=0;i<1000000;i++){}
    }

}


void redController(UArg arg0, UArg arg1)
{
    while(1)
    {
        GPIO_toggle(Board_LED2);
        Task_sleep(50); //50ms
    }
}


int main(void)
{
    Board_initGeneral();
    Board_initGPIO();


    BIOS_start();

    return (0);
}
