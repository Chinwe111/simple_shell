#include "shell.h"

/**
 **_strncpy - for copying a string
 *@desti: represents the location a string is copied from
 *@source: the source of the string
 *@ns: number of chracters in the string
 *Return: the joined string
 */
char *_strncpy(char *desti, char *source, int ns)
{
	int a, b;
	char *s = desti;

	a = 0;
	while (source[a] != '\0' && a < ns - 1)
	{
		desti[a] = source[a];
		a++;
	}
	if (a < ns)
	{
		b = a;
		while (b < ns)
		{
			desti[b] = '\0';
			b++;
		}
	}
	return (s);
}

/**
 **_strncat - adds two strings
 *@desti: first string
 *@source: second string
 *@mb: maximum bytes
 *Return: combined string
 */
char *_strncat(char *desti, char *source, int mb)
{
	int a, b;
	char *s = desti;

	a = 0;
	b = 0;
	while (desti[a] != '\0')
		a++;
	while (source[b] != '\0' && b < mb)
	{
		desti[a] = source[b];
		a++;
		b++;
	}
	if (b < mb)
		desti[a] = '\0';
	return (s);
}

/**
 **_strchr - finds char in the string
 *@str: parsed string
 *@chr: character to search for
 *Return: (str) a pointer to the memory area str
 */
char *_strchr(char *str, char chr)
{
	do {
		if (*str == chr)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}

