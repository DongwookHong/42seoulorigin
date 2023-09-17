/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:42:37 by donghong          #+#    #+#             */
/*   Updated: 2023/09/17 12:48:22 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*thread_function(void *arg)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)arg;
	info = philo->info;
	pthread_mutex_lock(&info->m_start);
	pthread_mutex_unlock(&info->m_start);
	if (info->ppl == 1)
	{
		one_phil(info, philo, FORK_PHI);
		return (NULL);
	}
	if (philo->id % 2)
		take_sleep(philo, info, info->time_to_eat);
	if (info->ppl % 2 && philo->id == info->ppl - 1)
		take_sleep(philo, info, info->time_to_eat * 2);
	while (1)
	{
		if (take_left(info, philo) == FALSE || take_right(info, philo) == FALSE \
		|| eating(info, philo) == FALSE || sleeping(info, philo) == FALSE \
		|| thinking(info, philo) == FALSE)
			break ;
	}
	return (NULL);
}

void	eating_start(t_philo *philo, t_info *info)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&info->m_start);
	while (++i < info->ppl)
	{
		if (pthread_create(&philo[i].thread_id, NULL, \
		thread_function, &philo[i]) != 0)
		{
			info->end_flag = 1;
			printf("Function error\n");
			break ;
		}
	}
	set_start_time(philo, info);
	pthread_mutex_unlock(&info->m_start);
	check_main(info);
	i = -1;
	while (++i < info->ppl)
		pthread_join(philo[i].thread_id, NULL);
}

void	check_main(t_info *info)
{
	while (1)
	{
		pthread_mutex_lock(&info->m_end);
		pthread_mutex_lock(&info->m_eat);
		if ((info->phi_eat_count != 0) && (info->ppl == info->phi_eat_count))
			info->end_flag = 1;
		if (info->end_flag == 1)
		{
			pthread_mutex_unlock(&info->m_end);
			pthread_mutex_unlock(&info->m_eat);
			return ;
		}
		pthread_mutex_unlock(&info->m_end);
		pthread_mutex_unlock(&info->m_eat);
	}
}

void	one_phil(t_info *info, t_philo *philo, char *str)
{
	unsigned long long	now;
	unsigned long long	print_time;

	pthread_mutex_lock(&info->m_print);
	now = get_time();
	print_time = now - info->start;
	printf("%lld %d %s\n", print_time, philo->id + 1, str);
	pthread_mutex_unlock(&info->m_print);
	take_sleep(philo, info, info->time_to_die);
}
