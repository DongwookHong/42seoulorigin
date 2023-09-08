/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:57:22 by donghong          #+#    #+#             */
/*   Updated: 2023/09/07 23:51:58 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	*philo;
	
	if (!init_info(&info, ac, av)|| !init_philo(&info, &philo))
		return (FALSE);
	eating_start(philo,philo->info);
	destroy_mutex(&info);
	free(info.forks);
	free(philo);
	return (0);
}
