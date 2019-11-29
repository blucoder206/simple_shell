#include "holberton.h"
/**
* _getenv - get environ path data
* @pathaddress: variable to get
*
* Return: value of variable PATH
*/
char *_getenv(char *pathaddress)
{
	char *cpy_nm = NULL;
	int i, len_value;

	cpy_nm = malloc((_strlen(pathaddress) + 2) * (sizeof(char)));
	_strcpy(cpy_nm, pathaddress);
	_strcat(cpy_nm, "=");
	len_value = _strlen(cpy_nm);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(cpy_nm, environ[i], len_value) == 0)
		{
			free(cpy_nm);
			return (environ[i] + len_value);
		}
	}
	return (NULL);
}

/**
* input_split - split the string into an array
* @argv: user's input splitted
* @string: string without split
* @delimitator: character that will act as delimitator
*
* Return: argv
**/

char **input_split(char **argv, char *string, char *delimitator)
{
	char *token;
	int i = 0;

	token = strtok(string, delimitator);
	while (token)
	{
		argv[i++] = token;
		token = strtok(NULL, delimitator);
	}
	argv[i] = 0;
	return (argv);
}

/**
* processing - split input, get env and more
* @readed_bytes: readed bytes
* @argv: user input processed
* @string: user input raw
*
* Return: nothing
**/

void processing(ssize_t readed_bytes, char **argv, char *string)
{
	if (readed_bytes == -1)
	{
		if (string != NULL)
		{
			free(string);
		}
		if (argv != NULL)
		{
			free(argv);
		}

		printf("\n");
		exit(1);
	}
	else
	{
		input_split(argv, string, " \n");
		if ((argv[0]) == NULL)
		{
		}
		else if (strcmp(argv[0], "env") == 0)
		{
			int env_i = 0;
			while (environ[env_i] != NULL)
			{
				printf("%s\n", environ[env_i]);
				env_i++;
			}
		}
		else if (strcmp(argv[0], "exit") == 0)
		{
			if (argv != NULL)
			{
				free(string);
				free(argv);
			}
			exit(0);
		}
	}
}


/**
* print_my_command - run the command execve
* @argv: user input
* @is_heap: indicate if pathnam is the heap
* @paths: paths taken from environ
*
* Return: nothing
**/

void print_my_command(char *pathname, char *argv[], int is_heap)
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve(pathname, argv, NULL) == -1)
		{
			printf("Error\n");
			if (is_heap == 1)
			{
				free(pathname);
			}
		}
	}
	else
	{
		wait(&status);
		if (is_heap == 1)
		{
			free(pathname);
		}
	}
}

/**
* brain - fork, execve process
* @argv: user input
* @st: file check
* @paths: paths taken from environ
*
* Return: nothing
**/
void brain(char **argv, struct stat st, char **paths)
{
	int i, found = 0;
	char *executable = NULL;

	if (stat(argv[0], &st) == 0)
	{
		print_my_command(argv[0], argv, 0);
	}
	else
	{
		for (i = 0; paths[i] != NULL; i++)
		{
			executable = malloc((_strlen(paths[i]) + _strlen(argv[0]) + 2) * sizeof(char));
			_strcat(executable, paths[i]);
			_strcat(executable, "/");
			_strcat(executable, argv[0]);

			if (stat(executable, &st) == 0)
			{
				print_my_command(executable, argv, 1);
				found = 1;
				break;
			}
			else
			{
				if (executable != NULL)
				{
					free(executable);
					executable = NULL;
				}
			}
		}
		if (!found)
		{
			printf("%s: not found\n", argv[0]);
		}
	}
}
