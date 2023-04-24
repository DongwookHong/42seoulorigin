/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:13:57 by donghong          #+#    #+#             */
/*   Updated: 2023/04/24 16:13:58 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_list **a)
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
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
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
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
