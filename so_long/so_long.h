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
    int cnt;
    int width;
    int p[2];
    int  c;
    int e[2];
    t_key *move;
    char *str; 
    void *mlx;
    void *win;
    char **map_down;
}t_map;



t_list	*read_map(int fd);


void setting(int ac , char **av,t_map *map);
void copy_map(t_map *map,t_list **head);
void init_map(t_map *map);
void	initialize_map(t_map *info);
void	key_init(t_map *map);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
void	*ft_calloc(size_t count, size_t size);
int		key_press(int keycode, t_map *map);
void	key_init(t_map *map);
int	show_map(t_map *map, int x, int y);
void	error();

void	ft_lstclear(t_list **lst);
void map_check(t_map map);

void  find(t_map *map);
void	move_w(t_map *map);
void	move_s(t_map *map);
void	move_d(t_map *map);
void	move_a(t_map *map);
#endif