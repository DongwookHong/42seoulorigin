/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:51:37 by donghong          #+#    #+#             */
/*   Updated: 2023/05/17 15:56:51 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_p(t_map *map)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map_down[i][j] == 'P')
			{
				map->p[0] = i;
				map->p[1] = j;
				flag++;
			}
			j++;
		}
		i++;
	}
	return (flag);
}

int	find_e(t_map *map)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map_down[i][j] == 'E')
			{
				map->e[0] = i;
				map->e[1] = j;
				flag++;
			}
			j++;
		}
		i++;
	}
	return (flag);
}

int	find_c(t_map *map)
{
	int	i;
	int	j;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map_down[i][j] == 'C')
				cnt++;
			j++;
		}
		i++;
	}
	map->c = cnt;
	return (cnt);
}

void	find(t_map *map)
{
	int	character;
	int	door;
	int	obstacle;

	obstacle = find_c(map);
	door = find_e(map);
	character = find_p(map);
	if (obstacle < 1 || door != 1 || character != 1)
		error(1);
}
