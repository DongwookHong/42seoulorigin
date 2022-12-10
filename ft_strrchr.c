/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:26:11 by donghong          #+#    #+#             */
/*   Updated: 2022/12/09 19:54:11 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			str_len;
	char	find;

	str_len = ft_strlen(s);
	find = (char)c;
	while (str_len > 0 && s[str_len] != find)
		str_len--;
	if (s[str_len] == find)
		return ((char *)(s + str_len));
	return (0);
}

// #include <stdio.h>
// int main(){

//  char s[] = "tripouille";

// //printf("%s\n ", strrchr(abc,'r'));
// //printf("%s", ft_strrchr(abc,'r'));
// 	printf("%s ",ft_strrchr(s ,'t' + 256));
// 	printf("%s",strrchr(s ,'t' + 256));
// 	return 0;
// }
