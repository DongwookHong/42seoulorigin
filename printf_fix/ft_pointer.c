/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:12:39 by donghong          #+#    #+#             */
/*   Updated: 2023/03/08 16:15:39 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*ft_pointer_itoa(size_t num)
{
	char	*str;
	long	num;
	int		len;

	num = (long)n;
	len = ft_len(n,16);
	if(!len)
		return (strdup("0x0"));
	len +=2;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len--] = '\0';
	str[0] == '0';
	str[1] == 'x';
	while (num > 0)
	{
		str[len--] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	return (str);
}

int ft_pointer(size_t point) 
{
   int len;
   char *point_ad; 
   point_ad = ft_pointer_itoa(point);
   ft_str(point_ad);
   return ft_strlen(point_ad);
}