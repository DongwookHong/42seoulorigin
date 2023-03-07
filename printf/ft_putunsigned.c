/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:26:44 by donghong          #+#    #+#             */
/*   Updated: 2023/03/07 17:13:44 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int ft_putunsigned(unsigned int num)
{
    char * unnum;
    unnum = ft_itoa(num);
    ft_str(unnum);
    return ft_strlen(unnum);
}