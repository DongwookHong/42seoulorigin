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
	info->e[0] = '\0';
	info->p[0] = '\0';
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
		ft_strlcpy(map->map_down[i], temp->content, map->width + 2);
		temp = temp->next;
		i++;
	}
	map->map_down[i] = NULL; 
}

int	show_map(t_map *map, int x, int y)
{
	mlx_clear_window(map->mlx, map->win);
	while (x < map->height)
	{
		y= 0;
		while (y < map->width)
		{
			if (map->map_down[x][y] == '0')
				put_img(map, y, x, "./pic/base.xpm");
			else if (map->map_down[x][y] == '1'){
				put_img(map, y, x, "./pic/base.xpm");
				put_img(map, y, x, "./pic/turret.xpm");
			}
			else if (map->map_down[x][y]  == 'E' && map ->c !=0)
			{
				put_img(map, y, x, "./pic/base.xpm");
				put_img(map, y, x, "./pic/exit1.xpm");
			}
			else if (map->map_down[x][y]  == 'E' && map ->c ==0)
			{
				put_img(map, y, x, "./pic/base.xpm");
				put_img(map, y, x, "./pic/exit2.xpm");
			}
			else if (map->map_down[x][y] == 'C')
			{
				put_img(map, y, x, "./pic/base.xpm");
				put_img(map, y, x, "./pic/object.xpm");
			}
			else if (map->map_down[x][y] == 'P')
			{
				put_img(map, y, x, "./pic/base.xpm");
				put_img(map, y, x, "./pic/monster.xpm");
			}
	
			y++;
		}
		x++;
	}
	return (0);
}

void move_charac(t_map map){

}
int main(int ac, char **av)
{
    t_list *head;
	t_map map;
	
	char **map_set;
    head = NULL; // line 초기화
	initialize_map(&map);
	int fd = open(av[1],O_RDONLY);
	head = read_map(fd);
	map.width = ft_strlen(head->content) -1;
	map.height = ft_lstsize(head);
	init_map(&map);

	// printf("width 의값은 %d , height의값은 ?? %d\n",map.width,map.height);
	copy_map(&map,&head);
	int i =0;
	// while(map.map_down[i])
	// {
	// 	printf("%s",map.map_down[i]);
	// 	i++;
	// }
	find(&map);
	key_init(&map);
	map_check(map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.width * 50,map.height * 50, "map");
	show_map(&map, 0, 0);
	mlx_hook(map.win, X_EVENT_KEY_RELEASE, 0, &key_press, &map);
	mlx_loop(map.mlx);
    return (0);
}



