/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:52:01 by donghong          #+#    #+#             */
/*   Updated: 2023/06/12 18:52:02 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *ch)
{
	write(2, ch, ft_strlen(ch));
	exit(1);
}

void	file_error(char *err)
{
	perror(err);
	exit(1);
}
