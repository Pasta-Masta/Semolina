#include <stdio.h>

global HINSTANCE w32_instance = 0;

//Entry Points

int main(int argc, char **argv){
    w32_main_init(argc, argv);
    app();
    return(0);
}

int
WinMain(HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lpCmdLine,
        int nShowCmd){
            w32_WinMain_init(hInstance, hPrevInstance, lpCmdLine, nShowCmd);
            app();
            return(0);
        }

//Inits

function void
w32_main_init(int argc, char **argv){

}

function void
w32_WinMain_init(HINSTANCE hInstance,
                               HINSTANCE hPrevInstance,
                               LPSTR     lpCmdLine,
                               int       nShowCmd){
    int argc = __argc;
    char **argv = __argv;
    w32_instance = hInstance;
    w32_main_init(argc, argv);
}

//Memory

function void* os_memory_reserve(U64 size){
    return VirtualAlloc(0, size, MEM_RESERVE, PAGE_READWRITE);
}

function B32 os_memory_commit(void *ptr, U64 size){
    B32 result = (VirtualAlloc(ptr, size, MEM_COMMIT, PAGE_READWRITE) != 0);
    return(result);
}

function void os_memory_decommit(void *ptr, U64 size){
    VirtualFree(ptr, size, MEM_DECOMMIT);
}

function void os_memory_release(void *ptr, U64 size){
    VirtualFree(ptr, 0, MEM_RELEASE);
}

