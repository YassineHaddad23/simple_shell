#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of the string
 */
int _strlen(const char *s)
{
    if (!s)
        return (0);

    int length = 0;
    while (*s++)
        length++;

    return length;
}

/**
 * _strcmp - performs lexicographic comparison of two strings.
 * @s1: the first string
 * @s2: the second string
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2) {
        if (*s1 != *s2)
            return (*s1 - *s2);

        s1++;
        s2++;
    }

    return (*s1 - *s2);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of the next char of haystack or NULL
 */
const char *starts_with(const char *haystack, const char *needle)
{
    while (*needle) {
        if (*needle != *haystack)
            return NULL;

        needle++;
        haystack++;
    }

    return haystack;
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, const char *src)
{
    char *ret = dest;

    while (*dest)
        dest++;

    while ((*dest++ = *src++))
        ;

    return ret;
}
