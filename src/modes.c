#include "modes.h"

void normalMode(win *w, viewport *v)
{
	bool normal = true;
	raise(SIGWINCH);
	while(normal)
	{
		while(kbhit())
		{
			switch(getchar())
			{
				case 'q':
					normal = false;
					break;
				case 'w':
					if(v->y > 0)
					{
						v->y--;
						isWinch = true;
					}
					break;
				case 'a':
					if(v->x > 0)
					{
						v->x--;
						isWinch = true;
					}
					break;
				case 's':
					v->y++;
					isWinch = true;
					break;
				case 'd':
					v->x++;
					isWinch = true;
					break;
				default:
					break;
			}
		}
		if(isWinch)
		{
			isWinch = false;
			getWinsize(w);
			resizeViewport(*w, v);
			if(winsizeRequirementsMet(*w))
				printViewport(*w, *v);
			else
				printError(*w);
		}
	}
}