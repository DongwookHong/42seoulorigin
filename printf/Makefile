NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS  = ft_printf.c \
	ft_utils.c \
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