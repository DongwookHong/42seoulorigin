/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:26:44 by donghong          #+#    #+#             */
/*   Updated: 2023/03/10 18:18:54 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_putunsigned(unsigned int num)
{
    char * unnum;
    unnum = ft_itoa(num);
    ft_putstr_fd(unnum,1);
    return ft_strlen(unnum);
}