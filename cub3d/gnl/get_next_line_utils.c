/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:01:23 by donghong          #+#    #+#             */
/*   Updated: 2023/10/22 18:16:21 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_glist	*ft_glstnew(int fd)
{
	t_glist	*next1;

	next1 = (t_glist *)malloc(sizeof(t_glist));
	if (!next1)
		return (NULL);
	next1->content = NULL;
	next1->next = NULL;
	next1->fd = fd;
	return (next1);
}

size_t	ft_gstrlen(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_gsubstr(char *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	char	*dest;

	if (start > ft_gstrlen(s))
		size = 0;
	else if (len > ft_gstrlen(s + start))
		size = ft_gstrlen(s + start);
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

char	*ft_gstrdup(char *s1)
{
	char	*abc;
	size_t	i;
	size_t	length;

	i = 0;
	length = ft_gstrlen(s1);
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

void	lstfree(t_glist **head)
{
	if ((*head)->content != NULL)
	{
		free((*head)->content);
		(*head)->content = NULL;
	}
	free(*head);
}
