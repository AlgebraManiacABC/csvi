#include "print.h"

#define COLOR_ERROR "\x1b[31m"

bool winsizeRequirementsMet(win w)
{
	return !(w.ws_col < MIN_COLUMNS || w.ws_row < MIN_ROWS);
}

void printViewport(win w, viewport v)
{
	setTerm(TERM_CLEAR);
	printLabels(w,v);
	printCellBorders(w,v);
	printViewportBorder(w,v);
	printValues(w,v);
}

void printLabels(win w, viewport v)
{
}

void printCellBorders(win w, viewport v)
{
	printHorizontalCellBorders(w,v);
	printVerticalCellBorders(w,v);
	//for(number of rows in viewport)
	//	teleportCursor(working row,5);
	//	moveRight(any partial cell width we begin at)
	//	for(x=0; until x = viewport width)
	//		print(intersect)
	//		x++;
	//		if(x < viewport width)
	//			moveRight(current cell width)
	//			x += current cell width

/*
	for(int r=0; r<v.h; r++)
	{
		teleportCursor(r+VP_ROW_OFFSET,DEFAULT_VP_COL_OFFSET);
		fflush(stdout);
		//moveCursor(DIR_RIGHT,?);
		for(int c=0; c<v.w; )
		{
			char b[4];
			deduceBorder(b,r,c,v);
			write(STDOUT_FILENO, b, sizeof(b));
			c++;
			if(c < v.w)
			{
				moveCursor(DIR_RIGHT,DEFAULT_CELL_WIDTH-1);
				fflush(stdout);
				c += DEFAULT_CELL_WIDTH-1;
			}
		}
	}
*/
}

void printHorizontalCellBorders(win w, viewport v)
{
	for(int r = DEFAULT_CELL_HEIGHT - (v.y % (DEFAULT_CELL_HEIGHT)); r<v.h; )
	{
		teleportCursor(r+VP_ROW_OFFSET,DEFAULT_VP_COL_OFFSET);
		fflush(stdout);
		for(int c=0; c<v.w; c++)
			write(STDOUT_FILENO, border.h, sizeof(border.h));
		r += DEFAULT_CELL_HEIGHT-1;
	}
	fflush(stdout);
}

void printVerticalCellBorders(win w, viewport v)
{
	for(int c = DEFAULT_CELL_WIDTH - (v.x % (DEFAULT_CELL_WIDTH)); c<v.w; )
	{
		teleportCursor(VP_ROW_OFFSET,DEFAULT_VP_COL_OFFSET+c);
		fflush(stdout);
		for(int r=0; r<v.h; r++)
		{
			write(STDOUT_FILENO, border.v, sizeof(border.v));
			fflush(stdout);
			write(STDOUT_FILENO, "\x1b[D\x1b[B", sizeof("\x1b[D\x1b[B"));
			fflush(stdout);
		}
		c += DEFAULT_CELL_WIDTH-1;
	}
}

void printIntersectingCellBorders(win w, viewport v)
{
}

void printViewportBorder(win w, viewport v)
{
	//	Uncomment below to check the window size
	teleportCursor(3,6);
	printf("[%03d,%03d]",w.ws_row,w.ws_col);
	teleportCursor(4,6);
	printf("[%03d,%03d]:[%02d,%02d]",v.x,v.y,(v.x % (DEFAULT_CELL_WIDTH)),(v.y % (DEFAULT_CELL_HEIGHT)));

	//	Cursor is placed at top-left of the border,
	//		leaving a row for column labels
	//		and 4 columns for row labels
	teleportCursor(VP_ROW_OFFSET,DEFAULT_VP_COL_OFFSET);
	fflush(stdout);
	write(STDOUT_FILENO, "╔", sizeof("╔"));
	for(int i=0; i<v.w-2; i++)
		write(STDOUT_FILENO, "═", sizeof("═"));
	write(STDOUT_FILENO, "╗", sizeof("╗"));

	for(int r=0; r<v.h-2; r++)
	{
		teleportCursor(VP_ROW_OFFSET+r+1,DEFAULT_VP_COL_OFFSET);
		printf("║\x1b[%dC║",v.w-2);
	}

	teleportCursor(VP_ROW_OFFSET+v.h-1,DEFAULT_VP_COL_OFFSET);
	fflush(stdout);
	write(STDOUT_FILENO, "╚", sizeof("╚"));
	for(int i=0; i<v.w-2; i++)
		write(STDOUT_FILENO, "═", sizeof("═"));
	write(STDOUT_FILENO, "╝", sizeof("╝"));
	fflush(stdout);
	//	Notice the space left on the bottom printing row for status and commands
}

void printValues(win w, viewport v)
{
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