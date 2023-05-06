#include "so_long.h"

void pic(t_map *map, t_img *img)
{
	int img_width;
	int img_height;

	img->img1 = mlx_xpm_file_to_image(map->mlx, "./pic/floor.xpm", &img_width, &img_height);
	img->img2 = mlx_xpm_file_to_image(map->mlx, "./pic/monster.xpm", &img_width, &img_height);
	img->img3 = mlx_xpm_file_to_image(map->mlx, "./pic/rock1.xpm", &img_width, &img_height);
}

t_list	*read_map(int fd)
{
	t_list	*head;
	t_list	*new;
	char	*str;

	head = 0;
	str = get_next_line(fd);
	if (!str)
		error();
	while (str)
	{
		new = ft_lstnew(str);
		if (!new)
			error();
		ft_lstadd_back(&head, new);
		str = get_next_line(fd);
	}
	return (head);
}
void init_map(t_map *map)
{
	int i =0;
	map->map_down = (char **)malloc((map->height+1)* sizeof(char *));
	while (i < map->height)
	{
		map->map_down[i] = (char *)malloc(sizeof(char) * map->width + 1 );
		i++;
	}
}

void map_setting(t_map map, t_list *list)
{
	t_key key;

	key.row = 0;
	while (key.row < map.height)
	{
		key.col = 0;
		while (key.col < map.width)
		{
			check_char(game, list->content[key.col], key.row, key.col);
			key.col++;
		}
		list = list->next;
		key.row++;
	}
}

int main(int ac, char **av)
{
    t_list *head;
	t_map map;
	t_img img;
	
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, 500, 500, "my_mlx");

	char **map_set;
    head = NULL; // line 초기화
	int fd = open(av[1],O_RDONLY);
	head = read_map(fd);
	map.width = ft_strlen(head->content) -1;
	map.height = ft_lstsize(head);
	init_map(&map);

	// int i =0;
	map_set = setting_map(&map,&head);

	pic(&map,&img);
	// map_setting(map_set,map,img);
	mlx_loop(map.mlx);
	
	// printf("%d\n",map.height);
	// printf("%d\n",map.width);
    // while (line)
    // {
    //     printf("%s", line->content);
    //     line = line->next;
	// }
    // // game.mlx = mlx_init();
    // game.win = mlx_new_window(game.mlx, 500, 500, "my_mlx");
    // mlx_loop(game.mlx);
    return (0);
}
