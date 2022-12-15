/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:17:46 by donghong          #+#    #+#             */
/*   Updated: 2022/12/15 10:27:33 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void f(unsigned int a, char* abc)
// {
// 	(void)a;
// 	*abc += 2;	
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
