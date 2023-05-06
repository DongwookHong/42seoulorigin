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

typedef struct s_list{
    char *content;
    struct s_list *next;
}t_list;

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
    void *mlx;
    void *win;
    char **map_down
}t_map;

typedef struct s_img
{
    void *img1;
    void *img2;
    void *img3;
}t_img;


t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);

void	error();
#endif