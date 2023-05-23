/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:02:32 by donghong          #+#    #+#             */
/*   Updated: 2023/05/16 22:53:51 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_gnl_list
{
	char			*content;
	int				fd;
	struct s_list	*next;
}				t_gnl_list;

char		*read_gnl(int fd, t_gnl_list **head, int j);
char		*get_next_line(int fd);
size_t		ft_strlen(char *s);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_strdup(char *s1);
t_gnl_list	*ft_gnl_lstnew(int fd);
void		lstfree(t_gnl_list **backup);

#endif