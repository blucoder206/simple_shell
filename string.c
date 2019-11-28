#include "holberton.h"
/**
* _strcat - concatenate two strings
* @source: source
* @destination: destination
* Return: dest
**/
char *_strcat(char *destination, const char *source)
{
	char *ptr = destination + strlen(destination);

	while (*source != '\0')
	*ptr++ = *source++;
	*ptr = '\0';

	return (destination);
}
/**
* _strcpy - copy the string src to string dest
* @src: string source
* @dest: string dest
* Return: the string dest
**/
char *_strcpy(char *dest, char *src)
{
	int x;

	for (x = 0; src[x] != '\0'; x++)
	{
		dest[x] = src[x];
	}
	dest[x] = '\0';
	return (dest);
}
/**
 * _strlen - get length of a string
 * @s: pointer type char
 *
 * Return: The program will return the number of characters of *s (the length)
 **/
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != 00)
	{
		i++;
	}
	return (i);
}
/**
 * _strcmp - compare two strings
 * @s1: string one to compare
 * @s2: string two to compare
 *
 * Return: string
 */
int _strcmp(char *s1, char *s2)
{
	int i, difference;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if ((s1[i] - s2[i]) != 0)
		{
			difference = (s1[i] - s2[i]);
			break;
		}
		else
		{
			difference = 0;
		}
	}
	return (difference);
}
