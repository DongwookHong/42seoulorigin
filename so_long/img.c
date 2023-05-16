#include "so_long.h"

void	put_img(t_map *map, int y, int x, char *file)
{
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(map->mlx, file, &img_width, &img_height);
	mlx_put_image_to_window(map->mlx, map->win, img, y * 50, x * 50);
	mlx_destroy_image(map->mlx, img);
}

int	show_map(t_map *map, int x, int y)
{
	mlx_clear_window(map->mlx, map->win);
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			if (map->map_down[x][y] == '0')
				put_img(map, y, x, "./pic/base.xpm");
			else if (map->map_down[x][y] == '1')
			{
				put_img(map, y, x, "./pic/base.xpm");
				put_img(map, y, x, "./pic/turret.xpm");
			}
			else if (map->map_down[x][y] == 'E' && map->c != 0)
			{
				put_img(map, y, x, "./pic/base.xpm");
				put_img(map, y, x, "./pic/exit1.xpm");
			}
			else if (map->map_down[x][y] == 'E' && map->c == 0)
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
