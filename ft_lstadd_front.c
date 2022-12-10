/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:35:59 by donghong          #+#    #+#             */
/*   Updated: 2022/12/10 14:09:32 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new ->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>
int main() 
{
    t_list  *node1;
    t_list  *head;
    t_list  *node2;
    t_list  *node3;
    t_list  *realhead;


    char * abc= "012";
    char * der= "567";
    char * qwe = "8910";
    char * pow = "42test";

    head = (t_list *)malloc(sizeof(t_list));
	node1 = (t_list *)malloc(sizeof(t_list));
    node2 = (t_list *)malloc(sizeof(t_list));
    node3 = (t_list *)malloc(sizeof(t_list));


    head -> content = abc;
    head -> next = node1;
    
    node1 ->content = der;
    node1 -> next = node2;
    
    node2 -> content = qwe;
    node2 -> next = NULL;
    
    node3 -> content = pow;

    ft_lstadd_front(&head,node3);
    realhead = head;
    while( head -> next !=NULL)
    {
        printf("%s  " , head ->content);
        head = head -> next ;
    }


printf("\n-------------\n");

	while(realhead!=NULL)
    {
        printf("%s\n",  realhead -> content);
        realhead = realhead->next;
    }


}*/
