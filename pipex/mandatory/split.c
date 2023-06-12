/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:08:38 by donghong          #+#    #+#             */
/*   Updated: 2023/06/12 19:08:39 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**free_all(char **str, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		j++;
	}
	free(str);
	return (0);
}

int	count_str(char const *str, char ch)
{
	int	flag;
	int	cnt;

	flag = 1;
	cnt = 0;
	while (*str)
	{
		if (flag == 1 && (*str) != ch)
		{
			flag = 0;
			cnt++;
		}
		if (flag == 0 && (*str) == ch)
			flag = 1;
		str++;
	}
	return (cnt);
}

char	*put_word(char const *str, char ch)
{
	int		len_word;
	int		i;
	char	*word;

	i = 0;
	len_word = 0;
	while (str[len_word] && str[len_word] != ch)
		len_word++;
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (0);
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	*skip_delimiter(const char *s, char c)
{
	while (*s && (*s == c))
		s++;
	return ((char *)s);
}

char	**ft_split(char const *s, char c)
{
	int		cnt;
	char	**string;
	int		i;

	cnt = count_str(s, c);
	i = 0;
	string = (char **)ft_calloc((cnt + 1), sizeof(char *));
	if (!string)
		return (0);
	if (!cnt)
		string[0] = ft_strdup("");
	while (*s != '\0')
	{
		s = skip_delimiter(s, c);
		if (*s)
		{
			string[i] = put_word(s, c);
			if (!string[i])
				return (free_all(string, i));
			i++;
		}
		while (*s && ((*s) != c))
			s++;
	}
	return (string);
}
