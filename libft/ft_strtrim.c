/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 19:36:03 by donghong          #+#    #+#             */
/*   Updated: 2023/04/03 21:03:04 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	st;
	size_t	end;
	char	*dest;

	st = 0;
	end = ft_strlen(s1);
	if (!s1)
		return (0);
	if (!set)
		return ((char *)s1);
	while (s1[st] && ft_strchr(set, s1[st]))
		st++;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]))
		end--;
	if (st >= end)
		return (ft_strdup(""));
	dest = (char *) malloc(sizeof(char) * (end - st + 1));
	if (!dest)
		return (0);
	ft_strlcpy(dest, s1 + st, end - st +1);
	return (dest);
}
