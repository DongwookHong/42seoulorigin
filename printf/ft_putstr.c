/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:50:41 by donghong          #+#    #+#             */
/*   Updated: 2023/03/07 17:06:57 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putstr(char * str)
{
	int cnt;
	if(str == NULL)
	{
		ft_str("(NULL)");
		cnt = ft_strlen("(NULL)");
		return  cnt;	
	}
	ft_str(str);
	return ft_strlen(str);
}
