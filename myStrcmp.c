#include "main.h"
/**
 * myStrcmp - compares 2 strings
 * @s1: first string to be compared with
 * @s2: second string compared on/with first string
 * Return: 0 if equal, positive if s1 < s2, negative if s1 > s2
 */
int myStrcmp(char *s1, char *s2)
{
	int i = 0;

	for (; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
