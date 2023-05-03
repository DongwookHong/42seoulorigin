#ifndef SO_LONG_H
#define SO_LONG_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "./mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "./gnl/get_next_line.h"

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

typedef struct s_key{
    int row;
    int col;
}   t_key;

typedef struct s_map
{
    int height;
    int width;
    int p;
    int o;
    int w;
    char *str; 
}t_map;

typedef struct s_game
{
    void *mlx;
    void *win;
}t_game;

#endif