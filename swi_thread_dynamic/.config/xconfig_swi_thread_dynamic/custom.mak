## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,em4f linker.cmd package/cfg/swi_thread_dynamic_pem4f.oem4f

# To simplify configuro usage in makefiles:
#     o create a generic linker command file name 
#     o set modification times of compiler.opt* files to be greater than
#       or equal to the generated config header
#
linker.cmd: package/cfg/swi_thread_dynamic_pem4f.xdl
	$(SED) 's"^\"\(package/cfg/swi_thread_dynamic_pem4fcfg.cmd\)\"$""\"C:/Github_Repo/ARM_TI_TM4C123G_RTOS/workspace/swi_thread_dynamic/.config/xconfig_swi_thread_dynamic/\1\""' package/cfg/swi_thread_dynamic_pem4f.xdl > $@
	-$(SETDATE) -r:max package/cfg/swi_thread_dynamic_pem4f.h compiler.opt compiler.opt.defs
