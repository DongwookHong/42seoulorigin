NAME = push_swap

CC = CC
COM = ./command
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = push_swap.c \
	sort.c \
	utils.c \
	error.c \
	minsort.c \
	parsing.c \
	push_swaputils.c \
	split.c \
	$(COM)/push.c \
	$(COM)/reverse.c \
	$(COM)/rotate.c \
	$(COM)/swap.c \


OBJS = $(SRCS:%.c=%.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) -I . $^ -o $@
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I . 

clean:
	$(RM) $(OBJS)
fclean: 
	make clean
	$(RM) $(NAME)
re: 
	make fclean 
	make all
	
.PHONY: all clean fclean re
