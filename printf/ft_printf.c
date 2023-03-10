/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:56:17 by donghong          #+#    #+#             */
/*   Updated: 2023/03/10 16:39:32 by donghong         ###   ########.fr       */
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
            cnt += ft_check(form[i], ap);
            if (cnt == -1)
                return -1;
        }        
        else 
        {
            ft_char(form[i]);
            cnt ++;
        }
       ++i;
    }
    va_end(ap);
    return (cnt);
}

