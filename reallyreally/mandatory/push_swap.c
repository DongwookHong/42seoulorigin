/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:08:09 by donghong          #+#    #+#             */
/*   Updated: 2023/04/26 22:49:03 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int ac, char *av[])
{
	char	**sp;
	t_info	info;
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	sp = NULL;
	ft_memset(&info, 0, sizeof(t_info));
	sp = fix(ac, av);
	if (!sp)
		return (0);
	changesp(&a, &b, info, sp);
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (0);
}
