#include "main.h"
#include "ansi.h"

int main()
{
    if(!isatty(STDOUT_FILENO))
    {
        fprintf(stderr,"Output is not to a terminal. Terminating.\n");
        return -1;
    }
    if(!isatty(STDIN_FILENO))
    {
        fprintf(stderr,"Input is not from a terminal. Terminating.\n");
        return -1;
    }
    alternateBuffer();
    restoreBuffer();
}