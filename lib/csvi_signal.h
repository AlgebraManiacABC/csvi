/**
 * TODO:
 * 
 *  Handle:
 *  - SIGSTOP/SIGCONT?
 *  - SIGQUIT?
 *  - ???
 * 
 */

#include "main.h"

#define WC_SET true
#define WC_QUERY false

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

/**
 * Is alerted to window size changes. Query this function to tell if the window size has been changed. 
 * 
 * @param q whether the function should be reset (WC_QUERY or WC_SET)
 */
bool isWinch(bool q);