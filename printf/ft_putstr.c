/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:50:41 by donghong          #+#    #+#             */
/*   Updated: 2023/03/12 20:03:00 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	cnt;

	if (str == 0)
	{
		ft_putstr_fd("(null)", 1);
		cnt = ft_strlen("(null)");
		return (cnt);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
