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

#define STACKSIZE 512


void task_ledController(UArg arg0, UArg arg1)
{
    while(1)
    {
        GPIO_toggle(Board_LED0);
        Task_sleep(100); //100ms
    }

}

int main(void)
{
    Task_Params taskParams;
    Task_Handle task0;

    Board_initGeneral();
    Board_initGPIO();

    Task_Params_init(&taskParams);

    taskParams.stackSize = STACKSIZE;
    taskParams.priority = 15;
    task0 = Task_create((Task_FuncPtr)task_ledController, &taskParams, NULL);

    if(task0 == NULL){
        System_abort("Task create failed");
    }

    BIOS_start();

    return (0);
}
