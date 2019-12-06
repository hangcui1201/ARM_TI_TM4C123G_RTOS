The idle thread will run if no other threads are running.

tm4c123 -> TI-RTOS -> Development Tools -> EK-TM4C123GXL -> Driver Examples -> Empty Project

(1) empty_project_name -> rename

(2) all the other files -> rename

swi_thread.cfg -> Hwi(ti.sysbios.hal) -> New Hwi -> halHwi0 

ISR function: hwi_ledController

Interrupt number: 39

swi_thread.cfg -> Swi -> New Hwi -> swi0

ISR function: swi_ledController

Interrupt number: 2

