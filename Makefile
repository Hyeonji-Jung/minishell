CC = GCC
FLAGS = -Wall -Wextra -Werror -lreadline
NAME = minishell
SRCS = init.c main.c makenode.c make_leaf.c signal.c parse/parse_pipe.c parse/parse_redirect.c parse/parse_redirects.c parse/parse_cmd.c parse/parse_simplecmd.c
UTILS = utils/ft_isalpha.c utils/ft_strlen.c utils/ft_strncmp.c utils/ft_substr.c utils/malloc_s.c utils/utils.c utils/ft_strjoin.c utils/multi_space.c utils/ft_strtrim.c
CMDS = command/exit.c

OBJS = $(SRCS:%.c=%.o) $(UTILS:%.c=%.o) $(CMDS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean :
	rm -rf $(OBJS) $(NAME)

re : fclean all
