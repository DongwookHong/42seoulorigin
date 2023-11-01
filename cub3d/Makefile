NAME = cub3d

MLX_NAME = libmlx.a
MLX_DIR = mlx

L_DIR = Libft
L_NAME = libft.a

INCS_DIR = includes

SRC_DIR_M = mandatory
gnl = gnl

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -lz

RM = rm -f
MAKE = make

SRCS_M = $(SRC_DIR_M)/cube3d.c \
	$(SRC_DIR_M)/init.c \
	$(SRC_DIR_M)/key.c \
	$(SRC_DIR_M)/map.c \
	$(gnl)/get_next_line.c \
	$(gnl)/get_next_line_utils.c \


OBJS = $(SRCS_M:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I .

all: $(NAME)

$(NAME): $(L_NAME) $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	cp ./$(MLX_DIR)/$(MLX_NAME) .
	$(CC) $(MLX_FLAGS) -L . $^ -o $@

$(L_NAME):
	$(MAKE) -C $(L_DIR)
	cp ./$(L_DIR)/$(L_NAME) .

clean:
	$(MAKE) -C $(L_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(SRC_DIR_M)/*.o $(L_NAME)

fclean:
	$(MAKE) clean
	$(RM) $(NAME) ./$(INCS_DIR_M)/$(MLX_NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
