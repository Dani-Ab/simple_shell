#include "main.h"
/**
 * _getenv - custome getenv function
 * @name: passed string parameter
 * @env: pointer to array of environment variables
 *
 * Return: a pointer to a character sucesses or NULL if fail
 */
char *_getenv(const char *name, char **env)
{
	char **envp = env;
	size_t namelen = _strlen(name);

	while (*envp != NULL)
	{
		if (_strncmp(*envp, name, namelen) == 0 && (*envp)[namelen] == '=')
		{
			return (&((*envp)[namelen + 1]));
		}
		envp++;
	}
	return (NULL);
}
