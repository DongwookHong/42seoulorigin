/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:40:50 by donghong          #+#    #+#             */
/*   Updated: 2022/11/28 16:47:07 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*st;

	dest = (unsigned char *)dst;
	st = (unsigned char *)src;
	if (st == dest || len == 0)
		return ((void *)dest);
	if (dest < st)
	{
		while (len--)
			*dest++ = *st++;
	}
	else
	{
		while (len--)
			*(dest + len) = *(st + len);
	}
	return ((void *)dst);
}
/*
int main()
{
    char str1[] = "abcdefg";
    char str2[] = "abcdefg";

    //printf("ㄴㅐ 함함수수는%s\n", ft_memmove(abc,src1,3));
    // printf("원본은 %s\n", memmove(abc,src1,3));
    // printf("------------------\n");

    //   printf("ㄴㅐ 함함수수는%s\n", ft_memmove(abc,src1,2));
    //  printf("원본은 %s\n", memmove(abc,src1,2));
    //  printf("------------------\n");

     printf("ㄴㅐ 함함수수는%s\n", ft_memmove(&str1[2],str1,5));
    printf("원본은 %s\n", memmove(&str2[2],str2,5));
    printf("------------------\n");
    
    //  printf("ㄴㅐ 함함수수는%s\n", ft_memmove(abc,src1,4));
    // printf("원본은 %s\n", memmove(abc,src1,4));
    // printf("------------------\n");



}*/
