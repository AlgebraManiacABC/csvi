#include "modes.h"

void normalMode(win *w)
{
	bool normal = true;
	raise(SIGWINCH);
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
			if(winsizeRequirementsMet(*w))
				printCellBorders(*w);
			else
				printError(*w);
		}
	}
}