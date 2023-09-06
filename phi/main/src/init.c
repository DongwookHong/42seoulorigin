/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:56:02 by donghong          #+#    #+#             */
/*   Updated: 2023/08/30 20:19:06 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_bool	init_info(t_info *info, int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf("error\n");
		return (FALSE);
	}
	info->ppl = ft_atoi(av[1]);
	info->time_to_die = (unsigned long long)ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->start = get_time();
	info->end_flag = 0;
	info->phi_eat_count = 0;
	if (ac == 6)
		info->must_eat = ft_atoi(av[5]);
	check_think_time(info);
	return (TRUE);
}


void	init_fork_mutex(t_info *info)
{
	int i;

	i = -1;
	info->forks = (t_fork *)ft_calloc(info->ppl+1, sizeof(t_fork));
	if (!info->forks)
		printf("error\n");
	while (++i < info->ppl)
		pthread_mutex_init(&info->forks[i].mutex,NULL);
	pthread_mutex_init(&info->m_start,NULL);
	pthread_mutex_init(&info->m_end,NULL);
	pthread_mutex_init(&info->m_print,NULL);
	pthread_mutex_init(&info->m_eat,NULL);
}



void	init_philo(t_info *info, t_philo **philo)
{
	int	i;

	i = -1;	
	*philo = (t_philo *)ft_calloc(info->ppl, sizeof(t_philo));
	if (!*philo)
		exit(1);
	init_fork_mutex(info);
	while (++i < info->ppl)
	{					
		(*philo)[i].id = i;
		(*philo)[i].info = info;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % info->ppl;
		(*philo)[i].last_taken = info->start;
	}
}