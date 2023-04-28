#include "shell.h"

/**
 * interactive - returns true if the shell mode is interactive
 * @inf: the address of the struct
 *
 * Return: 1 is for interactive mode, for other modes
 */
int interactive(info_t *inf)
{
	return (isatty(STDIN_FILENO) && inf->readfd <= 2);
}

/**
 * is_delim - checks for  delimeter in string of characters
 * @c: the character to check
 * @delim: delimeter string
 * Return: 1 for success, 0 for failure
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @c: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - string to integer conversion
 * @s: string sample for conversion
 * Return: 0 if string is void of number
 */

int _atoi(char *s)
{
	int i, sig = 1, flg = 0, out;
	unsigned int rslt = 0;

	for (i = 0; s[i] != '\0' && flg != 2; i++)
	{
		if (s[i] == '-')
			sig *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flg = 1;
			rslt *= 10;
			rslt += (s[i] - '0');
		}
		else if (flg == 1)
			flg = 2;
	}

	if (sig == -1)
		out = -rslt;
	else
		out = rslt;

	return (out);
}

