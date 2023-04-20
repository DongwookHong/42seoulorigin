#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}


size_t	ft_strlen2(const char *s)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		i++;
		k++;
	}
	return (i+(k));
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
	dest = (char *)malloc(sizeof(char) *(ft_strlen(s1) + ft_strlen2(s2) + 1));
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
	dest[i+1] = '\0';
	return (dest);
}


char ** fix(int k,char *st[])
{
    char * join;
    char **sp;
	char *temp;
    int j;
    int x;

    x =0;
    j = 1;
    join = ft_strdup("");
	sp=NULL;
	
    while(k > 1)
    {
       sp=ft_split(st[j] , ' ');
	   if(!sp)
			return NULL;
       while(sp[x])
       {			
	   		temp = join;
            join = ft_strjoin(join,sp[x]);
			if (!temp )
				free(temp);
			free(sp[x]);
            x++;
       }
	   free(sp);
       x=0;
       j++;
       k--;  
    }
    sp = ft_split(join,' ');
	free(join);
    return sp;
}


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
