#include "main.h"

/**
 * main - entry point for the shell program
 * @argc: number of arguments passed to the program
 * @argv: pointer to array of arguments passed to the program
 * @env: pointer to array of environment variables
 * Return: 0 on success, -1 on failure
 */

int main(int argc, char **argv, char **env)
{
	char *myprompt = "$ ", *line = NULL, *line_cpy = NULL;
	char *token = NULL, *delim = " \n", *out = "exit";
	size_t len = 0, token_len = 0, i = 0;

	while (1)
	{
		argc = 0;
		write(STDOUT_FILENO, myprompt, strlen(myprompt));
		if (getline(&line, &len, stdin) == -1)
			return (-1);
		line_cpy = _strdup(line);
		token = strtok(line, delim);
		while (token)
		{
			token = strtok(NULL, delim);
			token_len++;
		}
		argv = malloc(sizeof(char) * (token_len + 1));
		if (!argv | !line_cpy)
		{
			perror("Error malloc lince_cp or argv");
			return (-1);
		}
		token_len = 0;
		token = strtok(line_cpy, delim);
		while (token != NULL)
		{
			argv[i] = _strdup(token);
			token = strtok(NULL, delim);
			i++;
			token_len++;
		}
		argv[i] = NULL;
		argc = i;
		if (argc == 0)
			continue;
		if (_strcmp(out, argv[0]) == 0)
		{
			free(argv);
			free(line);
			free(line_cpy);
			return (0);
		}
		execu(argv, env);
		free(argv);
		i = 0;
	}
	free(line);
	free(line_cpy);
	return (0);
}
