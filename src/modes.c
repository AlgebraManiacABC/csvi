#include "modes.h"

void normalMode(win *w)
{
	bool normal = true;
	while(normal)
	{
		while(kbhit())
		{
			if(getchar()=='q')
				normal = false;
		}
		if(isWinch(WC_QUERY))
		{
			getWinsize(w);
			printf("Window size changed to [%d,%d]\n",w->ws_row,w->ws_col);
		}
	}
}