/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:26:44 by donghong          #+#    #+#             */
/*   Updated: 2023/03/13 21:12:21 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unlen(unsigned int n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		cnt++;
	while (n > 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_unitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_unlen(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	ft_putunsigned(unsigned int num)
{
	char	*unnum;
	int		len;

	unnum = ft_unitoa(num);
	if (!unnum)
		return (0);
	len = ft_strlen(unnum);
	ft_putstr_fd(unnum, 1);
	free(unnum);
	return (len);
}
