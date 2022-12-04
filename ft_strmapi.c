/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:52:58 by donghong          #+#    #+#             */
/*   Updated: 2022/11/28 16:32:48 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*dest;

	i = 0;
	len = ft_strlen(s);
	if (!s || !f)
		return (0);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	while (s[i] && i < len)
	{
		dest[i] = (f(i, s[i]));
		i++;
	}
	dest[i] = '\0';
	return (dest);
}	
// a 란 배열 을 대입했을때 a 변환 x 벗 b를 반환 !! 
