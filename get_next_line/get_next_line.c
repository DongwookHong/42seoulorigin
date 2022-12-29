/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:58:17 by donghong          #+#    #+#             */
/*   Updated: 2022/12/21 11:58:20 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include <stdio.h>
#include <string.h>
#define	BUFFERSIZE 1

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	i;
	char	*dest;

	if (start > strlen(s))
		size = 0;
	else if (len > strlen(s + start))
		size = strlen(s + start);
	else
		size = len;
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (0);
	i = 0;
	if (size)
		while (i < len && s[start])
			dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	find;

	find = (unsigned char)c;
	while (*s && *s != find)
		s++;
	if (*s == find)
		return ((char *)s);
	return (0);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = 0;
	if (!(s1) || !(s2))
		return (0);
	dest = (char *)malloc(sizeof(char) *(strlen(s1) + strlen(s2) + 1));
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
	dest[i] = '\0';
	return (dest);
}

char * get_next_line(int fd)
{

	char * buff ;
	char * temp;
	static char *str;
	
	buff = (char *)malloc(sizeof(char)* BUFFERSIZE+1);
	if (!buff)
		return NULL; 
	int i = 0;
	ssize_t rd = 1;
	if(rd < 0)
		return NULL;
	if(str == 0)
		str ="";
	while((!(ft_strchr(str,'\n'))) && rd > 0)
	{
 		rd = read(fd, buff ,BUFFERSIZE); 
		buff[rd] = '\0';
		str = ft_strjoin(str, buff);
	}

	while(str[i] != '\n' && str[i] != '\0')
		i++;

	temp = ft_substr(str,0,i+1);
	str = ft_substr(str,i+1,BUFFERSIZE);

	return temp;
}

int main()
{
	char buff[10000];
	int fd;
	int rdcnt;
    int idx;

	printf("\nstatic idx value is : %d\n" ,idx);
	fd = open("text.txt", O_RDONLY);
	int i =0;
	printf("fd : %d\n", fd);
	while( i< 19)
	{
    	char * str =get_next_line(fd);
			printf("string 의 값은 ----%s",str);
			i++;
	
	}
	close(fd);	
}
