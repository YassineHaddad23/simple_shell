#include "shell.h"

/**
 * list_len - determines the length of a linked list
 * @h: pointer to the first node
 *
 * Return: size of the list
 */
size_t list_len(const list_t *h)
{
    size_t i = 0;

    while (h)
    {
        h = h->next;
        i++;
    }
    return i;
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: pointer to the first node
 *
 * Return: array of strings or NULL on failure
 */
char **list_to_strings(list_t *head)
{
    list_t *node = head;
    size_t i = list_len(head);
    char **strs;

    if (!head || !i)
        return NULL;

    strs = malloc(sizeof(char *) * (i + 1));
    if (!strs)
        return NULL;

    for (i = 0; node; node = node->next, i++)
    {
        strs[i] = _strdup(node->str);
        if (!strs[i])
        {
            for (size_t j = 0; j < i; j++)
                free(strs[j]);
            free(strs);
            return NULL;
        }
    }

    strs[i] = NULL;
    return strs;
}
