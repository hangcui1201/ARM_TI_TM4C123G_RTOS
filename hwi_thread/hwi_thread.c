#include <stdint.h>
#include <stdbool.h>

#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"

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


void Timer2A_Interrupt_Init(void);

void hwi_ledController(void)
{
    // Must clear timer flag from
    TimerIntClear(TIMER2_BASE, TIMER_TIMA_TIMEOUT);

    GPIO_toggle(Board_LED1);

}

int main(void)
{
    Board_initGeneral();
    Board_initGPIO();

    Timer2A_Interrupt_Init();

    System_flush();

    /* Start BIOS */
    BIOS_start();

    return (0);
}

void Timer2A_Interrupt_Init(void)
{
    uint32_t ui32Period;

    // Set CPU clock to 40MHz. 400MHz PLL/2 = 200 DIV 5 = 40MHz
    SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);

    // Enable Timer 2 periph clks
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);

    // Cfg Timer 2 mode - periodic
    TimerConfigure(TIMER2_BASE, TIMER_CFG_PERIODIC);

    // period = CPU clk div 2 (500ms)
    ui32Period = (SysCtlClockGet()/2);

    // Set Timer 2 period
    TimerLoadSet(TIMER2_BASE, TIMER_A, ui32Period);

    // Enable Timer 2 to interrupt CPU
    TimerIntEnable(TIMER2_BASE, TIMER_TIMA_TIMEOUT);

    // Enable Timer 2
    TimerEnable(TIMER2_BASE, TIMER_A);

}
























