/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:48:33 by donghong          #+#    #+#             */
/*   Updated: 2023/08/28 16:33:31 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "define.h"

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_fork
{
	int				state;
	pthread_mutex_t	mutex;
}	t_fork;


typedef struct s_info
{
	int					ppl;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					time_to_think;
	int					must_eat;
	t_fork				*forks;
	unsigned long long 	start;
	int					end_flag;
	int					phi_eat_count;
	pthread_mutex_t		m_start;
	pthread_mutex_t		m_end;
	pthread_mutex_t		m_print;	
	pthread_mutex_t		m_eat;
}t_info;

typedef struct s_philo
{
	int			id;
	int			last_taken;
	int 		cnt_eat;
	int			left_time;
	int			left;
	int			right;
	t_info		*info;
	pthread_t	thread_id;
}t_philo;

#endif
