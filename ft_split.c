/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:25:41 by donghong          #+#    #+#             */
/*   Updated: 2022/11/28 16:39:09 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_str(char const *s, char c)
{
	int	flag;
	int	cnt;

	flag = 1;
	cnt = 0;
	while (*s)
	{
		if (flag == 1 && *s != c)
		{
			flag = 0;
			cnt++;
		}
		if (flag == 0 && *s == c)
			flag = 1;
		s++;
	}
	return (cnt);
}

char	**ft_free_split(char **str, int order)
{
	while (order >= 0)
	{
		free(str[order]);
		order--;
	}
	free(str);
	return (0);
}

size_t	str_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*put_word(char const *s, char c, char **str)
{
	size_t	len_word;
	size_t	i;
	char	*word;

	i = 0;
	len_word = str_len(s, c);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	while (i < len_word)
	{
		if (!word)
			return (*ft_free_split(str, i));
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**string;
	size_t	index;
	char	*ptr;

	index = 0;
	string = (char **)malloc(sizeof(char *) * (count_str(s, c) + 1));
	if (!string)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			ptr = put_word(s, c, string);
			if (!ptr)
				return (NULL);
			string[index++] = ptr;
		}
		while (*s && *s != c)
			s++;
	}
	string[index] = 0;
	return (string);
}

// int main()
// {
// 	 /*norm check ✅ */
//     int i = 0;
//     char **sk;
//     char strs[] = "w,, k,a,c";
//     char s = ',';
//     sk = ft_split(strs, s);
//     while (sk[i])
//     {
//         printf("%s\n", sk[i]);
//         i++;
//     }
//     return 0;
// }
