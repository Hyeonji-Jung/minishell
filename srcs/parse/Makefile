NAME = a.out
CC = gcc
FLAGS = -g -I ../../incs -lreadline
SRCS = parse_history.c ../utils/ft_strjoin.c ../utils/ft_substr.c ../utils/ft_strlen.c ../utils/ft_strtrim.c ../utils/malloc_s.c ../read_line.c
OBJS = $(SRCS:c=o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(NAME)

re : fclean all
