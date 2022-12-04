/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:26:11 by donghong          #+#    #+#             */
/*   Updated: 2022/11/28 16:41:17 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			str_len;
	unsigned char	find;

	str_len = ft_strlen(s);
	find = (unsigned char)c;
	while (str_len > 0 && s[str_len] != find)
		str_len--;
	if (s[str_len] == c)
		return ((char *)(s + str_len));
	return (0);
}
/*
#include <stdio.h>
int main(){

char abc[] = "rewqwrewqr";

printf("%s\n ", strrchr(abc,'r'));
printf("%s", ft_strrchr(abc,'r'));

}*/
