/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:56:17 by donghong          #+#    #+#             */
/*   Updated: 2023/03/07 20:26:24 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


int ft_printf(char * form, ...)
{
    va_list ap;
    va_start(ap,form);
    int i =0;
    int cnt = 0;
    while(form[i])
    {
        if(form[i] == '%')
        {   
            ++i;
            cnt += check(form[i], ap);
            ++i;          
        }
        else 
        {
            ft_char(form[i]);
            ++i;
        }
    }
    
    va_end(ap);
}

