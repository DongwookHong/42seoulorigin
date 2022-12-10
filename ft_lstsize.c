/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:43:36 by donghong          #+#    #+#             */
/*   Updated: 2022/12/10 13:53:39 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
int main(){
    t_list *l1;
    t_list *l2;
    t_list *l3;
    l1 = (t_list *)malloc(sizeof(t_list));
    l2 = (t_list *)malloc(sizeof(t_list));
    l3 = (t_list *)malloc(sizeof(t_list));
    char *abc = "123";
    char *rew = "567";
    char * rew12= "5678";
    l1 -> content = abc;
    l1 -> next = l2;
    l2 -> content = rew;
    l2 -> next = l3;
    l3 -> content = rew12;
    l3 -> next = NULL;
    printf("%d" , ft_lstsize(l1));
}*/
