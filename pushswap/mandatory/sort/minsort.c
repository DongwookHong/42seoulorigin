/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:11:27 by donghong          #+#    #+#             */
/*   Updated: 2023/04/24 20:35:16 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	three_sort(t_list **a)
{
	t_list	*temp;
	t_list	*last;

	temp = (*a)->next;
	last = ft_lstlast(*a);
	if ((*a)->order < last->order && last->order < temp->order)
	{
		sa(a, 0);
		ra(a, 0);
	}
	else if (temp->order < (*a)->order && (*a)->order < last->order)
		sa(a, 0);
	else if ((*a)->order < temp->order && (*a)->order > last->order)
		rra(a, 0);
	else if ((*a)->order > last->order && temp->order < last->order)
		ra(a, 0);
	else if ((*a)->order > temp->order && temp->order > last->order)
	{
		sa(a, 0);
		rra(a, 0);
	}
}

void	mintwo(t_list **a)
{
	sa(a, 0);
}

void	five_sort(t_list **a, t_list **b, t_info info)
{
	int	cnt;

	cnt = info.size;
	three_sort(a);
	pb(a, b, 0);
	three_sort(a);
	pb(a, b, 0);
	three_sort(a);
	if ((*b)->order < (*b)->next->order)
		sb(b, 0);
	while (cnt-- > 0)
	{
		pa(a, b, 0);
		three_sort(a);
	}
}

void	minsort(t_list **a, t_list **b, t_info info)
{
	if (info.size == 2)
		mintwo(a);
	else if (info.size == 3)
		three_sort(a);
	else
		five_sort(a, b, info);
}
