/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:29:32 by donghong          #+#    #+#             */
/*   Updated: 2023/05/17 15:54:33 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_init(t_map *map)
{
	t_key	*move;

	move = (t_key *)malloc(sizeof(t_key));
	if (move == NULL)
		error(4);
	move->row = map->p[0];
	move->col = map->p[1];
	map->move = move;
}

void	init_map(t_map *map)
{
	int	i;

	i = 0;
	map->map_down = (char **)calloc(map->height + 1, sizeof(char *));
	map->check = (char **)calloc(map->height + 1, sizeof(char *));
	if (!(map->map_down) || !(map->check))
		error(4);
	while (i < map->height)
	{
		map->map_down[i] = (char *)calloc(map->width + 1, sizeof(char));
		map->check[i] = (char *)calloc(map->width + 1, sizeof(char));
		if (!(map->map_down[i]) || !(map->check[i]))
			error(4);
		i++;
	}
	map->map_down[i] = NULL;
	map->check[i] = NULL;
}

void	dfs_base(t_map *map)
{
	map->check_x[0] = -1;
	map->check_x[1] = 1;
	map->check_x[2] = 0;
	map->check_x[3] = 0;
	map->check_y[0] = 0;
	map->check_y[1] = 0;
	map->check_y[2] = -1;
	map->check_y[3] = 1;
}

void	initialize_map(t_map *map)
{
	map->cnt = 0;
	map->height = 0;
	map->width = 0;
	map->p[0] = 0;
	map->p[1] = 0;
	map->e[0] = 0;
	map->e[1] = 0;
	map->c = 0;
	map->str = NULL;
	map->mlx = NULL;
	map->win = NULL;
	map->map_down = NULL;
	map->check = NULL;
	dfs_base(map);
}
