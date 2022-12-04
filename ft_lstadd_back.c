/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:13:33 by donghong          #+#    #+#             */
/*   Updated: 2022/12/02 13:25:41 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *temp;
    
    temp = *lst;
    if (!lst || !new)
        return ;
        
    while ((*lst)-> next)
        (*lst) = (*lst) -> next;
    (*lst) -> next = new;
    *lst = temp;
}


int main()
{

    t_list *head; 
    t_list *node1;
    t_list *node2;
    t_list *node3;

    head = (t_list *)malloc(sizeof(t_list));
    node1 = (t_list *)malloc(sizeof(t_list));
    node2 = (t_list *)malloc(sizeof(t_list));
    node3 = (t_list *)malloc(sizeof(t_list));
    
    
    char * l1  = "power";
    char * l2 =   "hard";
    char * l3 = "coding ";

    head -> next = node1;

    node1 -> content = l1;
    node1 -> next = node2;
    node2 -> content = l2;
    node2 -> next = NULL;

    node3 -> content= l3;

    //ft_lstadd_back(&head,node3);
    while(head -> next )
    {
        
        printf("%s \n", head -> content);
        head = head -> next;
    }
}