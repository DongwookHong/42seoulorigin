/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:01:23 by donghong          #+#    #+#             */
/*   Updated: 2023/05/15 21:15:40 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl_list	*ft_gnl_lstnew(int fd)
{
	t_gnl_list	*next1;

	next1 = (t_gnl_list *)malloc(sizeof(t_gnl_list));
	if (!next1)
		return (NULL);
	next1->content = NULL;
	next1->next = NULL;
	next1->fd = fd;
	return (next1);
}

size_t	ft_strlen(char *s)
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

	if (start > ft_strlen(s))
		size = 0;
	else if (len > ft_strlen(s + start))
		size = ft_strlen(s + start);
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

char	*ft_strdup(char *s1)
{
	char	*abc;
	size_t	i;
	size_t	length;

	i = 0;
	length = ft_strlen(s1);
	abc = (char *)malloc(sizeof(char) * (length + 1));
	if (!abc)
		return (NULL);
	while (i < length)
	{
		abc[i] = s1[i];
		i++;
	}
	abc[i] = '\0';
	return (abc);
}

void	lstfree(t_gnl_list **head)
{
	if ((*head)->content != NULL)
	{
		free((*head)->content);
		(*head)->content = NULL;
	}
	free(*head);
}
