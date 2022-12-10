/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:58:26 by donghong          #+#    #+#             */
/*   Updated: 2022/12/10 14:00:29 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst -> next;
	return (lst);
}
/*
int main()
{

    t_list *l1;
    t_list *l2;
    t_list *l3;
    t_list *last;


    l1 = (t_list *)malloc(sizeof(t_list));
    l2 = (t_list *)malloc(sizeof(t_list));
    l3 = (t_list *)malloc(sizeof(t_list));

    char * abc = "123";
    char * abc2 = "456";
    char * abc3 = "789";

    l1 -> content = abc;
    l1 -> next = l2;

    l2 -> content = abc2;
    l2 -> next    = l3;

    l3 -> content = abc3;
    l3 -> next = NULL;



   last = ft_lstlast(l2);
  printf("%s\n" , l1->content);
   while(l1)
    {
        printf("%s  ", l1->content);
        l1 = l1 -> next;
    }
    printf("%s\n", last->content);
 

}*/
