/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:31:21 by donghong          #+#    #+#             */
/*   Updated: 2022/12/03 21:01:55 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void del(void *content)
{
    free(content);
}



void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *temp;
    
    if (!lst || !del)
        return ;
    while(*lst)
    {
        temp = (*lst) -> next;
        del((*lst) -> content);
        free(*lst);
        *lst = temp;
      
    }
    (*lst) = 0;
}


//  int main()
// {

//     t_list	*head;
// 	t_list	*node1;
// 	t_list	*node2;
//     t_list *node3;

// 	head = (t_list *)malloc(sizeof(t_list));
// 	node1 = (t_list *)malloc(sizeof(t_list));
//     node2 = (t_list *)malloc(sizeof(t_list));
//     node3 = (t_list *)malloc(sizeof(t_list));


//     char *l1  =  malloc(5);
//     char *l2 = malloc(5);
//     char *l3 =  malloc(5);
    

//     char *t1  =  malloc(5);
//     char *t2 = malloc(5);
//     char *t3 =  malloc(5);

//     t1 = "123";
//     t2 = "456";
//     t3 = "789";
	
//     strcpy(l1 , t1);
//     strcpy(l2 , t2);
//     strcpy(l3 , t3);


//     head->next = node1;
    
//     node1->content = l1;
//     node1->next = node2;
    
//     node2->content = l2;
//     node2->next = node3;

//     node3 -> content =l3;
//     node3 -> next = NULL;


//     ft_lstclear(&head, &del);
    

//     while (head!=NULL)
//     {
//         printf("%s\n", head->content);
//         // printf("%p\n", head->next);
//         head = head->next;
//     }

// }