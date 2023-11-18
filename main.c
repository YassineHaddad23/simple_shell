#include "shell.h"

/**
 * main - Entry point
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
    info_t info[] = { INFO_INIT }; // Initialize info_t structure

    int fd = 2;

    asm ("mov %1, %0\n\t"
         "add $3, %0"
         : "=r" (fd)
         : "r" (fd));

    if (ac == 2)
    {
        // Open file for reading if an argument is provided
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
        {
            if (errno == EACCES)
                exit(126);
            if (errno == ENOENT)
            {
                _eputs(av[0]);
                _eputs(": 0: Can't open ");
                _eputs(av[1]);
                _eputchar('\n');
                _eputchar(BUF_FLUSH);
                exit(127);
            }
            return (EXIT_FAILURE);
        }

        info->readfd = fd; // Set the read file descriptor in the info structure
    }

    populate_env_list(info); // Populate environment list
    read_history(info);      // Read command history from file
    hsh(info, av);           // Run the shell

    return (EXIT_SUCCESS);
}
