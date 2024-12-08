int32_t _init()
{
    if (__gmon_start__)
        __gmon_start__();
    
    frame_dummy();
    return __do_global_ctors_aux();
}

int32_t sub_8048370()
{
    int32_t var_4 = data_8049ff8;
    /* jump -> data_8049ffc */
}

int32_t printf(char const* format, ...)
{
    /* tailcall */
    return printf();
}

int32_t sub_8048386()
{
    /* tailcall */
    return sub_8048370(0);
}

int32_t puts(char const* str)
{
    /* tailcall */
    return puts(str);
}

int32_t sub_8048396()
{
    /* tailcall */
    return sub_8048370(8);
}

int32_t system(char const* line)
{
    /* tailcall */
    return system(line);
}

int32_t sub_80483a6()
{
    /* tailcall */
    return sub_8048370(0x10);
}

int32_t __gmon_start__()
{
    /* tailcall */
    return __gmon_start__();
}

int32_t sub_80483b6()
{
    /* tailcall */
    return sub_8048370(0x18);
}

void __libc_start_main(int32_t (* main)(int32_t argc, char** argv, char** envp), int32_t argc, char** ubp_av, void (* init)(), void (* fini)(), void (* rtld_fini)(), void* stack_end) __noreturn
{
    /* tailcall */
    return __libc_start_main(main, argc, ubp_av, init, fini, rtld_fini, stack_end);
}

int32_t sub_80483c6()
{
    /* tailcall */
    return sub_8048370(0x20);
}

int32_t __isoc99_scanf(char const* format, ...)
{
    /* tailcall */
    return __isoc99_scanf();
}

int32_t sub_80483d6()
{
    /* tailcall */
    return sub_8048370(0x28);
}

void __convention("regparm") _start(int32_t arg1, void (* arg2)()) __noreturn
{
    int32_t stack_end = arg1;
    __libc_start_main(main, __return_addr, &ubp_av, __libc_csu_init, __libc_csu_fini, arg2, &stack_end);
    /* no return */
}

void __do_global_dtors_aux()
{
    if (!__bss_start)
    {
        for (uint32_t dtor_idx.6161_1 = dtor_idx.6161; dtor_idx.6161_1 < 0; dtor_idx.6161_1 = dtor_idx.6161)
        {
            dtor_idx.6161 = dtor_idx.6161_1 + 1;
            __DTOR_LIST__[dtor_idx.6161_1 + 1]();
        }
        
        __bss_start = 1;
    }
}

int32_t frame_dummy()
{
    return __JCR_END__;
}

int32_t main(int32_t argc, char** argv, char** envp)
{
    puts("********************************…");
    puts("* \t     -Level00 -\t\t  *");
    puts("********************************…");
    printf("Password:");
    int32_t var_14;
    __isoc99_scanf("%d", &var_14);
    
    if (var_14 != 0x149c)
    {
        puts("\nInvalid Password!");
        return 1;
    }
    
    puts("\nAuthenticated!");
    system("/bin/sh");
    return 0;
}

void __libc_csu_init()
{
    _init();
}

void j___libc_csu_fini()
{
    /* tailcall */
    return __libc_csu_fini();
}

void __libc_csu_fini() __pure
{
    return;
}

int32_t __i686.get_pc_thunk.bx() __pure
{
    return;
}

int32_t __do_global_ctors_aux()
{
    return 0xffffffff;
}

int32_t _fini()
{
    return __do_global_dtors_aux();
}
