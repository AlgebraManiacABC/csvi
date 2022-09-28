#include "print.h"

#define COLOR_ERROR "\x1b[31m"

void printCellBorders(win w)
{
	setTerm(TERM_CLEAR);

	teleportCursor(3,6);
	//printf("[%03d,%03d]",w.ws_row,w.ws_col);
	//	Cursor is placed at top-left of the border,
	//		leaving a row for column labels
	//		and 4 columns for row labels
	teleportCursor(2,5);
	printf("╔");
	for(int i=6; i<w.ws_col; i++) printf("═");
	printf("╗");

	for(int r=3; r<w.ws_row; r++)
	{
		teleportCursor(r,5);
		printf("║\x1b[%dC║",w.ws_col-4-2);
	}

	teleportCursor(w.ws_row,5);
	printf("╚");
	for(int i=6; i<w.ws_col; i++) printf("═");
	printf("╝");
	fflush(stdout);
}

void printError(win w)
{
	teleportCursor(1,1);
	printf(COLOR_ERROR);
	for(int r=0; r<w.ws_row; r++)
	{
		teleportCursor(r+1,1);
		for(int c=0; c<w.ws_col; c++)
		{
			printf("░");
		}
	}
	printf(RESET);
	fflush(stdout);
}

bool winsizeRequirementsMet(win w)
{
	return !(w.ws_col < MIN_COLUMNS || w.ws_row < MIN_ROWS);
}