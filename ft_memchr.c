/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:11:13 by donghong          #+#    #+#             */
/*   Updated: 2022/11/22 10:20:47 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n && *str)
	{
		if (str[i] == (unsigned char)c)
			return (((void *)str + i));
		i++;
	}
	return (0);
}
/*
int main()
{
	char abc[]= "abcd";
	printf("내꺼%s\n",ft_memchr(abc,'d',3));
	printf("원본%s\n",memchr(abc,'d',3));
	printf("------------------------\n");

	printf("내꺼%s\n",ft_memchr(abc,'a',0));
	printf("원본%s\n",memchr(abc,'a',0));
	printf("------------------------\n");
	
	printf("내꺼%s\n",ft_memchr(abc,'b',4));
	printf("원본%s\n",memchr(abc,'b',4));
	printf("------------------------\n");
	

}
*/
