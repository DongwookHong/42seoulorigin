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


t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;
	t_list	*ptr;

	new = ft_list(f(lst -> content));
	// if(!new)
	// 	ft_lstclear(&head,del);
	if (!lst || !f)
		return (0);
	while(lst)
	{
		f(new->content);
		lst = lst ->next;
	}
	return (new);
}
//주소값 리턴 - > 공간할 당 - >  if 할당 실패  