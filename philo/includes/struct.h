/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:48:33 by donghong          #+#    #+#             */
/*   Updated: 2023/08/22 18:33:00 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_info
{
	int					ppl;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					time_to_think;
	int					must_eat;
	t_fork				*forks;
	unsigned long long	start;
}t_info;

typedef struct s_fork
{
	int				cnt;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo
{
	int			id;
	int			start;
	int			end;
	t_fork		*fork;
	pthread_t	thread;
}t_philo;

#endif
