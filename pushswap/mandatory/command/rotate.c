/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:14:56 by donghong          #+#    #+#             */
/*   Updated: 2023/04/26 22:20:27 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_list **a, int flag)
{
	t_list	*tmp;
	int		size;

	size = ft_lstsize(*a);
	tmp = *a;
	if (!tmp || size <= 1)
		return ;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_back(a, tmp);
	if (flag == 0)
		write(1, "ra\n", 3);
}

void	rb(t_list **b, int flag)
{
	t_list	*tmp;
	int		size;

	size = ft_lstsize(*b);
	tmp = *b;
	if (!tmp || size <= 1)
		return ;
	*b = (*b)->next;
	tmp->next = NULL;
	ft_lstadd_back(b, tmp);
	if (flag == 0)
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, int flag)
{
	ra(a, 2);
	rb(b, 2);
	if (flag == 1)
		write(1, "rr\n", 3);
}
