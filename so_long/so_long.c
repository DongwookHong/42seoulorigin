#include "so_long.h"

void	put_img(t_map *map,int y,int x,char *file)
{
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(map->mlx,file, &img_width, &img_height);
	mlx_put_image_to_window(map->mlx, map->win, img,y*50,  x*50);
	mlx_destroy_image(map->mlx, img);
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
			break;
		ft_lstadd_back(&head, new);
		str = get_next_line(fd);
	}
	return (head);
}
void	initialize_map(t_map *info)
{
	info->c = 0;
	info->e = 0;
	info->p = 0;
	info->height = 0;
	info->width = 0;
}

void init_map(t_map *map)
{
    int i = 0;
    map->map_down = (char **)calloc(map->height + 1, sizeof(char *));
    while (i < map->height)
    {
        map->map_down[i] = (char *)calloc(map->width + 1, sizeof(char));
        i++;
    }
    map->map_down[i] = NULL;
}

void copy_map(t_map *map,t_list **head){
	
	int i =0;
	t_list *temp;

	temp = *head;
	while(i< map->height)
	{
		// map->map_down[i] = ft_strdup(temp->content);
		ft_strlcpy(map->map_down[i], temp->content, map->width + 1);
		temp = temp->next;
		i++;
	}
	map->map_down[i] = NULL; 
}

int	show_map(t_map *map, int x, int y, int index)
{
	mlx_clear_window(map->mlx, map->win);
	while (x++ < map->height)
	{
		 y= 0;
		while (y++ < map->width)
		{
			if (map->map_down[x][y] == '0')
				put_img(map, y, x, "./pic/floor.xpm");
			else if (map->map_down[x][y] == '1')
				put_img(map, y, x, "./pic/rock1.xpm");
			else if (map->map_down[x][y]  == 'E')
			{
				put_img(map, y, x, "./pic/floor.xpm");
				put_img(map, y, x, "./pic/rock1.xpm");
			}
			else if (map->map_down[x][y] == 'C')
			{
				put_img(map, y, x, "./pic/floor.xpm");
				if (index % 2 == 0)
					put_img(map, y, x, "./pic/rock1.xpm");
				else
					put_img(map, y, x, "./pic/rock1.xpm");
			}
			else if (map->map_down[x][y] == 'P')
			{
				put_img(map, y, x, "./pic/floor.xpm");
				put_img(map, y, x, "./pic/monster.xpm");
			}
		}
	}
	return (0);
}


void	run_mlx(t_map *map)
{
	show_map(map, 0, 0, 0);
	// put_img(map,"./pic/monster.xpm");
	mlx_loop(map->mlx);
}

int main(int ac, char **av)
{
    t_list *head;
	t_map map;
	// t_img img;
	
	void *img;
	int img_width;
	int img_height;


	char **map_set;
    head = NULL; // line 초기화
	initialize_map(&map);
	int fd = open(av[1],O_RDONLY);
	head = read_map(fd);
	map.width = ft_strlen(head->content) -1;
	map.height = ft_lstsize(head);
	init_map(&map);

	copy_map(&map,&head);
	int i =0;
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.height * 50, map.width * 50, "map");
	// img = mlx_xpm_file_to_image(map.mlx, "./pic/monster.xpm", &img_width, &img_height);
	// mlx_put_image_to_window(map.mlx, map.win, img, 0, 0);
	// mlx_loop(map.mlx);
	run_mlx(&map);
    return (0);
}



