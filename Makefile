CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = file.c  files.c  ins.c   mfiles.c  mmfiles.c  nums.c  push_swap.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ 
clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
