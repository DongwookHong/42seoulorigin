/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:40:12 by donghong          #+#    #+#             */
/*   Updated: 2023/03/13 09:41:34 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(char ch, va_list ap)
{
	int	cnt;

	cnt = 0;
	if (ch == 'c')
		cnt += (ft_putchar(va_arg(ap, int)));
	else if (ch == 's')
		cnt += (ft_putstr(va_arg(ap, char *)));
	else if (ch == 'd' || ch == 'i')
		cnt += (ft_putdeci(va_arg(ap, int)));
	else if (ch == 'u')
		cnt += (ft_putunsigned(va_arg(ap, unsigned int)));
	else if (ch == 'x')
		cnt += (ft_hexlow(va_arg(ap, unsigned int)));
	else if (ch == 'X')
		cnt += (ft_hexupper(va_arg(ap, unsigned int)));
	else if (ch == 'p')
		cnt += (ft_pointer(va_arg(ap, size_t)));
	else if (ch == '%')
		cnt += (ft_putchar('%'));
	else
		return (-1);
	return (cnt);
}
