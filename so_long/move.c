/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:17:35 by donghong          #+#    #+#             */
/*   Updated: 2023/05/16 20:48:13 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_map *map)
{
	int	i;
	int	j;

	i = map->p[0];
	j = map->p[1];
	if (map->map_down[i - 1][j] != '1' && map->map_down[i - 1][j] != 'E')
	{
		if (map->map_down[i - 1][j] == 'C')
			map->c--;
		map->map_down[i][j] = '0';
		map->map_down[i - 1][j] = 'P';
		map->p[0] = i - 1;
		map->cnt++;
	}
	if (map->map_down[i - 1][j] == 'E' && map->c == 0)
		exit(0);
	show_map(map, 0, 0);
}

void	move_s(t_map *map)
{
	int	i;
	int	j;

	i = map->p[0];
	j = map->p[1];
	if (map->map_down[i + 1][j] != '1' && map->map_down[i + 1][j] != 'E')
	{
		if (map->map_down[i + 1][j] == 'C')
			map->c--;
		map->map_down[i][j] = '0';
		map->map_down[i + 1][j] = 'P';
		map->p[0] = i + 1;
		map->cnt++;
	}
	if (map->map_down[i + 1][j] == 'E' && map->c == 0)
		exit(0);
	show_map(map, 0, 0);
}

void	move_a(t_map *map)
{
	int	i;
	int	j;

	i = map->p[0];
	j = map->p[1];
	if (map->map_down[i][j - 1] != '1' && map->map_down[i][j - 1] != 'E')
	{
		if (map->map_down[i][j - 1] == 'C')
			map->c--;
		map->map_down[i][j] = '0';
		map->map_down[i][j - 1] = 'P';
		map->p[1] = j - 1;
		map->cnt++;
	}
	if (map->map_down[i][j - 1] == 'E' && map->c == 0)
		exit(0);
	show_map(map, 0, 0);
}

void	move_d(t_map *map)
{
	int	i;
	int	j;

	i = map->p[0];
	j = map->p[1];
	if (map->map_down[i][j + 1] != '1' && map->map_down[i][j + 1] != 'E')
	{
		if (map->map_down[i][j + 1] == 'C')
			map->c--;
		map->map_down[i][j] = '0';
		map->map_down[i][j + 1] = 'P';
		map->p[1] = j + 1;
		map->cnt++;
	}
	if (map->map_down[i][j + 1] == 'E' && map->c == 0)
		exit(0);
	show_map(map, 0, 0);
}
