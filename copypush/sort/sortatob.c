/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortatob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:11:32 by donghong          #+#    #+#             */
/*   Updated: 2023/04/21 17:14:16 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int direction(t_list **a, t_info info)
{
    int front = 1;
    int center = info.size / 2;
    int tri = info.size / 3;
    t_list *temp = *a;
    int cnt = 0;
    
    while (temp)
    {
        if (center <= front)
        {
            if (temp->order <= tri)
                cnt++;
        }
        temp = temp->next;
        front++;
    }
    if (cnt >= (tri / 3) * 2)
        return 1;
    else 
        return -1;
}

void sortatob(t_list **a, t_list **b, t_info info)
{
    int i = 0;
    int num = info.chunk;
    int size = info.size;
    int dire = direction(a, info);
    
    while (i < size)
    {
        if ((*a)->order > num + i)
        {
            if (dire == 1 && size > 100)
                rra(a);
            else
                ra(a);
        }
        else
        {
            if ((*a)->order < i)
                pb(a, b);
            else
            {
                pb(a, b);
                rb(b);
            }
            i++;
        }
    }
}
