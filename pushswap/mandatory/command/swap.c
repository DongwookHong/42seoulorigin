/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:11:23 by donghong          #+#    #+#             */
/*   Updated: 2023/04/26 22:20:13 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **a, int flag)
{
	t_list	*tmp;

	if (*a && (*a)->next)
	{
		tmp = (*a)->next;
		(*a)->next = tmp->next;
		tmp->next = *a;
		*a = tmp;
	}
	if (flag == 0)
		write(1, "sa\n", 3);
}

void	sb(t_list **b, int flag)
{
	t_list	*tmp;

	if (*b && (*b)->next)
	{
		tmp = (*b)->next;
		(*b)->next = tmp->next;
		tmp->next = *b;
		*b = tmp;
	}
	if (flag == 0)
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b, int flag)
{
	sa(a, 2);
	sb(b, 2);
	if (flag == 1)
		write(1, "ss\n", 3);
}
