/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:33:03 by donghong          #+#    #+#             */
/*   Updated: 2022/12/09 22:08:31 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*dest;

	s_len = ft_strlen(s);
	if()
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	while (i < len && (start+i) < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

// int main()
// {
//     char origin[20] = "abcde12345\0";
// 	char *rst;
// 	int idx_start=3, len=7;

// 	printf("origin string\t[%s]\n", origin);
// 	printf("start\t\t[%d]\nlen\t\t[%d]\n", idx_start, len);
// 	rst = ft_substr(origin, idx_start, len);
// 	printf("result\t\t[%s]\n", rst);
// }