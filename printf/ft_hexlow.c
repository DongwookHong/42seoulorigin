/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:42:36 by donghong          #+#    #+#             */
/*   Updated: 2023/03/12 20:36:09 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlow(unsigned int hexdeci)
{
	char	*hexlow;
	int		len;

	hexlow = ft_hexlow_itoa(hexdeci);
	len = ft_strlen(hexlow);
	ft_putstr_fd(hexlow, 1);
	free(hexlow);
	return (len);
}
