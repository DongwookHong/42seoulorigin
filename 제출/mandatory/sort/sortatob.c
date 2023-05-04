/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortatob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:11:32 by donghong          #+#    #+#             */
/*   Updated: 2023/04/26 22:39:50 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	direction(t_list **a, t_info info)
{
	int		front;
	int		center;
	int		tri;
	int		cnt;
	t_list	*temp;

	front = 1;
	center = info.size / 2;
	tri = info.size / 3;
	temp = *a;
	cnt = 0;
	while (temp)
	{
		if (center <= front && temp->order <= tri)
			cnt++;
		temp = temp->next;
		front++;
	}
	if (cnt >= (tri / 4) * 3)
		return (1);
	else
		return (-1);
}

void	rotate_a(t_list **a, int dire)
{
	if (dire == 1)
		rra(a, 0);
	else
		ra(a, 0);
}

void	push_b(t_list **a, t_list **b)
{
	pb(a, b, 0);
}

void	push_b_and_rotate(t_list **a, t_list **b)
{
	pb(a, b, 0);
	rb(b, 0);
}

void	sortatob(t_list **a, t_list **b, t_info info)
{
	int	i;
	int	num;
	int	size;
	int	dire;

	i = 0;
	num = info.chunk;
	size = info.size;
	dire = direction(a, info);
	while (i < size)
	{
		if ((*a)->order > num + i)
			rotate_a(a, dire);
		else
		{
			if ((*a)->order < i)
				push_b(a, b);
			else
				push_b_and_rotate(a, b);
			i++;
		}
	}
}
