/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:30:04 by donghong          #+#    #+#             */
/*   Updated: 2022/12/14 18:16:42 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	find;

	find = (char)c;
	while (*s && *s != find)
		s++;
	if (*s == find)
		return ((char *)s);
	return (0);
}

/*
int main()
{
	char abc[] = "abcd";
	int c = 65;
	printf("%s\n", strchr(abc,'c'));
	printf("%s\n", ft_strchr(abc,'c'));
}
*/
