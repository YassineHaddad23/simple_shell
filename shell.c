#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

extern char **environ;

void prompt(void);
void handle_input(char *input);

int main(void)
{
    char input[MAX_INPUT_LENGTH];
    
    while (1)
    {
        prompt();

        if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
        {
            break; /* EOF (Ctrl+D) */
        }

        /* Remove trailing newline character */
        input[strcspn(input, "\n")] = '\0';

        handle_input(input);
    }

    return 0;
}

void prompt(void)
{
    printf("#cisfun$ ");
    fflush(stdout);
}

void handle_input(char *input)
{
    pid_t pid;
    int status;
    char *argv[2];

    argv[0] = input;
    argv[1] = NULL;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        /* Child process */
        if (execve(input, argv, environ) == -1)
        {
            perror("./shell");
        }
        exit(EXIT_FAILURE);
    }
    else
    {
        /* Parent process */
        wait(&status);
    }
}

