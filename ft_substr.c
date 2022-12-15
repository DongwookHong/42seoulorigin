/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:33:03 by donghong          #+#    #+#             */
/*   Updated: 2022/12/15 09:13:45 by donghong         ###   ########.fr       */
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

// int main()
// {
//     char origin[20] = "abcde12345\0";
// 	char *rst;
// 	int idx_start=4, len=7;

// 	printf("origin string\t[%s]\n", origin);
// 	printf("start\t\t[%d]\nlen\t\t[%d]\n", idx_start, len);
// 	rst = ft_substr(origin, idx_start, len);
// 	printf("result\t\t[%s]\n", rst);
// }
