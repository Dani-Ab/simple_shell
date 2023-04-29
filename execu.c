#include "main.h"

/**
 * execu - Executes a command
 * @argv: Pointer to an array of arguments
 * @env: Pointer to an array of environment variables
 * This function forks a new process and executes the command passed argument
 * If the command is not found, an error message is displayed and the function
 * If an error occurs during execution, an error message is displayed.
 */

void execu(int argc, char **argv, char **env, char *line)
{
	pid_t pid;
	char *cmd_in, *cmd_path;
	int val = 0;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(1);
	}
	if (pid == 0)
	{
		if (argv)
		{
			cmd_in = argv[0];
			cmd_path = get_path(cmd_in, env);
			if (cmd_path == NULL)
			{
				perror("./hsh");
				free_argv(argv, argc);
				free(line);
				exit(1);
			}
			val = execve(cmd_path, argv, env);
			if (val == -1)
			{
				perror("Error");
				free(cmd_path);
				free_argv(argv, 0);
				exit(EXIT_FAILURE);
			}
		}
		exit(0);
	}
}
