/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:56:02 by donghong          #+#    #+#             */
/*   Updated: 2023/08/22 18:33:15 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*thread_function(void *arg)
{
	t_fork	*data;

	data = (t_fork *)arg;
	pthread_mutex_lock(&data->mutex);
	printf("Thread argument: %d\n", data->cnt);
	pthread_mutex_unlock(&data->mutex);
	return (NULL);
}
t_bool	init_info(t_info *info, int ac, char **av)
{
	if (ac != 5 || ac != 6)
	{
		printf("error\n");
		return (FALSE);
	}
	info->ppl = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->start = get_time();
	if (ac == 6)
		info->must_eat = ft_atoi(av[5]);
	return (TRUE);
}
// ㅇㅖ외처리 필요함 

void	init_philo(t_info *info, t_philo **philo, t_fork fork)
{
	int	i;

	i = 0;
	info->forks = (t_fork *)ft_calloc(info->ppl, sizeof(t_fork));
	*philo = (t_philo *)ft_calloc(info->ppl, sizeof(t_philo));
	if (!*philo)
		exit(1);
	pthread_mutex_init(&fork.mutex, NULL);
	while (i < info->ppl)
	{
		fork.cnt = 1;
		pthread_create(&(*philo)[i].thread, NULL, thread_function, &fork);
		i++;
	}
	while (i < info->ppl)
	{
		pthread_join((*philo)[i].thread, NULL);
		i++;
	}
	pthread_mutex_destroy(&fork.mutex);
}

t_philo	*philo(t_info *info, t_philo **philo, t_fork fork)
{
	int	i;

	i = 0;
	info->forks = (t_fork *)ft_calloc(info->ppl + 1, sizeof(t_fork));
	if (!info->forks)
		printf("error\n");
	*philo = (t_philo *)ft_calloc(info->ppl + 1, sizeof(t_philo));
	if (!*philo)
		exit(1);
	pthread_mutex_init(&fork.mutex, NULL);
	while (i < info->ppl)
	{
		fork.cnt = 1;
		pthread_create(&(*philo)[i].thread, NULL, thread_function, &fork);
		i++;
	}
	while (i < info->ppl)
	{
		pthread_join((*philo)[i].thread, NULL);
		i++;
	}
	pthread_mutex_destroy(&fork.mutex);
}