#include "../inc/minishell.h"

int pipe_cnt(char *s)
{
    int i;
    int quote;
    int dquote;
    int cnt;

    i = -1;
    quote = 0;
    dquote = 0;
    cnt = 0;
    while (s[++i])
    {
        if (s[i] == '\'')
            quote = !quote;
        else if (s[i] == '\"')
            dquote = !dquote;
        else if (s[i] == '|' && !quote && !dquote)
            cnt++;
    }
    return (cnt);
}

int chk_pipe(char *s)
{
    int i;
    int quote;
    int dquote;

    i = -1;
    quote = 0;
    dquote = 0;
    while (s[++i])
    {
        if (s[i] == '\'')
            quote = !quote;
        else if (s[i] == '\"')
            dquote = !dquote;
        else if (s[i] == '|' && !quote && !dquote)
            break;
    } 
    return (-1);
}

char    **pipe_split(char *s)
{
    char    n;
    char    **ret;
    int     i;
    int     loc;
    int     tmp;

    i = -1;
    n = pipe_cnt(s) + 1;
    ret = malloc_s(sizeof(char *) * n);
    tmp = 0;
    while (++i < n)
    {
        loc = chk_pipe(&s[tmp]);
        ret[i] = ft_substr(s, tmp, loc);
        tmp = tmp + loc + 1;
    }
    return (ret);
}
