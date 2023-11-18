#include "shell.h"

/**
 * bfree - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 *
 * This function frees the memory block pointed to by the given pointer and
 * then sets the pointer to NULL to avoid a dangling pointer.
 *
 * Return: 1 if freed successfully, otherwise 0.
 */
int bfree(void **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
        return 1;
    }
    return 0;
}
