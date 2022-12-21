/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:30:22 by donghong          #+#    #+#             */
/*   Updated: 2022/12/15 10:28:36 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_need;
	size_t	len_hay;

	i = 0;
	len_need = ft_strlen(needle);
	len_hay = ft_strlen(haystack);
	if (*needle == '\0')
		return ((char *)haystack);
	if (!len || len < ft_strlen(needle))
		return (0);
	while (*haystack && i <= len - len_need)
	{
		if (ft_strncmp(haystack, needle, len_need) == 0)
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (0);
}
