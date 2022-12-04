/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 11:30:22 by donghong          #+#    #+#             */
/*   Updated: 2022/11/28 16:42:40 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_need;

	i = 0;
	len_need = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	if (!len || len < ft_strlen(needle))
		return (0);
	while (*haystack && i <= len - len_need)
	{
		if (ft_strncmp(haystack, needle, len_need) == 0)
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (0);
}
/*
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	h_len;
	size_t	n_len;

	idx = 0;
	if (!*needle)
		return ((char *)haystack);
	if (!len)
		return (0);
	h_len = ft_strlen(haystack);
	n_len = ft_strlen(needle);
	if (len < n_len)
		return (0);
	while (idx <= len - n_len && *haystack)
	{
		if (!ft_strncmp(haystack, needle, n_len))
			return ((char *)haystack);
		idx++;
		haystack++;
	}
	return (0);
}



#include <stdio.h>
int main()
{

    char str1[10] = "rewqr";
    char str2[10] = "abc";

    char str3[10] = "abcqr";
    char str4[10] = "abc";

    char str5[100] = "lorem ipsum dolor sit amet";
    char str6[10] = "lorem";


    char str7[100] = "lorem ipsum dolor sit amet";
    char str8[10] = "lorem";
    
    printf("1내함수%s\n",ft_strnstr(str1,str2,3));
    printf("1원본%s\n",strnstr(str1,str2,3));

    printf("2내함수%s\n",ft_strnstr(str3,str4,3));
    printf("2원본%s\n",strnstr(str3,str4,3));

    printf("3내함수%s\n",ft_strnstr(str5,str6,3));
    printf("3원본%s\n",strnstr(str5,str6,3));
    
    printf("4내함수%s\n",ft_strnstr(str7,str8,15));
    printf("4원본%s\n",strnstr(str7,str8,15));

}

*/
