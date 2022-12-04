/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:10:30 by donghong          #+#    #+#             */
/*   Updated: 2022/11/27 17:06:51 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c = c + 'A' - 'a';
	return (c);
}
/*
int main()
{

	int a = 122;
	int b = 4;
	printf("%c\n", ft_toupper(a));
	printf("%c\n", toupper(a));
	printf("%d", a);
}
*/