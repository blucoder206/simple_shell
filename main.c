#include "holberton.h"

/**
* main - super simple shell
*
* Return: nothing
**/

int main(void)
{
	char *paths[20];
	char *path;

	signal(SIGINT, ctrlc_handle);
	path = _getenv("PATH");
	input_split(paths, path, ":");

	for (;;)
	{
		ssize_t readed_bytes;
		struct stat st;
		size_t numberbytes = 0;
		char *string = NULL;
		char **argv;

		printf("$ ");
		readed_bytes = getline(&string, &numberbytes, stdin);
		argv = malloc(readed_bytes * sizeof(*argv));

		processing(readed_bytes, argv, string);
		brain(argv, st, paths);

		free(string);
		free(argv);
	}
	return (0);
}
