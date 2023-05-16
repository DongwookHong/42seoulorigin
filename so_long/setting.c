#include "so_long.h"

void setting(int ac , char **av,t_map *map)
{
	t_list *head;

	head = NULL;
	int fd;
	fd = open(av[1],O_RDONLY);
	if (fd <0)
	{
		error();
		return ;
	}
	head = read_map(fd);
	if (!head)
	{
		error();
		return ;
	}
	map->width = ft_strlen((head)->content)-1;
	// // printf("width-?%d\n",map->width);
	map->height = ft_lstsize(head);
	// // printf("height-?%d\n",map->height);
    init_map(map);
	copy_map(map,&head);
	find(map);
    key_init(map);
	map_check(*map);
}
