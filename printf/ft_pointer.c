/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:12:39 by donghong          #+#    #+#             */
/*   Updated: 2023/03/07 21:45:31 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_pointer_itoa(unsigned int n)
{
	char	*str;
	long	num;
	int		len;

	num = (long)n;
	len = ft_len(n,16);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len--] = '\0';
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[len--] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	return (str);
}

int ft_pointer(ssize_t point) 
{
   
}