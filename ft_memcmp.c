/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:20:47 by donghong          #+#    #+#             */
/*   Updated: 2022/11/22 10:05:55 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ar1;
	unsigned char	*ar2;
	size_t			i;

	i = 0;
	ar1 = (unsigned char *)s1;
	ar2 = (unsigned char *)s2;
	while (i < n && (ar1[i] || ar2[i]))
	{
		if (ar1[i] != ar2[i])
			return (ar1[i] - ar2[i]);
		else
			i++;
	}
	return (0);
}
/*
int main ()
{
 	char  abc[] = "abcdef";
	char  bre[] = "abcded";

	char  str1[] = "adef";
	char  str2[] = "abef";

	char  str3[5] = "1234";
	char  str4[5] = "123";

	printf("원본 %d \n" , memcmp(abc,bre,4) );	
	printf("내꺼 %d \n" , ft_memcmp(abc,bre,4) );	
	printf("------------------------\n");

	printf("원본 %d \n" , memcmp(str1,str2,6));	
	printf("내꺼 %d \n" , ft_memcmp(str1,str2,6) );	
	printf("------------------------\n");

	printf("원본 %d \n" , memcmp(str1,str2,0) );	
	printf("내꺼 %d \n" , ft_memcmp(str1,str2,0) );	
	printf("------------------------\n");

	printf("원본 %d \n" , memcmp(str3,str4,3) );	
	printf("내꺼 %d \n" , ft_memcmp(str3,str4,3) );	
	printf("------------------------\n");

	printf("원본 %d \n" , memcmp(str3,str4,5) );	
	printf("내꺼 %d \n" , ft_memcmp(str3,str4,5) );	
	printf("------------------------\n");


}
*/