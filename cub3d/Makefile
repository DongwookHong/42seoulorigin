NAME =		cub3D

CC =		cc -g3
CFLAGS =	-Wall -Wextra -Werror
INCLUDE = 	-I include \
			-I libft/libft.h \
			-I gnl/get_next_line.h \
			-I mlx

LIB = -Llibft -lft -Lmlx -framework OpenGl -framework Appkit
RM = rm -rf 

BUILD_LIBFT = make -C libft

SRC = mandatory/

CFILES = $(SRC)cube3d.c \
		$(SRC)init.c \
		$(SRC)key.c \
		$(SRC)map.c 

# CFILES :=		$(addprefix $(SRCS_RT_DIR), $(CFILES))

# SRCS = 			$(notdir $(CFILES))

OBJS_DIR = 		objs/
OBJS = 			$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

# VPATH = 		$(SRCS_RT_DIR) \
# 				$(addprefix $(SRCS_RT_DIR), $(SRCS_DIR))

$(OBJS_DIR)%o: %c
	$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

$(NAME): make_mandatory

all: $(NAME)

bonus: all

make_mandatory: $(OBJS)
	$(BUILD_LIBFT)
	$(CC) $(CFLAGS) $(LIB) $^ -o $(NAME)
	touch $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(RM) make_mandatory make_bonus
	$(BUILD_LIBFT)

fclean: clean
	$(RM) $(NAME)
	$(BUILD_LIBFT)

re: 
	make fclean
	make all

.PHONY: all clean fclean re bonus