/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:24:39 by donghong          #+#    #+#             */
/*   Updated: 2022/12/03 21:04:28 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include "libft.h"
/*void del1(void * content)
{
	free(content);
}

void *f(void *number)
{
	char *temp;

	temp = malloc(4);
	temp[0] = ((char *)number)[0];
	temp[0] += 3;
	
    return (void *)(temp);
}

*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del1)(void *))
{
	t_list	*new;
	t_list	*head;
	void * temp;
	int i=0;
	if (!lst || !f || !del1)
		return (0);
	head = NULL;
	while(lst)
	{
		temp = f(lst ->content);
		new = ft_lstnew(temp);
		
		if (i ==2)
			new =0;
		if(new == NULL)
		{
			ft_lstclear(&head,del1);
			del1(temp);
			return (0);
		}
		ft_lstadd_back(&head,new);
		lst = lst ->next;
		i++;
	}
	return (head);
}

/*
int main()
{
	t_list *head;
	t_list *node1;
	t_list *node2;
	t_list *node3;
	t_list *st;

	head =  (t_list *)malloc(sizeof(t_list));
	node1 = (t_list *)malloc(sizeof(t_list));
	node2 = (t_list *)malloc(sizeof(t_list));
	node3 = (t_list *)malloc(sizeof(t_list));

	char * l1 ;
	char * l2 ;
	char * l3 ;

	l1 = malloc(7);
	l2 = malloc(7);
	l3 = malloc(7);

	// l1 = "123";
	// l2 = "456";
	// l3 = "789";

	memcpy(l1, "123", 4);
	memcpy(l2, "456", 4);
	memcpy(l3, "789", 4);
	head -> next = node1;

	node1 -> content = l1;
	node1 -> next = node2;

	node2 -> content = l2;
	node2 -> next = node3;

	node3 -> content = l3;
	node3 -> next = NULL;

	st = ft_lstmap(node1,f,del1);

	// while(head)
	// {
	// 	printf("%s\n", (char *)head ->content);
	// 	head = head ->next;
	// }
	while(st)
	{
		printf("%s\n", (char *)st ->content);
		st= st ->next;
	}
}*/