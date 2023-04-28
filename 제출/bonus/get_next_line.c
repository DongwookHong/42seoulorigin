/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:02:04 by donghong          #+#    #+#             */
/*   Updated: 2023/04/27 13:54:07 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		s1 = "";
	dest = (char *)malloc(sizeof(char) * (ft_strlen2(s1) + ft_strlen2(s2) + 1));
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

char	*divide(t_list **head, int i, int j)
{
	char	*file_content;
	char	*free_content;

	free_content = (*head)->content;
	if ((*head)->content == NULL)
		return (NULL);
	i = ft_strchr((*head)->content, '\n');
	if (i == -1)
	{
		file_content = ft_strdup((*head)->content);
		free((*head)->content);
		(*head)->content = NULL;
		return (file_content);
	}
	file_content = ft_substr((*head)->content, 0, i + 1);
	(*head)->content = ft_substr((*head)->content, i + 1, j - i - 1);
	if ((*head)->content[0] == '\0')
	{
		free((*head)->content);
		(*head)->content = NULL;
	}
	free(free_content);
	return (file_content);
}

char	*read_gnl(int fd, t_list **head, int j)
{
	ssize_t	read_file;
	char	tmp[BUFFER_SIZE + 1];
	char	*file_content;
	int		i;

	i = -1;
	if (read(fd, 0, 0) == -1)
		return (NULL);
	while (1)
	{
		read_file = read(fd, tmp, BUFFER_SIZE);
		if (read_file == 0)
			break ;
		tmp[read_file] = '\0';
		file_content = (*head)->content;
		(*head)->content = ft_strjoin2((*head)->content, tmp);
		if (file_content != NULL)
			free(file_content);
		i = ft_strchr((*head)->content, '\n');
		if (i >= 0)
			break ;
	}
	j = ft_strlen2((*head)->content);
	file_content = divide(head, i, j);
	return (file_content);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	char			*save_buff;
	int				j;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (head == NULL)
	{
		head = ft_lstnew2(fd);
		if (!head)
			return (NULL);
	}
	j = ft_strlen2((head)->content);
	save_buff = read_gnl(fd, &head, j);
	if (save_buff == NULL)
	{
		lstfree(&head);
		head = NULL;
	}
	return (save_buff);
}
