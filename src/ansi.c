#include "main.h"

void alternateBuffer()
{
    printf("\x1b[?1049h");
}

void restoreBuffer()
{
    printf("\x1b[?1049l");
}