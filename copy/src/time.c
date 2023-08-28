/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:00:27 by donghong          #+#    #+#             */
/*   Updated: 2023/08/28 16:31:54 by donghong         ###   ########.fr       */
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

void take_sleep(unsigned long long  time)
{
    unsigned long long  start;

    start = get_time();
	while (1)
	{
		if (get_time() - start >= time)
			break ;
		usleep(1000);
	}
}