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

#ifndef gnl_H
# define gnl_H


#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct s_list
{
    char            *content;
    int             fd;
    struct s_lst    *next;
}t_list;


#endif
