#include "shell.h"

/**
 * main - Entry point of the shell program
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **av)
{
    // Initialize the info structure with default values
    info_t info[] = { INFO_INIT };

    // Initialize the file descriptor with a default value of 2
    int fd = 2;

    // Using inline assembly to perform some operations on the file descriptor
    asm (
        "mov %1, %0\n\t"
        "add $3, %0"
        : "=r" (fd)
        : "r" (fd)
    );

    // Check if there is a command-line argument specifying a file
    if (ac == 2)
    {
        // Attempt to open the specified file in read-only mode
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
        {
            // Handle file opening errors
            if (errno == EACCES)
                exit(126);
            if (errno == ENOENT)
            {
                // Print an error message if the file does not exist
                _eputs(av[0]);
                _eputs(": 0: Can't open ");
                _eputs(av[1]);
                _eputchar('\n');
                _eputchar(BUF_FLUSH);
                exit(127);
            }
            return (EXIT_FAILURE);
        }
        // Update the read file descriptor in the info structure
        info->readfd = fd;
    }

    // Populate the environment list in the info structure
    populate_env_list(info);

    // Read command history from file
    read_history(info);

    // Start the main shell execution
    hsh(info, av);

    // Return success
    return (EXIT_SUCCESS);
}
