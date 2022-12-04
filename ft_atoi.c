/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:39:33 by donghong          #+#    #+#             */
/*   Updated: 2022/11/28 16:48:44 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || \
			str[i] == '\t' || str[i] == '\f' || \
			str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (sign * result);
}
/*
int main()
{
	char abc[20] = "-2147483648";
	char rew[20] = "2147483647";
	char zxc[20] = "0";
	printf("내결과는%d\n", ft_atoi(abc));
	printf(" 원본%d\n", atoi(abc));
	printf("내결과는%d\n", ft_atoi(rew));
	printf(" 원본%d\n", atoi(rew));
	printf("내결과는%d\n", ft_atoi(zxc));
	printf(" 원본%d\n", atoi(zxc));
}
*/
