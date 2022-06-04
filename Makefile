NAME =	minishell
CC =	gcc
FLAGS = -Wall -Wextra -Werror -I incs/
MAIN =	main make_env make_leaf make_node signal execute error make_fd redirect read_line
PARSE =	parse_cmd parse_pipe parse_redirect parse_redirects parse_simplecmd parse_env
UTILS =	env_func ft_isalpha ft_split ft_strjoin ft_strlen ft_strncmp ft_strtrim malloc_s multi_space utils free_all ft_substr ft_itoa
CMDS =	exit env export unset pwd echo cd

SRCS =  $(addsuffix .c, $(addprefix srcs/, $(MAIN))) \
		$(addsuffix .c, $(addprefix srcs/parse/, $(PARSE))) \
	  	$(addsuffix .c, $(addprefix srcs/utils/, $(UTILS))) \
	  	$(addsuffix .c, $(addprefix srcs/command/, $(CMDS)))
OBJS = 	$(SRCS:c=o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) -lreadline $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(NAME)

re : fclean all

.PHONY: all clean fclean re
