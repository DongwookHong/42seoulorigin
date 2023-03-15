/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:56:17 by donghong          #+#    #+#             */
/*   Updated: 2023/03/15 20:14:57 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			cnt += ft_check(format[i + 1], ap);
			if (cnt == -1)
				return (-1);
			i++;
		}
		else
			cnt += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (cnt);
}
