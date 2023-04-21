NAME = push_swap

CC = CC
COM = ./command
SORT = ./sort
UTIL= ./utils
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = push_swap.c \
	$(UTIL)/base.c \
	$(UTIL)/baseset.c \
	$(UTIL)/clean.c \
	$(UTIL)/utils.c \
	$(UTIL)/list.c \
	$(UTIL)/error.c \
	$(UTIL)/parsing.c \
	$(UTIL)/split.c \
	$(SORT)/minsort.c \
	$(SORT)/sort.c \
	$(SORT)/sortatob.c \
	$(SORT)/sortbtoa.c \
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
