#include "main.h"

#define MIN_COLUMNS	11
#define MIN_ROWS	4

//	Default cell width, in characters. Includes border.
#define DEFAULT_CELL_WIDTH	16
//	Default cell height, in characters. Includes border.
#define DEFAULT_CELL_HEIGHT	3

//	The row with which the top of the viewport (border) is aligned
#define VP_ROW_OFFSET 2
//	The default column with which the left of the viewport (border) is aligned
#define DEFAULT_VP_COL_OFFSET 5

#ifndef PRINT
#define PRINT
/**
 * A viewport struct contains information about the region that a user is viewing.
 * The user's "viewport" is simply a rectangular space that can pan around a csv document.
 * The viewport has a height and width, and a location in the document.
 */
typedef struct viewport
{
	// viewport width (including borders)
	uint w;
	//	viewport height (including borders)
	uint h;
	//	non-negative x position of the top-left corner of the viewport, relative to the "origin" (0)
	uint x;
	//	non-negative y position of the top-left corner of the viewport, relative to the "origin" (0)
	uint y;

}	viewport;

struct __BORDER_CHARACTERS
{
	char X[4];	//	Thick Intersection
	char V[4];	//	Thick Vertical
	char H[4];	//	Thick Horizontal
	char TL[4];	//	Thick Top-Left
	char TR[4];	//	Thick Top-Right
	char BL[4];	//	Thick Bottom-Left
	char BR[4];	//	Thick Bottom-Right
	char x[4];	//	Thin Intersect
	char v[4];	//	Thin Vertical
	char h[4];	//	Thin Horizontal
	char Vr[4];	//	Thick vertical + thin right intersect
	char Vl[4];	//	Thick vertical + thin left intersect
	char Hu[4];	//	Thick horizontal + thin up intersect
	char Hd[4];	//	Thick horizontal + thin down intersect

}	static const border =
{
	"╬",
	"║",
	"═",
	"╔",
	"╗",
	"╚",
	"╝",
	"┼",
	"│",
	"─",
	"╟",
	"╢",
	"╧",
	"╤"

};

#endif

/**
 * Tells if the terminal has at least MIN_COLUMNS columns and MIN_ROWS rows
 * 
 * @param w the winsize struct containing current winsize
 * @return true if requirements met, else false
 */
bool winsizeRequirementsMet(win w);

/**
 * Prints the entire viewport, including labels and borders 
 * 
 * @param w 
 */
void printViewport(win w, viewport v);

/**
 * Only prints the row and column labels (1,2,3; A,B,C) 
 * 
 * @param w 
 */
void printLabels(win w, viewport v);

/**
 * Only prints the cell borders 
 * 
 * @param w The current winsize
 */
void printCellBorders(win w, viewport v);

void printHorizontalCellBorders(win w, viewport v);
void printVerticalCellBorders(win w, viewport v);
void printIntersectingCellBorders(win w, viewport v);

/**
 * Only prints the main viewport border 
 * 
 * @param w 
 */
void printViewportBorder(win w, viewport v);

/**
 * Only prints the values inside the cell borders 
 * 
 * @param w The current winsize
 */
void printValues(win w, viewport v);

/**
 * Fills the terminal with characters indicating that the minimum size requirements are not met. 
 * 
 * @param w The current winsize
 */
void printError(win w);