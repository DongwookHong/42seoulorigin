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
	$(MAKE) -C $(LIBFT_DIR)
	cp libft/libft.a $(NAME)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I .

clean:
	$(RM) $(OBJS)
	make -C libft clean
fclean: 
	make clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: 
	make fclean 
	make all
	
.PHONY: all clean fclean re