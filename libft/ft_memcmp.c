/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:20:47 by donghong          #+#    #+#             */
/*   Updated: 2022/12/15 10:26:56 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ar1;
	unsigned char	*ar2;
	size_t			i;

	i = 0;
	ar1 = (unsigned char *)s1;
	ar2 = (unsigned char *)s2;
	while (i < n)
	{
		if (ar1[i] != ar2[i])
			return (ar1[i] - ar2[i]);
		else
			i++;
	}
	return (0);
}
