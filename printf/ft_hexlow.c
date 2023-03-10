/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:42:36 by donghong          #+#    #+#             */
/*   Updated: 2023/03/10 19:24:54 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_hexlow(unsigned int hexdeci)
{   
    char *hexlow;
    hexlow = ft_hexlow_itoa(hexdeci);
    ft_putstr_fd(hexlow,1);
    return ft_strlen(hexlow);
}