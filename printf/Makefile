NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

LIBFT_DIR = ./libft/

SRCS  = ft_printf.c \
	ft_check.c \
	ft_changehex.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putdeci.c \
	ft_putunsigned.c \
	ft_hexlow.c \
	ft_hexupper.c \
	ft_pointer.c \

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	make all -C $(LIBFT_DIR)
	cp libft/libft.a $(NAME)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -I .

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re