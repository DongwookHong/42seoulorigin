/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:08:09 by donghong          #+#    #+#             */
/*   Updated: 2023/04/21 17:08:11 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	char	**sp;
	t_info	info;
	t_list	*a;
	t_list	*b;

	b = NULL;
	a = NULL;
	sp = NULL;
	ft_memset(&info, 0, sizeof(t_info));
	sp = fix(ac, av);
	changesp(&a, &b, info, sp);
	ft_lstclear(&a);
	return (0);
}
