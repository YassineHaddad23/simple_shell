#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * Return: a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        s[i] = b;

    return s;
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
    char **a = pp;

    if (!pp)
        return;

    // Free each string in the array
    while (*pp)
        free(*pp++);

    // Free the array itself
    free(a);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of the previous block
 * @new_size: byte size of the new block
 * Return: pointer to the old block or a new block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *p;

    // Allocate new memory block
    p = malloc(new_size);
    if (!p)
        return NULL;

    // Copy contents from old block to new block
    old_size = old_size < new_size ? old_size : new_size;
    while (old_size--)
        p[old_size] = ((char *)ptr)[old_size];

    // Free the old block
    free(ptr);

    return p;
}
