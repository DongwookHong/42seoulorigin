/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:00:27 by donghong          #+#    #+#             */
/*   Updated: 2023/08/30 19:34:36 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned long long 	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) < 0)
		return (-1);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

t_bool take_sleep(t_philo * philo, t_info *info, unsigned long long  time)
{
    unsigned long long  start;

    start = get_time();
	while (1)
	{
		if (check_finish(philo,info,died_phi) == FALSE)
			return FALSE;
		if (get_time() - start >= time)
			break ;
		usleep(1000);
	}
	return TRUE;
}