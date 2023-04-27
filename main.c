#include "main.h"

/**
 * tokenizer - tokenize input commmand for the shell program
 * @line: ouput of get line and input to tokenization
 * @argc: number of arguments passed to the program
 * @argv: pointer to array of arguments passed to the program
 *
 * Return: noting
 */

void tokenizer(char *line, char ***argv, int *argc)
{
	char *line_cpy = NULL;
	char *token = NULL;
	char *delim = " \n";
	size_t token_len = 0;
	int i = 0;

	line_cpy = _strdup(line);
	token = strtok(line, delim);
	while (token)
	{
		token_len++;
		token = strtok(NULL, delim);
	}
	*argv = malloc(sizeof(char *) * (token_len + 1));
	if (!*argv || !line_cpy)
	{
		free(argv);
		perror("Error malloc line_cp or argv");
		exit(EXIT_FAILURE);
	}
	token_len = 0;
	token = strtok(line_cpy, delim);
	while (token != NULL)
	{
		(*argv)[i] = _strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	(*argv)[i] = NULL;
	*argc = i;
	free(line_cpy);
}

/**
 * main - entry point for the shell program
 * @argc: number of arguments passed to the program
 * @argv: pointer to array of arguments passed to the program
 * @env: pointer to array of environment variables
 * Return: 0 on success, -1 on failure
 */

int main(int argc, char **argv, char **env)
{
	char *myprompt = ":) ";
	char *line = NULL;
	size_t len = 0;
	char *out = "exit";

	while (1)
	{
		/*int argc = 0;*/
		write(STDOUT_FILENO, myprompt, _strlen(myprompt));
		if (getline(&line, &len, stdin) == -1)
			return (-1);
		tokenizer(line, &argv, &argc);
		if (argc == 0)
		{
			free(argv);
			continue;
		}
		if (_strcmp(out, argv[0]) == 0)
		{
			free(argv);
			free(line);
			return (0);
		}
		execu(argv, env);
		free(argv);
	}
	free(line);
	return (0);
}
