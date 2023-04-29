#include "main.h"

/**
 * tokenizer - tokenize input commmand for the shell program
 * @line: ouput of get line and input to tokenization
 * @token_arr: number of arguments passed to the program
 * @token_count: number of tokes
 * Return: noting
 */

void tokenizer(char *line, char ***token_arr, int *token_count)
{
	char *line_cpy = NULL;
	char *token = NULL;
	char *delim = " \n";
	int i = 0;

	line_cpy = _strdup(line);
	if (!line_cpy)
	{
		if (!line_cpy)
		{
			free(line_cpy);
			line = NULL;
		}
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, delim);
	while (token)
	{
		(*token_arr)[i] = _strdup(token);
		if (!(*token_arr)[i])
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delim);
		i++;
	}
	(*token_arr)[i] = NULL;
	*token_count = i;
	free(line_cpy);
}

/**
 * free_argv - to free argv array
 * @argc: number of arguments passed
 * @argv: pointer to array of arguments passed
 *
 * Return: noting
 */
void free_argv(char **argv, int argc)
{
	int i;

	if (argv != NULL)
	{
		for (i = 0; i < argc; i++)
		{
			if ((argv)[i])
				free(argv[i]);
		}
		argv = NULL;
	}
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
	char *myprompt = ":) ", *line = NULL, *out = "exit";
	size_t len = 0;

	while (1)
	{
		write(STDOUT_FILENO, myprompt, _strlen(myprompt));
		if (getline(&line, &len, stdin) == -1)
		{
			if (line)
			{
				free(line);
				line = NULL;
			}
			return (-1);
		}
		tokenizer(line, &argv, &argc);
		if (argc == 0)
		{
			free_argv(argv, argc);
			continue;
		}
		if (_strcmp(out, argv[0]) == 0)
		{
			free_argv(argv, argc);
			free(line);
			return (0);
		}
		execu(argc, argv, env, line);
		free_argv(argv, argc);
		if (line)
		{
			free(line);
			line = NULL;
		}
	}
	free(line);
	return (0);
}
