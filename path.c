#include "shell.h"

/**
 * is_cmd - Determines if a file is an executable command.
 * @info: The info struct.
 * @path: Path to the file.
 *
 * Return: 1 if true, 0 otherwise.
 */
int is_cmd(info_t *info, char *path)
{
    struct stat st;

    // Unused parameter (info)
    (void)info;

    // Check if the path is valid and obtain file stats
    if (!path || stat(path, &st))
        return (0);

    // Check if the file is a regular file (executable)
    if (st.st_mode & S_IFREG)
    {
        return (1);
    }

    // Not an executable command
    return (0);
}

/**
 * dup_chars - Duplicates characters from the given path string.
 * @pathstr: The PATH string.
 * @start: Starting index.
 * @stop: Stopping index.
 *
 * Return: Pointer to the new buffer.
 */
char *dup_chars(char *pathstr, int start, int stop)
{
    static char buf[1024];
    int i = 0, k = 0;

    // Copy characters to the buffer, excluding ':' characters
    for (k = 0, i = start; i < stop; i++)
        if (pathstr[i] != ':')
            buf[k++] = pathstr[i];
    buf[k] = 0;
    return (buf);
}

/**
 * find_path - Finds the given command in the PATH string.
 * @info: The info struct.
 * @pathstr: The PATH string.
 * @cmd: The command to find.
 *
 * Return: Full path of the command if found, or NULL.
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
    int i = 0, curr_pos = 0;
    char *path;

    // Check for NULL PATH string
    if (!pathstr)
        return (NULL);

    // Check if the command starts with "./" and is a valid executable
    if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
    {
        if (is_cmd(info, cmd))
            return (cmd);
    }

    // Iterate through the PATH string and search for the command
    while (1)
    {
        if (!pathstr[i] || pathstr[i] == ':')
        {
            // Duplicate characters from the current position to the current index
            path = dup_chars(pathstr, curr_pos, i);

            // Append the command to the path
            if (!*path)
                _strcat(path, cmd);
            else
            {
                _strcat(path, "/");
                _strcat(path, cmd);
            }

            // Check if the concatenated path is a valid executable
            if (is_cmd(info, path))
                return (path);

            // If end of PATH string, exit the loop
            if (!pathstr[i])
                break;

            // Update the current position
            curr_pos = i;
        }
        i++;
    }

    // Command not found in the PATH
    return (NULL);
}
