/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:24:39 by donghong          #+#    #+#             */
/*   Updated: 2022/12/15 10:34:50 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;
	void	*temp;

	if (!lst || !f || !del)
		return (0);
	head = NULL;
	while (lst)
	{
		temp = f(lst ->content);
		new = ft_lstnew(temp);
		if (new == NULL)
		{
			ft_lstclear(&head, del);
			del(temp);
			return (0);
		}
		ft_lstadd_back(&head, new);
		lst = lst ->next;
	}
	return (head);
}
