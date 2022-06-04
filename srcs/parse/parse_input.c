#include "minishell.h"

static int  chk_quote(char c)
{
    static int  quote;
    static int  dquote;

    if (!c)
    {
        quote = 0;
        dquote = 0;
    }
    if (c == '\'' && !dquote)
    {
        quote = !quote;
        return (0);
    }
    else if (c == '\"' && !quote)
    {
        dquote = !dquote;
        return (0);
    }
    if (quote)
        return (1);
    else if (dquote)
        return (2);
    else
        return (0);
}

static void    delete_quote(char **ret, char *s, int i, int chk)
{
    char    *add;
    char    *tmp;

    if (chk == 0 && (s[i] == '\'' || s[i] == '\"'))
        return ;
    add = ft_substr(s, i, 1);
    tmp = ft_strjoin(*ret, add);
    if (*ret)
        free(*ret);
    *ret = tmp;
    free(add);
}

static void    after_slash(char **ret, char *s, int i)
{
    char    *add;
    char    *tmp;

    if (s[i + 1] == '\n')
        return ;
    add = ft_substr(s, i + 1, 1);
    tmp = ft_strjoin(*ret, add);
    if (*ret)
        free(*ret);
    *ret = tmp;
    free(add);
}

int parse_dollar(char **ret, char *s, t_env *env, int i)
{
    int     chk;
    char    *add;
    char    *tmp;

    chk = chk_quote(s[i]);
    if (chk == 1 || s[i + 1] == ' ' || s[i + 1] == '\0')
    {
        delete_quote(ret, s, i, 1);
        return (0);
    }
    if (!ft_strncmp("$$", &s[i], 2))
    {
      //  add_pid(ret);
        return (1);
    }
    // else
    //     parse_env(ret, s, env, i);
}

char    *parse_input(char *s)
{
    char    *ret;
    int     i;
    int     chk;

    i = -1;
    ret = NULL;
    chk_quote(0);
    while (s[++i])
    {
        if (s[i] == '\\')
        {
            after_slash(&ret, s, i++);
            continue ;
        }
        chk = chk_quote(s[i]);
        delete_quote(&ret, s, i, chk);
    }
    return (ret);
}