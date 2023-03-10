/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdeci.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:22:28 by donghong          #+#    #+#             */
/*   Updated: 2023/03/10 17:22:56 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_putdeci(int num)
{
    char *str;
    str = ft_itoa(num);
    ft_putstr_fd(str,1);
    return ft_strlen(str);
}