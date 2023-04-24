/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:11:41 by donghong          #+#    #+#             */
/*   Updated: 2023/04/24 17:45:03 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	changesp(t_list **a, t_list **b, t_info info, char **str)
{
	long	cnt;
	int		i;

	cnt = 0;
	i = 0;
	while (str[i])
	{
		cnt = ft_atoi(str[i]);
		if (cnt == -123456789012)
		{
			ft_lstclear(a);
			error_msg();
		}
		ft_lstadd_back(a, ft_lstnew(cnt));
		free(str[i]);
		i++;
	}
	free(str);
	info.size = ft_lstsize(*a);
	info.chunk = standard_num(info.size);
	double_check(*a);
	find_order(a, info.size);
	if (ordercheck(*a) == 1 || info.size <= 1)
		return ;
	sortmeth(a, b, info);
}
