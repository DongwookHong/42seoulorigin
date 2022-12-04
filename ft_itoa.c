/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:26:31 by donghong          #+#    #+#             */
/*   Updated: 2022/11/28 16:01:29 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(long n)
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
		n /= 10;
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
	len = ft_len(n);
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
/*
#include <stdio.h>
int main()
{
	int a = 2147483647;
	int b = -2147483648;
	int c = 0;
	printf("내꺼는%s\n", ft_itoa(a));
//	printf("원본은 %s\n", itoa(a));
	printf("------------\n");
	printf("내꺼는%s\n", ft_itoa(b));
	//printf("원본은 %s\n", itoa(b));
	printf("------------\n");
	printf("내꺼는%s\n", ft_itoa(0));
	//printf("원본은 %s\n", itoa(b));
	printf("------------\n");
}
*/