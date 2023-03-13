/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:12:39 by donghong          #+#    #+#             */
/*   Updated: 2023/03/13 21:18:24 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_hexp(unsigned long long n, int base)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		cnt++;
	while (n > 0)
	{
		n /= base;
		cnt++;
	}
	return (cnt);
}

static char	*ft_pointer_itoa(unsigned long long n)
{
	char	*str;
	int		len;

	if (!n)
		return (ft_strdup("0x0"));
	len = ft_len_hexp(n, 16);
	len += 2;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len--] = '\0';
	str[0] = '0';
	str[1] = 'x';
	while (n > 0)
	{
		str[len--] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	return (str);
}

int	ft_pointer(unsigned long long point)
{
	char	*point_ad;
	int		len;

	point_ad = ft_pointer_itoa(point);
	if (!point_ad)
		return (0);
	len = ft_strlen(point_ad);
	ft_putstr_fd(point_ad, 1);
	free(point_ad);
	return (len);
}
