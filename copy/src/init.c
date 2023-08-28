/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:56:02 by donghong          #+#    #+#             */
/*   Updated: 2023/08/28 20:13:16 by donghong         ###   ########.fr       */
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
	if (philo->id % 2)
		take_sleep(info->time_to_eat);
	if (info->ppl%2 && philo->id == info->ppl-1)
		take_sleep(info->time_to_eat*2);
	while(1)
	{
		if(take_left(info,philo) == FALSE
		|| take_right(info,philo) == FALSE
		|| eating(info,philo) == FALSE
		|| sleeping(info,philo) == FALSE
		|| thinking(info,philo)== FALSE)
		break;
	}
	return NULL;
}

t_bool	init_info(t_info *info, int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf("error\n");
		return (FALSE);
	}
	info->ppl = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
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
// ㅇㅖ외처리 필요함 
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

void eating_start(t_philo * philo, t_info *info)
{
	int i;

	i = -1;
	pthread_mutex_lock(&info->m_start);
	while (++i < info->ppl)
	{
		if (pthread_create(&philo[i].thread_id, NULL, thread_function, &philo[i]))
			info->end_flag=1;
	}
	pthread_mutex_unlock(&info->m_start);
	if (info -> end_flag)
		printf("died\n");
	i = -1;
	while (++i < info->ppl)
		pthread_join(philo[i].thread_id, NULL);
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
	}
}