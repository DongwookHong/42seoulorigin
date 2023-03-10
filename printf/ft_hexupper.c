/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:42:27 by donghong          #+#    #+#             */
/*   Updated: 2023/03/10 16:57:45 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_hexupper(unsigned int hexdeci)
{   
    char *hexupper;
    
    hexupper = ft_hexlow_itoa(hexdeci);
    ft_putstr_fd(hexupper,1);
    return ft_strlen(hexupper);
}