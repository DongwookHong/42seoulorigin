/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:57:22 by donghong          #+#    #+#             */
/*   Updated: 2023/08/25 00:12:48 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	*philo;

	init_info(&info, ac, av);
	init_philo(&info, &philo);
	eating_start(philo,philo->info);
	return (0);
}
