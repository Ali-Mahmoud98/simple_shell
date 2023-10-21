#include "shell.h"

/**
 * wait_print - wait for the status to change and prints the message
 * @status: the status;
 * @prompt: The prompt to be displayed
 */
void wait_print(int *status, char *prompt)
{
	wait(status);
	printf("%s ", prompt);
}
