/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:11:36 by donghong          #+#    #+#             */
/*   Updated: 2023/04/24 17:06:05 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_lenorder(t_list **b, int size, int len)
{
	t_list	*top;
	int		topnum;

	top = *b;
	topnum = 1;
	while (top->order != size)
	{
		topnum++;
		top = top->next;
	}
	if (topnum <= len)
		return (1);
	return (2);
}

void	sort_b(t_list **b, int size)
{
	int	len;
	int	k;

	len = size / 2;
	if ((*b)->order == size)
		return ;
	k = find_lenorder(b, size, len);
	while (1)
	{
		if (k == 1)
			rb(b);
		else if (k == 2)
			rrb(b);
		if ((*b)->order == size)
			break ;
	}
}

void	sortbtoa(t_list **a, t_list **b, t_info info)
{
	int	find_order;

	find_order = info.size;
	while (find_order != 0)
	{
		sort_b(b, find_order);
		pa(a, b);
		find_order--;
	}
}
