#include "csvi_signal.h"

int sigHandlerInit()
{
	struct sigaction new;
	sigemptyset(&new.sa_mask);
	new.sa_flags = SA_RESTART;
	
	new.sa_handler = sigIntHandler;
	if(sigaction(SIGINT, &new, NULL) == -1)
		return -1;

	new.sa_handler = sigTermHandler;
	if(sigaction(SIGTERM, &new, NULL) == -1)
		return -1;
	
	new.sa_handler = sigWinchHandler;
	if(sigaction(SIGWINCH, &new, NULL) == -1)
		return -1;

	return EXIT_SUCCESS;
}

void sigIntHandler()
{
	printf("Sorry! I cannot accept your Ctrl+C\n");
}

void sigTermHandler()
{
	printf("Oh no! anyways...\n");
}

void sigWinchHandler()
{
	isWinch(WC_SET);
}

bool isWinch(bool set)
{
	static bool winch = false;
	bool query = false;
	if(set == WC_SET)
		winch = true;
	else
	{
		query = winch;
		if(winch) winch = false;
	}
	return query;
}