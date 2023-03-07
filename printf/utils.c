/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:44:45 by donghong          #+#    #+#             */
/*   Updated: 2023/03/07 21:03:22 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"



size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_len(long n, int base)
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

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;

	num = (long)n;
	len = ft_len(n,10);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len--] = '\0';
	if (num == 0)
		str[0] = '0';
	else if (num < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	while (num > 0)
	{
		str[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

char	*ft_hexlow_itoa(unsigned int n)
{
	char	*str;
	long	num;
	int		len;

	num = (long)n;
	len = ft_len(n,16);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len--] = '\0';
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[len--] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	return (str);
}

char	*ft_hexupper_itoa(unsigned int n)
{
	char	*str;
	long	num;
	int		len;

	num = (long)n;
	len = ft_len(n,16);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len--] = '\0';
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[len--] = "0123456789ABCDEF"[num % 16];
		num /= 16;
	}
	return (str);
}



char	*ft_strdup(const char *s1)
{
	char	*abc;
	size_t	i;
	size_t	length;

	i = 0;
	length = ft_strlen(s1);
	abc = (char *)malloc(sizeof(char) * length + 1);
	if (!abc)
		return (0);
	while (i < length)
	{
		abc[i] = s1[i];
		i++;
	}
	abc[i] = '\0';
	return (abc);
}


void	ft_str(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}
