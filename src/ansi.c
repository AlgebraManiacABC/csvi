#include "main.h"

/**
 * Switches the terminal to the alternate buffer.
 *
 */
void alternateBuffer()
{
	printf("\x1b[?1049h");
}

/**
 * Switches the terminal back to the default buffer.
 *
 * Clears the alternate buffer.
 *
 */
void restoreBuffer()
{
	printf("\x1b[?1049l");
}