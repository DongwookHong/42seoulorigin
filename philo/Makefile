NAME = philo

INCS_DIR = includes
SRCS_DIR = src

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
MAKE = make

SRCS = $(SRCS_DIR)/philo.c \
	$(SRCS_DIR)/time.c \
	$(SRCS_DIR)/utils.c \
	$(SRCS_DIR)/check.c \
	$(SRCS_DIR)/execution.c \
	$(SRCS_DIR)/init.c \
	$(SRCS_DIR)/act_philo.c \
	

OBJS = $(SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(INCS_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -I $(INCS_DIR)

clean:
	$(RM) $(OBJS)

fclean:
	$(MAKE) clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re