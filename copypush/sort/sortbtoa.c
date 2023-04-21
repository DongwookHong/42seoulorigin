/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:11:36 by donghong          #+#    #+#             */
/*   Updated: 2023/04/21 17:11:37 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int find_lenorder(t_list **b, int size, int len)
{
    t_list *top = *b;
    int topnum = 1;
   
    while (1)
    {
        if (top->order == size)
            break;
        topnum++;
        top = top->next;
    }
    if (topnum <= len)
        return 1;
    return 2;
}

void sort_b(t_list **b, int size)
{
    int len = size / 2;
    if ((*b)->order == size)
        return;
    int k = find_lenorder(b, size, len);
    if (k == 1)
    {
        while (1)
        {
            rb(b);
            if ((*b)->order == size)
                return;
        }
    }
    else if (k == 2)
    {
        while (1)
        {
            rrb(b);
            if ((*b)->order == size)
                return;
        }
    }
}

void sortbtoa(t_list **a, t_list **b, t_info info)
{
    int find_order = info.size;
   
    while (find_order != 0)
    { 
        sort_b(b, find_order);
        pa(a, b);
        find_order--;
    }
}
