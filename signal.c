#include "holberton.h"
/**
* ctrlc_handle - Handle with Ctrl-C signal
* @sig: non-used variable
*
* Return: nothing
*/
void ctrlc_handle(int sig)
{
	(void)sig;
	signal(SIGINT, ctrlc_handle);
	fflush(stdout);
}
