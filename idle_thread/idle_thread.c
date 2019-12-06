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


// This function will be called when system is in idle
void ledController(void){

    GPIO_toggle(Board_LED2);
    Task_sleep(1000); // delay function

}

int main(void)
{
    // Call board init functions
    Board_initGeneral();
    Board_initGPIO();


    System_flush();
    BIOS_start();    //Start BIOS

    return (0);
}
