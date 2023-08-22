/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:13:08 by donghong          #+#    #+#             */
/*   Updated: 2023/08/22 17:13:52 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USE_H
# define USE_H

# include "struct.h"

void				*ft_calloc(size_t count, size_t size);
int					ft_atoi(const char *str);

void				init_info(t_info *info, int ac, char **av);
void				init_philo(t_info *info, t_philo **philo, t_data data);
unsigned long long	get_time(void);

#endif