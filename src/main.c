#include "main.h"
#include "modes.h"
#include "csvi_signal.h"
#include "print.h"
#include "doc.h"

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
	if(getWinsize(&w))
	{
		fprintf(stderr, "Could not get terminal size. Aborting.\n");
		return EXIT_FAILURE;
	}
	if(!winsizeRequirementsMet(w))
	{
		fprintf(stderr, "Terminal is not large enough to run csvi!\nMust have at least %d rows and %d columns.\n",MIN_ROWS,MIN_COLUMNS);
		return EXIT_FAILURE;
	}

	//	Initializes signal-handling functions
	sigHandlerInit();

	setTerm(TERM_UNBUFFERED | TERM_ECHO_OFF | TERM_ALT_BUFFER | TERM_CURSOR_OFF);
	
	viewport v;
	v.x = 0;
	v.y = 0;
	resizeViewport(w, &v);

	normalMode(&w, &v);

	setTerm(TERM_BUFFERED | TERM_ECHO_ON | TERM_OG_BUFFER | TERM_CURSOR_ON);

	return EXIT_SUCCESS;
}