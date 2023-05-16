/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:12:42 by donghong          #+#    #+#             */
/*   Updated: 2023/05/16 22:03:04 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.width)
		{
			if (!((map.map_down[i][j] == '1') || (map.map_down[i][j] == '0') ||
				(map.map_down[i][j] == 'C') || (map.map_down[i][j] == 'P') ||
				(map.map_down[i][j] == 'E')))
				error();
			if (map.check[i][j] == '1')
				k++;
			j++;
		}
		i++;
	}
	if (k != (map.height * map.width))
		error();
}

void	dfs_exit(t_map *map, int cha_x, int cha_y)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	map->check[cha_x][cha_y] = '1';
	while (i < 4)
	{
		x = cha_x + map->check_x[i];
		y = cha_y + map->check_y[i];
		if (x < 0 || y < 0 || x > map->height || y > map->width)
			continue ;
		if ((map->check[x][y] == '0') || (map->check[x][y] == 'P') || \
		(map->check[x][y] == 'C') || (map->check[x][y] == 'E'))
			dfs_exit(map, x, y);
		i++;
	}
}

void	map_check(t_map map)
{
	square_check(map);
	surround(map);
	dfs_exit(&map, map.p[0], map.p[1]);
	check_factor(map);
}
