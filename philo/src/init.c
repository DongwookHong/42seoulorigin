/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:56:02 by donghong          #+#    #+#             */
/*   Updated: 2023/09/12 15:06:03 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_bool	init_info(t_info *info, int ac, char **av)
{
	if (!check_input(ac, av))
	{
		printf("Please check Argument\n");
		return (FALSE);
	}
	info->ppl = (unsigned long long)ft_atoi(av[1]);
	info->time_to_die = (unsigned long long)ft_atoi(av[2]);
	info->time_to_eat = (unsigned long long)ft_atoi(av[3]);
	info->time_to_sleep = (unsigned long long)ft_atoi(av[4]);
	if (!check_arg(info))
		return (FALSE);
	info->start = get_time();
	info->end_flag = 0;
	info->phi_eat_count = 0;
	if (ac == 6)
		info->must_eat = (unsigned long long)ft_atoi(av[5]);
	else
		info->must_eat = -1;
	think_time(info);
	return (TRUE);
}

t_bool	init_philo(t_info *info, t_philo **philo)
{
	int	i;

	i = -1;
	*philo = (t_philo *)ft_calloc(info->ppl, sizeof(t_philo));
	if (!*philo)
	{
		printf("Malloc Error\n");
		return (FALSE);
	}
	if (!init_fork_mutex(info))
	{
		free(*philo);
		return (FALSE);
	}
	while (++i < info->ppl)
		init_single_philo(&(*philo)[i], i, info);
	return (TRUE);
}

t_bool	init_fork_mutex(t_info *info)
{
	info->forks = (t_fork *)ft_calloc(info->ppl + 1, sizeof(t_fork));
	if (!info->forks)
	{
		printf("Malloc Error\n");
		return (FALSE);
	}
	if (!init_mutex(info))
	{
		destroy_mutex(info);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	init_mutex(t_info *info)
{
	int	i;

	i = -1;
	while (++i < info->ppl)
	{
		if (pthread_mutex_init(&info->forks[i].mutex, NULL) != 0)
		{
			while (--i)
				pthread_mutex_destroy(&info->forks[i].mutex);
			free(info->forks);
			printf("MUTEX Error\n");
			return (FALSE);
		}
	}
	if (pthread_mutex_init(&info->m_start, NULL) != 0 \
	|| pthread_mutex_init(&info->m_end, NULL) != 0 \
	|| pthread_mutex_init(&info->m_print, NULL) != 0 \
	|| pthread_mutex_init(&info->m_eat, NULL) != 0)
	{		
		free(info->forks);
		printf("MUTEX Error\n");
		return (FALSE);
	}
	return (TRUE);
}

void	init_single_philo(t_philo *philo, int id, t_info *info)
{
	philo->id = id;
	philo->info = info;
	if (!(id % 2))
	{
		philo->left = id;
		philo->right = (id + 1) % info->ppl;
	}
	else
	{
		philo->left = (id + 1) % info->ppl;
		philo->right = id;
	}
}
