/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:01:31 by donghong          #+#    #+#             */
/*   Updated: 2023/09/07 19:11:43 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return ((void *)b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	temp = malloc(size * count);
	if (!temp)
		return (0);
	ft_memset(temp, 0, size * count);
	return ((void *)temp);
}


void destroy_mutex(t_info *info)
{
	int	i;

	pthread_mutex_destroy(&info->m_eat);
	pthread_mutex_destroy(&info->m_end);
	pthread_mutex_destroy(&info->m_print);
	pthread_mutex_destroy(&info->m_start);
	i = -1;
	while (++i < info->ppl)
		pthread_mutex_destroy(&info->forks[i].mutex);
}

void	think_time(t_info *info)
{
	info->time_to_think = 0;
	if (info->ppl % 2)
		info->time_to_think = info->time_to_eat * 2 - info->time_to_sleep;
	else
		info->time_to_think = info->time_to_eat - info->time_to_sleep;
}
