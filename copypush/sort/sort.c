/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:11:30 by donghong          #+#    #+#             */
/*   Updated: 2023/04/21 17:11:30 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int standard_num(int size)
{
    int stand = 0;

    if (size <= 5)
        return -1;
    else if (size <= 100)
        stand = 15;
    else
        stand = 30;

    return stand;    
}

void sortmeth(t_list **a, t_list **b, t_info info)
{
    if (info.size <= 5)
        minsort(a, b, info);
    else
    {
        sortatob(a, b, info);
        sortbtoa(a, b, info);
    }
}
