#include "doc.h"

void resizeViewport(win w, viewport *v)
{
	//	All but the top row (reserved for column labels) and
	//	bottom row (reserved for status and commands) are included in the viewport
	v->h = w.ws_row - 2;

	//	First four columns are reserved for row labels
	v->w = w.ws_col - 4;
}