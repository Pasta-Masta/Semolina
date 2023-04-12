#pragma once

#undef function
#include <windows.h>
#define function static

function void w32_main_init(int argc, char **argv);
function void w32_WinMain_init(HINSTANCE hInstance,
                               HINSTANCE hPrevInstance,
                               LPSTR     lpCmdLine,
                               int       nShowCmd);