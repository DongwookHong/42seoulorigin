/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:42:27 by donghong          #+#    #+#             */
/*   Updated: 2023/03/13 21:15:47 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexupper(unsigned int hexdeci)
{
	char	*hexupper;
	int		len;

	hexupper = ft_hexupper_itoa(hexdeci);
	if (!hexupper)
		return (0);
	len = ft_strlen(hexupper);
	ft_putstr_fd(hexupper, 1);
	free(hexupper);
	return (len);
}
