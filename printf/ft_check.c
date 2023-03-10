/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:40:12 by donghong          #+#    #+#             */
/*   Updated: 2023/03/10 16:39:41 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "printf.h"

int ft_check(char ch, va_list ap)
{
    if(ch == 'c')//
        return ft_putchar(va_arg(ap,int));
    else if(ch  == 's')//
        return ft_putstr(va_arg(ap,char *));
    else if(ch  == 'd' || ch == 'i')//
        return ft_putdeci(va_arg(ap,int));
    else if(ch  == 'u')//
        return ft_putunsigned(va_arg(ap,unsigned int));
    else if(ch  == 'x')//
        return ft_hexlow(va_arg(ap,unsigned int));
    else if(ch  == 'X')//
        return ft_hexupper(va_arg(ap,unsigned int));
    else if(ch  == 'p')
        return ft_pointer(va_arg(ap,void *));
    else if(ch  == '%')
        return ft_putchar('%');
    else
        return -1;
}