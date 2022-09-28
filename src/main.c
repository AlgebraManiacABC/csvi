#include "main.h"
#include "modes.h"
#include "csvi_signal.h"
#include "print.h"

int main()
{
	if (!isatty(STDOUT_FILENO))
	{
		fprintf(stderr, "Output is not to a terminal. Terminating.\n");
		return EXIT_FAILURE;
	}
	if (!isatty(STDIN_FILENO))
	{
		fprintf(stderr, "Input is not from a terminal. Terminating.\n");
		return EXIT_FAILURE;
	}

	win w;
	getWinsize(&w);
	if(w.ws_col < MIN_COLUMNS || w.ws_row < MIN_ROWS)
	{
		fprintf(stderr, "Terminal is not large enough to run csvi!\nMust have at least 3 rows and 11 columns.\n");
		return EXIT_FAILURE;
	}

	//	Initializes signal-handling functions
	sigHandlerInit();

	setTerm(TERM_UNBUFFERED | TERM_ECHO_OFF | TERM_ALT_BUFFER | TERM_CURSOR_OFF);

	normalMode(&w);

	setTerm(TERM_BUFFERED | TERM_ECHO_ON | TERM_OG_BUFFER | TERM_CURSOR_ON);

	return EXIT_SUCCESS;
}