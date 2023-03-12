/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_changehex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:44:45 by donghong          #+#    #+#             */
/*   Updated: 2023/03/12 20:19:21 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_hex(unsigned int n, int base)
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

char	*ft_hexlow_itoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_len_hex(n, 16);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len--] = "0123456789abcdef"[n % 16];
		n /= 16;
	}
	return (str);
}

char	*ft_hexupper_itoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_len_hex(n, 16);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len--] = "0123456789ABCDEF"[n % 16];
		n /= 16;
	}
	return (str);
}
