NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = ./mandatory
SRC_G = ./gnl
HEADER	=	mandatory/so_long.h

MLX = -L./mlx -lmlx -framework OpenGL -framework Appkit

SRCS = $(SRC)/so_long.c \
	$(SRC)/end.c \
	$(SRC)/find.c \
	$(SRC)/img.c \
	$(SRC)/init.c \
	$(SRC)/keyhook.c \
	$(SRC)/list_utils.c \
	$(SRC)/move.c \
	$(SRC)/setting.c \
	$(SRC)/settingmap.c \
	$(SRC)/check.c \
	$(SRC)/utils.c \
	$(SRC_G)/get_next_line.c \
	$(SRC_G)/get_next_line_utils.c \

OBJS	=	$(SRCS:%.c=%.o)

all:	$(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C mlx
	
fclean:	clean
	$(RM) $(NAME)

re:
	make fclean
	make all

$(NAME):	$(OBJS) $(HEADER)
	@make -C mlx
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I. $(MLX)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:	all clean fclean re
