/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:00:27 by donghong          #+#    #+#             */
/*   Updated: 2023/09/08 15:39:06 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) < 0)
		return (-1);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

t_bool	take_sleep(t_philo *philo, t_info *info, unsigned long long time)
{
	unsigned long long	start;

	start = get_time();
	while (1)
	{
		if (check_finish(philo, info, DIED_PHI) == FALSE)
			return (FALSE);
		if (get_time() - start >= time)
			break ;
		usleep(1000);
	}
	return (TRUE);
}

void	set_start_time(t_philo *philo, t_info *info)
{
	int	i;

	info->start = get_time();
	i = -1;
	while (++i < info->ppl)
		philo[i].last_taken = info->start;
}
