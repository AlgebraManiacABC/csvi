#include "main.h"

#define MIN_COLUMNS	11
#define MIN_ROWS	3

/**
 * Clears the drawing space, then prints the cell borders 
 * 
 */
void printCellBorders(win w);

/**
 * Fills the terminal with characters indicating that the minimum size requirements are not met. 
 * 
 */
void printError(win w);

/**
 * Tells if the terminal has at least MIN_COLUMNS columns and MIN_ROWS rows
 * 
 * @param w the winsize struct containing current winsize
 * @return true if requirements met, else false
 */
bool winsizeRequirementsMet(win w);