/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:13:08 by donghong          #+#    #+#             */
/*   Updated: 2023/08/30 23:52:21 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USE_H
# define USE_H

# include "struct.h"
# include "define.h"

void				*ft_calloc(size_t count, size_t size);
int					ft_atoi(const char *str);


void	init_philo(t_info *info, t_philo **philo);
void	init_fork_mutex(t_info *info);
unsigned long long 	get_time(void);
t_bool	init_info(t_info *info, int ac, char **av);
void	*thread_function(void *arg);

void eating_start(t_philo * philo, t_info *info);
t_bool print_check(t_info *info,t_philo *philo,char *str);
t_bool	check_finish(t_philo *philo, t_info *info, char *str);

t_bool take_left(t_info *info, t_philo *philo);
t_bool take_right(t_info *info, t_philo *philo);
t_bool	eating( t_info *info,t_philo *philo);
t_bool	sleeping(t_info *info,t_philo *philo);
t_bool	thinking(t_info *info, t_philo *philo);


t_bool take_sleep(t_philo *philo, t_info *info, unsigned long long  time);
void check_think_time(t_info *info);
#endif