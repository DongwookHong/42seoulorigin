/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:50:41 by donghong          #+#    #+#             */
/*   Updated: 2023/03/10 17:22:52 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putstr(char * str)
{
	int cnt;
	if(str == NULL)
	{
		ft_putstr_fd("(NULL)",1);
		cnt = ft_strlen("(NULL)");
		return  cnt;	
	}
	ft_putstr_fd(str,1);
	return ft_strlen(str);
}
