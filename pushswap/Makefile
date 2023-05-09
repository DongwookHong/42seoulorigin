NAME = push_swap
BONUS_NAME = checker

CC = CC
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

HEADER	=	mandatory/push_swap.h
BONUS_HEADER = bonus/checker.h

SRCS = mandatory/push_swap.c \
	mandatory/utils/base.c \
	mandatory/utils/baseset.c \
	mandatory/utils/clean.c \
	mandatory/utils/utils.c \
	mandatory/utils/list.c \
	mandatory/utils/error.c \
	mandatory/utils/parsing.c \
	mandatory/utils/split.c \
	mandatory/sort/minsort.c \
	mandatory/sort/sort.c \
	mandatory/sort/sortatob.c \
	mandatory/sort/sortbtoa.c \
	mandatory/command/push.c \
	mandatory/command/reverse.c \
	mandatory/command/rotate.c \
	mandatory/command/swap.c \

BONUS_SRCS = 	bonus/checker.c \
	bonus/get_next_line_utils.c \
	bonus/get_next_line.c \
	mandatory/utils/clean.c \
	mandatory/utils/utils.c \
	mandatory/utils/list.c \
	mandatory/utils/split.c \
	mandatory/utils/error.c \
	mandatory/utils/parsing.c \
	mandatory/utils/base.c \
	mandatory/utils/baseset.c \
	mandatory/command/reverse.c \
	mandatory/command/rotate.c \
	mandatory/command/swap.c \
	mandatory/command/push.c \
	mandatory/sort/minsort.c \
	mandatory/sort/sort.c \
	mandatory/sort/sortatob.c \
	mandatory/sort/sortbtoa.c \

OBJS = $(SRCS:%.c=%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus:	$(BONUS_NAME)
$(BONUS_NAME):	$(BONUS_OBJS) $(BONUS_HEADER)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)

fclean: 
	make clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)

re: 
	make fclean 
	make all
	
.PHONY: all clean fclean re bonus
