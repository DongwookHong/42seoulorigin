NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

HEADER	=	mandatory/pipex.h
BONUS_HEADER = bonus/bonus_pipex.h

SRCS = mandatory/pipex.c \
	mandatory/child.c \
	mandatory/close.c \
	mandatory/error.c \
	mandatory/find_path.c \
	mandatory/init.c \
	mandatory/split.c \
	mandatory/utils.c
	

BONUS_SRCS = 	bonus/bonus_pipex.c \
	bonus/bonus_child.c \
	bonus/bonus_close.c \
	bonus/bonus_error.c \
	bonus/bonus_find_path.c \
	bonus/bonus_heredoc.c \
	bonus/bonus_init.c \
	bonus/bonus_pipe.c \
	bonus/bonus_set_path.c \
	bonus/bonus_split.c \
	bonus/bonus_utils.c \
	bonus/gnl/get_next_line.c \
	bonus/gnl/get_next_line_utils.c

M_OBJS = $(SRCS:%.c=%.o)
B_OBJS = $(BONUS_SRCS:%.c=%.o)

ifdef WITH_BONUS
	OBJS = $(B_OBJS)
	HEADER = bonus/bonus_pipex.h
else
	OBJS = $(M_OBJS)
	HEADER = mandatory/pipex.h
endif

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

bonus:
	@$(RM) ./mandatory/*.o	
	@make WITH_BONUS=1 $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(M_OBJS)
	$(RM) $(B_OBJS)

fclean: 
	make clean
	$(RM) $(NAME)

re: 
	make fclean 
	make all
	
.PHONY: all clean fclean re bonus
