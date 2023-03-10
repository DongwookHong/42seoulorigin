/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:26:20 by donghong          #+#    #+#             */
/*   Updated: 2023/03/10 17:27:43 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"

int ft_check(char ch, va_list ap);
int	ft_puchar(int ch);
int	ft_putstr(char * str);
int ft_putdeci(int num);
int ft_putunsigned(unsigned int num);
int ft_hexupper(unsigned int hexdeci);
int ft_hexlow(unsigned int hexdeci);
char	*ft_hexlow_itoa(unsigned int n);
char	*ft_hexupper_itoa(unsigned int n);
int ft_pointer(size_t point);

#endif