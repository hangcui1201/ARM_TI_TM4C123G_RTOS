# invoke SourceDir generated makefile for idle_thread.pem4f
idle_thread.pem4f: .libraries,idle_thread.pem4f
.libraries,idle_thread.pem4f: package/cfg/idle_thread_pem4f.xdl
	$(MAKE) -f C:\Github_Sync\ARM_TI_TM4C123G_RTOS\idle_thread/src/makefile.libs

clean::
	$(MAKE) -f C:\Github_Sync\ARM_TI_TM4C123G_RTOS\idle_thread/src/makefile.libs clean

