/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:12:39 by donghong          #+#    #+#             */
/*   Updated: 2023/03/10 18:21:12 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_len_hexP(long n, int base)
{
	int	cnt;
	
	cnt = 0;
	if (n < 0)
	{
		n *= -1;
		cnt++;
	}
	if (n == 0)
		cnt++;
	while (n > 0)
	{
		n /= base;
		cnt++;
	}
	return (cnt);
}

static char	*ft_pointer_itoa(size_t n)
{
	char	*str;
	long	num;
	int		len;

	num = (long)n;
	len = ft_len_hexP(n,16);
	if(!len)
		return (ft_strdup("0x0"));
	len +=2;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len--] = '\0';
	str[0] = '0';
	str[1] = 'x';
	while (num > 0)
	{
		str[len--] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	return (str);
}

int ft_pointer(size_t point) 
{
   char *point_ad; 
   point_ad = ft_pointer_itoa(point);
   ft_putstr_fd(point_ad,1);
   return ft_strlen(point_ad);
}