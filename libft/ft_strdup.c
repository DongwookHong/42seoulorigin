/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:12:46 by donghong          #+#    #+#             */
/*   Updated: 2022/12/15 10:27:29 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*abc;
	size_t	i;
	size_t	length;

	i = 0;
	length = ft_strlen(s1);
	abc = (char *)malloc(sizeof(char) * length + 1);
	if (!abc)
		return (0);
	while (i < length)
	{
		abc[i] = s1[i];
		i++;
	}
	abc[i] = '\0';
	return (abc);
}
