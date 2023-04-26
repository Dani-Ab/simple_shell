#include "main.h"

/**
 * execu - Executes a command
 * @argv: Pointer to an array of arguments
 * @env: Pointer to an array of environment variables
 * This function forks a new process and executes the command passed argument
 * If the command is not found, an error message is displayed and the function
 * If an error occurs during execution, an error message is displayed.
 */

void execu(char **argv, char **env)
{
	pid_t pid;
	char *cmd_in, *cmd_path;
	int val = 0;

	pid = fork();

	if (pid == -1)
		perror("Error");
	if (pid == 0)
	{
		if (argv)
		{
			cmd_in = argv[0];
			cmd_path = get_path(cmd_in, env);
			if (cmd_path == NULL)
			{
				perror("./hsh");
				exit(1);
			}
			val = execve(cmd_path, argv, env);
			if (val == -1)
				perror("Error");
		}
		exit(0);
	}
	else
	{
		wait(NULL);
	}
}
