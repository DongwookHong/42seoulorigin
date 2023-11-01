/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:02:32 by donghong          #+#    #+#             */
/*   Updated: 2023/10/24 20:57:56 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_glist
{
	char			*content;
	int				fd;
	struct s_glist	*next;
}				t_glist;

char	*read_gnl(int fd, t_glist **head, int j);
char	*get_next_line(int fd);
size_t	ft_gstrlen(char *s);
char	*ft_gsubstr(char *s, unsigned int start, size_t len);
char	*ft_gstrdup(char *s1);
t_glist	*ft_glstnew(int fd);
void	lstfree(t_glist **backup);

#endif