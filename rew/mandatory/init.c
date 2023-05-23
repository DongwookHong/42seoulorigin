/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:29:32 by donghong          #+#    #+#             */
/*   Updated: 2023/05/23 18:21:42 by donghong         ###   ########.fr       */
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
	// int	i;

	// i = 0;
	map->map_down = (char **)ft_calloc(map->height + 1, sizeof(char *));
	map->check = (char **)ft_calloc(map->height + 1, sizeof(char *));
	map->do_check = (char **)ft_calloc(map->height + 1, sizeof(char *));
	if (!(map->map_down) || !(map->check) || !(map->do_check))
		error(4);
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
	map->copy = 0;
	map->door = 1;
	map->str = NULL;
	map->mlx = NULL;
	map->win = NULL;
	map->map_down = NULL;
	map->check = NULL;
	dfs_base(map);
}
