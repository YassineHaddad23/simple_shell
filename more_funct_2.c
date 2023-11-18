#include "shell.h"

/**
 * _erratoi - converts a string to an integer safely
 * @s: the string to be converted
 *
 * Return: Converted number if successful, -1 on error
 */
int _erratoi(char *s)
{
    int i = 0;
    unsigned long int result = 0;

    if (*s == '+')
        s++;  /* Skip leading '+' */

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            result *= 10;
            result += (s[i] - '0');
            if (result > INT_MAX)
                return (-1);
        }
        else
            return (-1);
    }
    return (result);
}

/**
 * print_error - prints a custom error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 */
void print_error(info_t *info, char *estr)
{
    _eputs(info->fname);
    _eputs(": ");
    print_d(info->line_count, STDERR_FILENO);
    _eputs(": ");
    _eputs(info->argv[0]);
    _eputs(": ");
    _eputs(estr);
}

/**
 * print_integer - prints an integer to a file descriptor
 * @input: the input integer
 * @fd: the file descriptor to write to
 *
 * Return: number of characters printed
 */
int print_integer(int input, int fd)
{
    int (*__putchar)(char) = _putchar;
    int i, count = 0;
    unsigned int _abs_, current;

    if (fd == STDERR_FILENO)
        __putchar = _eputchar;

    // ... (rest of the function remains unchanged)
}

/**
 * convert_number - converts a number to a string
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string representation of the number
 */
char *convert_number(long int num, int base, int flags)
{
    // ... (no changes to the function itself)
}

/**
 * remove_comments - replaces the first instance of '#' with '\0'
 * @buf: address of the string to modify
 */
void remove_comments(char *buf)
{
    int i;

    for (i = 0; buf[i] != '\0'; i++)
        if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
        {
            buf[i] = '\0';
            break;
        }
}
