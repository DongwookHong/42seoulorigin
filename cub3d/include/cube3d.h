#ifndef cube3d
#define cube3d

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include  "screen.h"
# include "update.h"

void init_map(char *filename);




void file_down(t_list **head,char *filename);
t_list  *component_set(t_list *list);
void set_comp(char **componets,t_list **list);
void set_map(char ***componets,t_list *list);
void map_setting(t_map *map,t_list *list);


void setting_mlx(t_monitor *monitor);
int	press_event_handler(int key_code, t_move *move);
int	exit_event_handler(int key_code, void *param);
int	release_event_handler(int key_code, t_move *move);
t_id	get_element_id(char *str);

#endif