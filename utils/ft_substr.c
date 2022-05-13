#include "../inc/minishell.h"

char    *ft_substr(char *s, int start, int len)
{
    char    *ret;
    int     i;
    
    ret = malloc_s(sizeof(char) * (len + 1));
    ret[len] = '\0';
    i = 0;
    while (i < len)
    {
        ret[i] = s[start + i];
        i++;
    }
    return (ret);
}