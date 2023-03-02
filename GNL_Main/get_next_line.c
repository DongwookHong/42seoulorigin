/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:02:04 by donghong          #+#    #+#             */
/*   Updated: 2023/03/02 16:09:18 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = 0;
	if (s1 == NULL)
		s1 = "";
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dest == NULL)
		return (0);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strchr(char *s, int c)
{
	unsigned char	find;
	int				i;

	find = (unsigned char)c;
	i = 0;
	while (s[i] && s[i] != find)
		i++;
	if (s[i] == find)
		return (i);
	return (-1);
}

char	*divide(t_list **head, int i)
{
	char	*file_content;
	char	*free_content;
	int		j;

	j = ft_strlen((*head)->content);
	free_content = (*head)->content;
	if ((*head)->content == NULL)
		return (NULL);
	else
	{
		if (i == -1)
		{
			i = ft_strchr((*head)->content, '\n');
			if (i == -1)
			{
				file_content = ft_strdup((*head)->content);
				free((*head)->content);
				(*head)->content = NULL;
				return (file_content);
			}
		}
		file_content = ft_substr((*head)->content, 0, i + 1);
		(*head)->content = ft_substr((*head)->content, i + 1, j - i - 1);
		if ((*head)->content[0] == '\0')
		{
			free((*head)->content);
			(*head)->content = NULL;
		}
		free(free_content);
	}
	return (file_content);
}

char	*read_gnl(int fd, t_list **head)
{
	ssize_t	read_file;
	char	tmp[BUFFER_SIZE + 1];
	char	*file_content;
	int		i;

	i = -1;
	if (read(fd, 0, 0) == -1)
		return (NULL);
	while ((read_file = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		tmp[read_file] = '\0';
		file_content = (*head)->content;
		(*head)->content = ft_strjoin((*head)->content, tmp);
		if (file_content != NULL)
			free(file_content);
		i = ft_strchr((*head)->content, '\n');
		if (i >= 0)
			break ;
	}
	file_content = divide(head, i);
	return (file_content);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			*save_buff;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (head == NULL)
	{
		head = ft_lstnew(fd);
		if (!head)
			return (NULL);
	}
	save_buff = read_gnl(fd, &head);
	if (save_buff == NULL)
	{
		lstfree(&head);
		head = NULL;
	}
	return (save_buff);
}
