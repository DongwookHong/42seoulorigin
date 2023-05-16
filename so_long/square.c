#include "so_long.h"

void	square_check(t_map map)
{
	int	base;
	int	i;
	int	len;

	base = ft_strlen(map.map_down[0]);
	i = 0;
	len = 0;
	while (i < map.height)
	{
		len = ft_strlen(map.map_down[i]);
		if (base != len)
			error();
		i++;
	}
}

void	surround(t_map map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (i == 0 || i == map.height - 1 || j == 0 || j == map.width - 1)
			{
				if (map.map_down[i][j] != '1')
					error();
			}
			j++;
		}
		i++;
	}
}

void	check_factor(t_map map)
{
	int	i = 0;
	int	j;

	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (!((map.map_down[i][j] == '1') || (map.map_down[i][j] == '0') || \
            (map.map_down[i][j] == 'C') || (map.map_down[i][j] == 'P') || \
            (map.map_down[i][j] == 'E')))
				error();
			j++;
		}
		i++;
	}
}

void	map_check(t_map map)
{
	square_check(map);
	surround(map);
	check_factor(map);
}
