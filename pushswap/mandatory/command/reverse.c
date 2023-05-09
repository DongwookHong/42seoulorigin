/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:13:57 by donghong          #+#    #+#             */
/*   Updated: 2023/04/26 22:20:31 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_list **a, int flag)
{
	t_list	*tmp;
	t_list	*head;

	head = (*a);
	if (!head || !head->next)
		return ;
	while (head->next)
	{
		tmp = head;
		head = head->next;
	}
	tmp->next = NULL;
	head->next = *a;
	*a = head;
	if (flag == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_list **b, int flag)
{
	t_list	*tmp;
	t_list	*head;

	head = (*b);
	if (!head || !head->next)
		return ;
	while (head->next)
	{
		tmp = head;
		head = head->next;
	}
	tmp->next = NULL;
	head->next = *b;
	*b = head;
	if (flag == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b, int flag)
{
	rra(a, 2);
	rrb(b, 2);
	if (flag == 1)
		write(1, "rrr\n", 4);
}
