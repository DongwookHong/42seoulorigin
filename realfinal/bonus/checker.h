/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:02:32 by donghong          #+#    #+#             */
/*   Updated: 2023/04/26 22:10:27 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../mandatory/push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>


char	*read_gnl(int fd, t_list **head, int j);
char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
t_list	*ft_lstnew2(int fd);
void	lstfree(t_list **backup);
size_t	ft_strlen2(char *s);

#endif