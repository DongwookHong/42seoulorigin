/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:16:15 by donghong          #+#    #+#             */
/*   Updated: 2023/05/17 16:04:55 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setting(char **av, t_map *map)
{
	t_list	*head;
	int		fd;
	char	*filename;
	int		len;

	head = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error(2);
	filename = av[1];
	len = ft_strlen(filename);
	if (len < 4 || ft_strcmp(&filename[len - 4], ".ber") != 0)
		error(2);
	head = read_map(fd);
	if (!head)
		error(3);
	map->width = ft_strlen(head->content) - 1;
	map->height = ft_lstsize(head);
	init_map(map);
	copy_map(map, &head);
	find(map);
	key_init(map);
	map_check(*map);
}
