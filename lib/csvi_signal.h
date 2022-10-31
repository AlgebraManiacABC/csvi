/**
 * TODO:
 * 
 *  Handle:
 *  - SIGSTOP/SIGCONT? (not sure I *can* handle these...
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
 * Is alerted to window size changes. Becomes true when a window size change is detected. Should be set to false after use.
 * 
 */
extern bool isWinch;