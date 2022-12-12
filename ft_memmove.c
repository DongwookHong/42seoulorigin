/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:40:50 by donghong          #+#    #+#             */
/*   Updated: 2022/12/11 16:39:09 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*st;

	dest = (unsigned char *)dst;
	st = (unsigned char *)src;
	if (st == dest || len == 0)
		return ((void *)dest);
	if (dest < st)
	{
		while (len--)
			*dest++ = *st++;
	}
	else
	{
		while (len--)
			*(dest + len) = *(st + len);
	}
	return ((void *)dst);
}
