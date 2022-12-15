/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:33:03 by donghong          #+#    #+#             */
/*   Updated: 2022/12/15 12:12:48 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	char	*dest;

	if (start > ft_strlen(s))
		size = 0;
	else if (len > ft_strlen(s + start))
		size = ft_strlen(s + start);
	else
		size = len;
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (0);
	i = 0;
	if (size)
		while (i < len && s[start])
			dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}
