/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settingmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:15:20 by donghong          #+#    #+#             */
/*   Updated: 2023/05/17 16:02:30 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*read_map(int fd)
{
	t_list	*head;
	t_list	*new;
	char	*str;

	head = NULL;
	str = get_next_line(fd);
	if (!str)
	{
		error(3);
		close(fd);
	}
	while (str)
	{
		new = ft_lstnew(str);
		if (!new)
			error(4);
		ft_lstadd_back(&head, new);
		str = get_next_line(fd);
	}
	close(fd);
	return (head);
}

void	copy_map(t_map *map, t_list **head)
{
	int		i;
	t_list	*temp;
	char	*tmp;

	i = 0;
	temp = *head;
	while (i < map->height)
	{
		tmp = temp->content;
		ft_strlcpy(map->map_down[i], temp->content, map->width + 1);
		ft_strlcpy(map->check[i], temp->content, map->width + 1);
		free(tmp);
		temp = temp->next;
		i++;
	}
	ft_lstclear(head);
	map->map_down[i] = NULL;
	map->check[i] = NULL;
}
