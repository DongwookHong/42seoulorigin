/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:58:51 by donghong          #+#    #+#             */
/*   Updated: 2022/12/21 11:59:09 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef get_next_line_H
# define get_next_line_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif


#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
    char            *content;
    int             fd;
    struct s_lst    *next;
}t_list;

char *get_next_line(int fd);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
int ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_list	*ft_lstnew(void *content);

#endif
