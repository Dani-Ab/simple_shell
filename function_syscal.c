#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @original: pointer to the string to duplicate.
 * Return: pointer to the duplicated string, or NULL if insufficient memory
**/

char *_strdup(const char *original)
{
	size_t len;
	char *copy, *copy_int;

	if (original == NULL)
		return (NULL);
	len = _strlen(original);
	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	copy_int = copy;
	while (*original != '\0')
	{
		*copy = *original;
		copy++;
		original++;
	}
	*copy = '\0';
	return (copy_int);
}

/**
 * _strcpy - copies the string pointed to by src, including the terminating
 * @copy: pointer to the destination buffer
 * @original: pointer to the string
 * Return: pointer to the destination string.
**/

char *_strcpy(char *copy, const char *original)
{
	char *copy_int;

	copy_int = copy;
	while (*original != '\0')
	{
		*copy = *original;
		original++;
		copy++;
	}
	*copy = '\0';
	return (copy_int);
}

/**
 * _strcat - appends the src string to the dest string, overwriting null byte
 * @base: pointer to the destination string.
 * @add: pointer to the source string.
 * Return: pointer to the resulting string dest.
**/

char *_strcat(char *base, const char *add)
{
	char *base_copy;

	if (base == NULL || add == NULL)
		return (NULL);
	base_copy = base;
	while (*base_copy != '\0')
	{
		base_copy++;
	}
	while (*add != '\0')
	{
		*base_copy++ = *add++;
	}
	*base_copy = '\0';
	return (base);
}

/**
 * _strlen - calculates the length of the string str, excluding the null byte.
 * @str: pointer to the string to be measured.
 * Return: the length of the string.
**/

size_t _strlen(const char *str)
{
	const char *p = str;

	while (*p != '\0')
	{
		p++;
	}
	return (p - str);
}

/**
 * _strcmp - compares the two strings s1 and s2.
 * @s1: pointer to the first string to compare.
 * @s2: pointer to the second string to compare.
 * Return: an integer less than, equal to, or greater than zero if s1 is found,
**/


int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}
