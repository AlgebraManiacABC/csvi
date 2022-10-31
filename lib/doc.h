#include "main.h"
#include "print.h"

/**
 * Sets the width and height of the given viewport struct, based on the winsize
 * TODO: Viewport width will eventually be determined by the number of digits of the largest column number in view
 * 
 * @param w The current winsize
 * @param v Pointer to the viewport to be updated
 */
void resizeViewport(win w, viewport *v);