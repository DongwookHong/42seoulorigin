/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:45:59 by donghong          #+#    #+#             */
/*   Updated: 2023/09/17 12:42:45 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_bool	check_finish(t_philo *philo, t_info *info, char *str)
{
	unsigned long long	now;
	unsigned long long	print_time;

	now = get_time();
	print_time = now - info->start;
	pthread_mutex_lock(&info->m_end);
	if (info->end_flag == 1)
	{
		pthread_mutex_unlock(&info->m_end);
		return (FALSE);
	}
	if (now - philo->last_taken >= info->time_to_die)
	{
		info->end_flag = 1;
		pthread_mutex_lock(&info->m_print);
		printf("%lld %d %s\n", print_time, philo->id + 1, str);
		pthread_mutex_unlock(&info->m_print);
		pthread_mutex_unlock(&info->m_end);
		return (FALSE);
	}
	pthread_mutex_unlock(&info->m_end);
	return (TRUE);
}

t_bool	check_input(int ac, char **av)
{
	int	i;

	if (!(ac >= 5 && ac <= 6))
		return (FALSE);
	i = 0;
	while (++i < ac)
	{
		if (!check_digit(av[i]))
			return (FALSE);
	}
	return (TRUE);
}

t_bool	check_digit(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9') && !(*str == '+'))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

t_bool	check_arg(t_info *info)
{
	if (info->ppl < 0)
	{
		printf("Philo must be at least 1\n");
		return (FALSE);
	}
	if ((info->time_to_die < 0) \
	|| (info->time_to_eat < 0) \
	|| (info->time_to_sleep < 0))
	{
		printf("Time must always be greater than 0\n");
		return (FALSE);
	}
	return (TRUE);
}

t_bool	print_check(t_info *info, t_philo *philo, char *str)
{
	unsigned long long	now;
	unsigned long long	print_time;

	if (check_finish(philo, info, DIED_PHI) == FALSE)
		return (FALSE);
	pthread_mutex_lock(&info->m_print);
	now = get_time();
	print_time = now - info->start;
	printf("%lld %d %s\n", print_time, philo->id + 1, str);
	pthread_mutex_unlock(&info->m_print);
	return (TRUE);
}
