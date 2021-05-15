#include "Header.h"
#include <windows.h>

void setConsoleWindow()
{
    HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD crd = { 10, 10 };
    SMALL_RECT src = { 0, 0, crd.X - 1, crd.Y - 1 };
    SetConsoleWindowInfo(out_handle, true, &src);
    system("mode con cols=220 lines=50");
    SetConsoleScreenBufferSize(out_handle, crd);
}