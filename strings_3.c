#include "myshellk.h"

/**
 * _strdup - Duplicates a string.
 * @str: Input string to be duplicated.
 *
 * Return: A dynamically allocated copy of the input string.
 *
 * This function takes an input string and dynamically allocates memory to
 * create an identical copy. The length of the string is determined, and the
 * memory is allocated to store the copy, including the null terminator. The
 * caller is responsible for freeing the allocated memory.
 */
char *_strdup(const char *str)
{
	char *ptr;
	int i, len;

	if (str == NULL)
		return (NULL);

	for (len = 0; *str != '\0'; len++)
		str++;

	str = str - len;
	ptr = malloc(sizeof(char) * (len + 1));

	if (ptr == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		ptr[i] = str[i];

	return (ptr);
}

/**
 * _strcmp - Compares two strings.
 * @s1: First string.
 * @s2: Second string.
 *
 * Return: An integer representing the difference between the ASCII values
 * of the first non-matching characters in the strings.
 *
 * This function compares two strings character by character. It returns an
 * integer representing the difference between the ASCII values of the first
 */
int _strcmp(char *s1, char *s2)
{
	int ptr;

	ptr = (int)*s1 - (int)*s2;

	for (; *s1;)
	{
		if (*s1 != *s2)
			break;

		s1++;
		s2++;
		ptr = (int)*s1 - (int)*s2;
	}

	return (ptr);
}

/**
 * _strlen - Returns the length of a string.
 * @s: Input string.
 *
 * Return: The length of the string.
 *
 * This function calculates and returns the length of the input string by
 * iterating through each character until the null terminator is encountered.
 */
int _strlen(const char *s)
{
	int i;

	if (!s)
		return (0);

	for (i = 0; *s != '\0'; s++)
		i++;

	return (i);
}

/**
 * _strcat - Concatenates two strings.
 * @dest: First string.
 * @src: Second string.
 *
 * Return: A pointer to the concatenated string.
 *
 * This function appends the characters of the second string to the end of
 * the first string. The resulting concatenated string is stored in the
 * destination buffer, and the pointer to the destination buffer is returned.
 */
char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;

	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}

	*p = '\0';
	return (dest);
}

/**
 * _strcpy - Copies a string.
 * @dest: Destination string.
 * @src: Source string.
 *
 * Return: A pointer to the copied string.
 *
 * This function copies characters from the source string to the destination
 * string until the null terminator is encountered. The resulting copied
 * string is stored in the destination buffer, and the pointer to the
 * destination buffer is returned.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}
