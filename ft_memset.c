/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:23:02 by donghong          #+#    #+#             */
/*   Updated: 2022/11/28 16:39:47 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return ((void *)b);
}

/*
#include <stdio.h>
int main()
{
    char abc[] = "987654123";
	char c = 48;
	int	b =	48;
    printf("내함수는 :%s\n", ft_memset(abc,-1,4));
    printf("원본함수는 :%s\n", memset(abc,-1,4));
    printf("내함수는 :%s\n", ft_memset(abc,257,4));
    printf("원본함수는 :%s\n", memset(abc,257,4));
    printf("내함수는 :%s\n", ft_memset(abc,48,4));
    printf("원본함수는 :%s\n", memset(abc,48,4));

	printf ("%d", c);
	printf ("%d", b);


}
*/
