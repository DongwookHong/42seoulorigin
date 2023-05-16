/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:14:15 by donghong          #+#    #+#             */
/*   Updated: 2023/05/16 11:14:16 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;

	initialize_map(&map);
	setting(ac, av, &map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.width * 50, map.height * 50, "map");
	show_map(&map, 0, 0);
	mlx_hook(map.win, X_EVENT_KEY_RELEASE, 0, &key_press, &map);
	mlx_loop(map.mlx);
	return (0);
}
