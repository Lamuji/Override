int64_t _init()
{
    call_gmon_start();
    frame_dummy();
    return __do_global_ctors_aux();
}

int64_t sub_400660()
{
    int64_t var_8 = data_6011c8;
    /* jump -> data_6011d0 */
}

int32_t strncmp(char const* arg1, char const* arg2, uint64_t arg3)
{
    /* tailcall */
    return strncmp(arg1, arg2, arg3);
}

int64_t sub_400676()
{
    int64_t var_8 = 0;
    /* tailcall */
    return sub_400660();
}

int32_t puts(char const* str)
{
    /* tailcall */
    return puts(str);
}

int64_t sub_400686()
{
    int64_t var_8 = 1;
    /* tailcall */
    return sub_400660();
}

uint64_t fread(void* buf, uint64_t size, uint64_t count, FILE* fp)
{
    /* tailcall */
    return fread(buf, size, count, fp);
}

int64_t sub_400696()
{
    int64_t var_8 = 2;
    /* tailcall */
    return sub_400660();
}

int32_t fclose(FILE* fp)
{
    /* tailcall */
    return fclose(fp);
}

int64_t sub_4006a6()
{
    int64_t var_8 = 3;
    /* tailcall */
    return sub_400660();
}

int32_t system(char const* line)
{
    /* tailcall */
    return system(line);
}

int64_t sub_4006b6()
{
    int64_t var_8 = 4;
    /* tailcall */
    return sub_400660();
}

int32_t printf(char const* format, ...)
{
    /* tailcall */
    return printf();
}

int64_t sub_4006c6()
{
    int64_t var_8 = 5;
    /* tailcall */
    return sub_400660();
}

uint64_t strcspn(char const* arg1, char const* arg2)
{
    /* tailcall */
    return strcspn(arg1, arg2);
}

int64_t sub_4006d6()
{
    int64_t var_8 = 6;
    /* tailcall */
    return sub_400660();
}

void __libc_start_main(int32_t (* main)(int32_t argc, char** argv, char** envp), int32_t argc, char** ubp_av, void (* init)(), void (* fini)(), void (* rtld_fini)(), void* stack_end) __noreturn
{
    /* tailcall */
    return __libc_start_main(main, argc, ubp_av, init, fini, rtld_fini, stack_end);
}

int64_t sub_4006e6()
{
    int64_t var_8 = 7;
    /* tailcall */
    return sub_400660();
}

char* fgets(char* buf, int32_t n, FILE* fp)
{
    /* tailcall */
    return fgets(buf, n, fp);
}

int64_t sub_4006f6()
{
    int64_t var_8 = 8;
    /* tailcall */
    return sub_400660();
}

FILE* fopen(char const* filename, char const* mode)
{
    /* tailcall */
    return fopen(filename, mode);
}

int64_t sub_400706()
{
    int64_t var_8 = 9;
    /* tailcall */
    return sub_400660();
}

void exit(int32_t status) __noreturn
{
    /* tailcall */
    return exit(status);
}

int64_t sub_400716()
{
    int64_t var_8 = 0xa;
    /* tailcall */
    return sub_400660();
}

uint64_t fwrite(void const* buf, uint64_t size, uint64_t count, FILE* fp)
{
    /* tailcall */
    return fwrite(buf, size, count, fp);
}

int64_t sub_400726()
{
    int64_t var_8 = 0xb;
    /* tailcall */
    return sub_400660();
}

void _start(int64_t arg1, int64_t arg2, void (* arg3)()) __noreturn
{
    int64_t stack_end_1;
    int64_t stack_end = stack_end_1;
    __libc_start_main(main, __return_addr, &ubp_av, __libc_csu_init, __libc_csu_fini, arg3, &stack_end);
    /* no return */
}

void call_gmon_start()
{
    if (__gmon_start__)
        __gmon_start__();
}

void __do_global_dtors_aux()
{
    if (!completed.6531)
    {
        for (uint64_t dtor_idx.6533_1 = dtor_idx.6533; dtor_idx.6533_1 < 0; dtor_idx.6533_1 = dtor_idx.6533)
        {
            dtor_idx.6533 = dtor_idx.6533_1 + 1;
            __DTOR_LIST__[dtor_idx.6533_1 + 1]();
        }
        
        completed.6531 = 1;
    }
}

void frame_dummy()
{
    __JCR_END__;
}

int32_t main(int32_t argc, char** argv, char** envp)
{
    int32_t argc_1 = argc;
    char** argv_1 = argv;
    void var_78;
    *__builtin_memset(&var_78, 0, 0x60) = 0;
    void var_a8;
    *__builtin_memset(&var_a8, 0, 0x28) = 0;
    void var_118;
    *__builtin_memset(&var_118, 0, 0x60) = 0;
    int64_t var_10 = 0;
    int32_t var_14 = 0;
    FILE* fp = fopen("/home/users/level03/.pass", u"r…");
    
    if (!fp)
    {
        fwrite("ERROR: failed to open password f…", 1, 0x24, stderr);
        exit(1);
        /* no return */
    }
    
    int32_t rax = fread(&var_a8, 1, 0x29, fp);
    *(&var_a8 + strcspn(&var_a8, u"\n…")) = 0;
    
    if (rax != 0x29)
    {
        fwrite("ERROR: failed to read password f…", 1, 0x24, stderr);
        fwrite("ERROR: failed to read password f…", 1, 0x24, stderr);
        exit(1);
        /* no return */
    }
    
    fclose(fp);
    puts("===== [ Secure Access System v1.…");
    puts("/*******************************…");
    puts("| You must login to access this …");
    puts("\*******************************…");
    printf("--[ Username: ");
    fgets(&var_78, 0x64, __bss_start);
    *(&var_78 + strcspn(&var_78, u"\n…")) = 0;
    printf("--[ Password: ");
    fgets(&var_118, 0x64, __bss_start);
    *(&var_118 + strcspn(&var_118, u"\n…")) = 0;
    puts("********************************…");
    
    if (!strncmp(&var_a8, &var_118, 0x29))
    {
        printf("Greetings, %s!\n", &var_78, &var_78);
        system("/bin/sh");
        return 0;
    }
    
    printf(&var_78);
    puts(" does not have access!");
    exit(1);
    /* no return */
}

void __libc_csu_init()
{
    _init();
}

void __libc_csu_fini() __pure
{
    return;
}

int64_t __do_global_ctors_aux()
{
    return -1;
}

int64_t _fini()
{
    return __do_global_dtors_aux();
}

