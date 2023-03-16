/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:56:17 by donghong          #+#    #+#             */
/*   Updated: 2023/03/16 11:46:57 by donghong         ###   ########.fr       */
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

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		cnt;
	int		temp;

	i = 0;
	cnt = 0;
	temp = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			temp = ft_check(format[i + 1], ap);
			if (temp == -1)
				return (-1);
			cnt += temp;
			i++;
		}
		else
			cnt += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (cnt);
}
