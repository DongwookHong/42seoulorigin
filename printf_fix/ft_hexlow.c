/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:42:36 by donghong          #+#    #+#             */
/*   Updated: 2023/03/07 21:08:04 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_hexlow(unsigned int hexdeci)
{   
    char *hexlow;
    
    hexlow = ft_hexlow_itoa(hexdeci);
    ft_str(hexlow);
    return ft_strlen(hexlow);
}