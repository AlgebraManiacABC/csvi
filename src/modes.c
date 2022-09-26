#include "modes.h"
#include <stdbool.h>

void normalMode(win w)
{
	bool normal = true;
	while(normal)
	{
		while(!kbhit())
		{
		}
		normal = false;
	}
}