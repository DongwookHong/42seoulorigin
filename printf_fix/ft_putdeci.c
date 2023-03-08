/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdeci.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:22:28 by donghong          #+#    #+#             */
/*   Updated: 2023/03/07 17:09:12 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_putdeci(int num)
{
    char *str;
    str = ft_itoa(num);
    ft_str(str);
    return ft_strlen(str);
}