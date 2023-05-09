/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:01:23 by donghong          #+#    #+#             */
/*   Updated: 2023/04/27 13:54:15 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*ft_lstnew2(int fd)
{
	t_list	*next1;

	next1 = (t_list *)malloc(sizeof(t_list));
	if (!next1)
		return (NULL);
	next1->content = NULL;
	next1->next = NULL;
	next1->fd = fd;
	return (next1);
}

size_t	ft_strlen2(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	char	*dest;

	if (start > ft_strlen2(s))
		size = 0;
	else if (len > ft_strlen2(s + start))
		size = ft_strlen2(s + start);
	else
		size = len;
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}

void	lstfree(t_list **head)
{
	if ((*head)->content != NULL)
	{
		free((*head)->content);
		(*head)->content = NULL;
	}
	free(*head);
}
