/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:26:20 by donghong          #+#    #+#             */
/*   Updated: 2023/03/07 21:09:01 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <unistd.h>


void	ft_putchar(char *s);
size_t	ft_strlen(const char *s);
int	ft_len(long n, int base)
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
char	*ft_hexlow_itoa(unsigned int n);
char	*ft_hexupper_itoa(unsigned int n)
void	ft_str(char *s);
#endif