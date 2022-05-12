#include "inc/minishell.h"

void    make_redirects(t_node *n)
{
    n->left = malloc(sizeof(t_node));
    n->right = malloc(sizeof(t_node));
}

void    make_redirect(t_node *n)
{
    n->left = malloc(sizeof(t_node));
    n->right = malloc(sizeof(t_node));
    n->left->type = TYPE;
    n->right->type = FILENAME;
    n->left->left = NULL;
    n->left->right = NULL;
    n->right->left = NULL;
    n->right->right = NULL;
}

void    make_cmd(t_node *n)
{
    n->left = malloc(sizeof(t_node));
    n->right = malloc(sizeof(t_node));
    n->left->type = REDIRECTS;
    n->right->type = SIMPLECMD;
    make_simplecmd(n->right);
}
전화받고올게요
void    make_simplecmd(t_node *n)
{
    n->left = malloc(sizeof(t_node));
    n->right = malloc(sizeof(t_node));
    n->left->type = FILEPATH;
    n->right->type = ARGV;
    n->left->left = NULL;
    n->left->right = NULL;
    n->right->left = NULL;
    n->right->right = NULL;
}