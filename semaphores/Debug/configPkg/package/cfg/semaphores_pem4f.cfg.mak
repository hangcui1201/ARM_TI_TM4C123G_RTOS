# invoke SourceDir generated makefile for semaphores.pem4f
semaphores.pem4f: .libraries,semaphores.pem4f
.libraries,semaphores.pem4f: package/cfg/semaphores_pem4f.xdl
	$(MAKE) -f C:\Github_Repo\ARM_TI_TM4C123G_RTOS\workspace\semaphores/src/makefile.libs

clean::
	$(MAKE) -f C:\Github_Repo\ARM_TI_TM4C123G_RTOS\workspace\semaphores/src/makefile.libs clean

