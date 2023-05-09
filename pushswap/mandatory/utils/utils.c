/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:13:23 by donghong          #+#    #+#             */
/*   Updated: 2023/05/04 16:06:33 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*abc;
	size_t	i;
	size_t	length;

	i = 0;
	length = ft_strlen(s1);
	abc = (char *)malloc(sizeof(char) * (length + 1));
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		s1 = "";
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!dest)
		return (0);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = ' ';
	dest[i + 1] = '\0';
	return (dest);
}

char	*join_strings(char *join, char **sp)
{
	int		i;
	char	*temp;

	i = 0;
	while (sp[i])
	{
		temp = join;
		join = ft_strjoin(join, sp[i]);
		if (temp)
			free(temp);
		free(sp[i]);
		i++;
	}
	free(sp);
	return (join);
}

char	**fix(int k, char *st[])
{
	char	*join;
	char	**sp;
	int		j;

	j = 1;
	join = ft_strdup("");
	sp = NULL;
	while (k-- > 1)
	{
		sp = ft_split(st[j++], ' ');
		if (sp[0][0] == '\0')
		{
			error_msg();
			return (NULL);
		}
		join = join_strings(join, sp);
	}
	sp = ft_split(join, ' ');
	free(join);
	return (sp);
}
