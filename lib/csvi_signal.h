/**
 * TODO:
 * 
 *  Handle:
 *  - SIGSTOP/SIGCONT
 *  - ???
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/**
 * Initializes all signal-related functions:
 *  - SIGINT
 *  - SIGWINCH
 * 
 */
int sigHandlerInit();

/**
 * Handles SIGINT 
 * 
 */
void sigIntHandler();

/**
 * Handles SIGTERM 
 * 
 */
void sigTermHandler();

/**
 * Handles SIGWINCH 
 * 
 */
void sigWinchHandler();