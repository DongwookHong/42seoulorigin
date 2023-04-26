/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:12:05 by donghong          #+#    #+#             */
/*   Updated: 2023/04/26 22:47:37 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_space(char a)
{
	if (a == ' ' || a == '\n' || \
		a == '\t' || a == '\f' || \
		a == '\r' || a == '\v')
	{
		return (1);
	}
	return (0);
}

int	check_num(long long k)
{
	if (k > 2147483647 || k < -2147483647)
	{
		return (1);
	}
	return (0);
}

int	check_digit(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || check_space(str[i]) \
		|| str[i] == '+' || str[i] == '-'))
		{
			return (-1);
		}
		i++;
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;
	int	digit;

	i = 0;
	sign = 1;
	result = 0;
	while (check_space(str[i]))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	digit = check_digit(str);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (check_num(sign * result) || digit == -1 || str[i] !='\0')
		return (-123456789012);
	return (sign * result);
}
