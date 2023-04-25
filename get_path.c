#include "main.h"
/**
 * get_path - returns the path of a command
 * @command: pointer to the command
 *
 * Return: pointer to the path of the command, or NULL if not found
 */

char *get_path(char *command)
{
	char  *path, *path_cp, *tokenph, *fileph;
	struct stat buf;

	path = getenv("PATH");
	if (path)
	{
		path_cp = _strdup(path);
		tokenph = strtok(path_cp, ":");
		while (tokenph)
		{
			fileph = malloc(_strlen(command) + _strlen(tokenph) + 2);
			if (!fileph)
			{
				perror("get_path malloc");
				return (NULL);
			}
			_strcpy(fileph, tokenph);
			_strcat(fileph, "/");
			_strcat(fileph, command);
			_strcat(fileph, "\0");
			if (stat(fileph, &buf) == 0)
			{
				free(path_cp);
				return (fileph);
			}
			free(fileph);
			tokenph = strtok(NULL, ":");
		}
		free(path_cp);
		if (stat(command, &buf) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
