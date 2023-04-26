#include "main.h"
/**
 * _strncmp - compare two stringsfor given size
 * @s1: input string 1
 * @s2: input string 2
 * @n: size to compare
 *
 * Return: pointer to the path of the command, or NULL if not found
*/
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] < s2[i] ? -1 : 1);
		}
		if (s1[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}
