#include "minishell.h"

void    cmd_bin(char **command, char **envp)
{
    int status;

    status = 0;
    if (execve(command[0], command, envp) == -1)
        status = errno;
    if (status == 2)
    {
        if (command[0][0] == '/' || command[0][ft_strlen(command[0]) - 1] == '/')
            print_err(command[0], "no such file or directory");
        else
            print_err(command[0], "command not found");
    }
    strerror(status);
}
