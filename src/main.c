#include "main.h"
#include "modes.h"
#include "csvi_signal.h"

int main()
{
	if (!isatty(STDOUT_FILENO))
	{
		fprintf(stderr, "Output is not to a terminal. Terminating.\n");
		return -1;
	}
	if (!isatty(STDIN_FILENO))
	{
		fprintf(stderr, "Input is not from a terminal. Terminating.\n");
		return -1;
	}

	sigHandlerInit();

	win w;
	getWinsize(&w);

	setTerm(TERM_UNBUFFERED | TERM_ECHO_OFF | TERM_ALT_BUFFER);

	normalMode(w);

	setTerm(TERM_BUFFERED | TERM_ECHO_ON | TERM_OG_BUFFER);
}