/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexupper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:42:27 by donghong          #+#    #+#             */
/*   Updated: 2023/03/07 21:07:51 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_hexupper(unsigned int hexdeci)
{   
    char *hexupper;
    
    hexupper = ft_hexlow_itoa(hexdeci);
    ft_str(hexupper);
    return ft_strlen(hexupper);
}