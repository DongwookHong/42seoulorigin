NAME = push_swap

CC = CC
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = push_swap.c \
	command.c \
	sort.c \
	utils.c \

OBJS = $(SRCS:%.c=%.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

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
