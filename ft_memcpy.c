/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:22:23 by donghong          #+#    #+#             */
/*   Updated: 2022/11/28 16:40:25 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;

	i = 0;
	if (src == dst || n == 0)
		return ((void *)dst);
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}


// #include <stdio.h>
// int main(){

//     char str1[] ="abcdef";
				
// 	char str2[] ="abcdef";
					
// 	// char str3[] ="abcdef";
// 	// char str4[] ="abcdef";
    

//     // ft_memcpy(str1,str,7);
//     // printf("%s\n", str1);
//     // memcpy(str1,str,7);
//     // printf("%s\n", str1);
// 	// printf("-------");
// 	// ft_memcpy(str1,str,0);
//     // printf("%s\n", str1);
//     // memcpy(str1,str,0);
//     // printf("%s\n", str1);
// 	// printf("-------");
// 	ft_memcpy(&str1[2],str1,4);
//     printf("%s\n", str1);
//     memcpy(&str2[2],str2,4);
//     printf("%s\n", str2);
// 	printf("-------");
// 	// ft_memcpy(str1,str,7);
//     // printf("%s\n", str1);
//     // memcpy(str1,str,7);
//     // printf("%s\n", str1);
 
// }
