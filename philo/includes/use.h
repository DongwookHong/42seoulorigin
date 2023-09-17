/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:13:08 by donghong          #+#    #+#             */
/*   Updated: 2023/09/17 12:48:57 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USE_H
# define USE_H

# include "struct.h"
# include "define.h"

/* init */
t_bool				init_info(t_info *info, int ac, char **av);
t_bool				init_philo(t_info *info, t_philo **philo);
t_bool				init_fork_mutex(t_info *info);
t_bool				init_mutex(t_info *info);
void				init_single_philo(t_philo *philo, int id, t_info *info);

/* check */
t_bool				check_input(int ac, char **av);
t_bool				check_digit(char *str);
t_bool				check_arg(t_info *info);
t_bool				check_finish(t_philo *philo, t_info *info, char *str);
t_bool				print_check(t_info *info, t_philo *philo, char *str);

/* act_philo */
void				eating_start(t_philo *philo, t_info *info);
void				*thread_function(void *arg);
void				check_main(t_info *info);
void				one_phil(t_info *info, t_philo *philo, char *str);

/* utils */
void				*ft_memset(void *b, int c, size_t len);
void				*ft_calloc(size_t count, size_t size);
int					ft_atoi(const char *str);
void				think_time(t_info *info);
void				destroy_mutex(t_info *info);

/* time */
unsigned long long	get_time(void);
t_bool				take_sleep(t_philo *philo, t_info *info, \
					unsigned long long time);
void				set_start_time(t_philo *philo, t_info *info);

/* execution */
t_bool				take_left(t_info *info, t_philo *philo);
t_bool				take_right(t_info *info, t_philo *philo);
t_bool				eating( t_info *info, t_philo *philo);
t_bool				sleeping(t_info *info, t_philo *philo);
t_bool				thinking(t_info *info, t_philo *philo);

#endif