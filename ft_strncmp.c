/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:46:46 by donghong          #+#    #+#             */
/*   Updated: 2022/11/28 16:33:35 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else
			i++;
	}
	return (0);
}
/*
int main()
{

    char str1[10] = "rewqr";
    char str2[10] = "abc";

    char str3[10] = "abcqr";
    char str4[10] = "abc";

    char str5[10] = "rewqrabc";
    char str6[10] = "abc";

    printf("1내함수%d\n",ft_strncmp(str1,str2,1));
    printf("1원본%d\n",strncmp(str1,str2,1));
    printf("------------------------\n");

    printf("2내함수%d\n",ft_strncmp(str3,str4,3));
    printf("2원본%d\n",strncmp(str3,str4,3));
    printf("------------------------\n");

    printf("3내함수%d\n",ft_strncmp(str5,str6,0));
    printf("3원본%d\n",strncmp(str5,str6,0));
    printf("------------------------\n");
    
    printf("4내함수%d\n",ft_strncmp(str5,str6,8));
    printf("4원본%d\n",strncmp(str5,str6,8));

}
*/
