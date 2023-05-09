/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:11:03 by donghong          #+#    #+#             */
/*   Updated: 2023/04/26 22:22:13 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_list **a, t_list **b, int flag)
{
	t_list	*tmp;

	tmp = *b;
	if (!tmp)
		return ;
	*b = (*b)->next;
	tmp->next = NULL;
	ft_lstadd_front(a, tmp);
	if (flag == 0)
		write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b, int flag)
{
	t_list	*tmp;

	tmp = *a;
	if (!tmp)
		return ;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_front(b, tmp);
	if (flag == 0)
		write(1, "pb\n", 3);
}
