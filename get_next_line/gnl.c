#include "get_next_line.h"

char *cut_str(t_list **save)
{
	int i;
	char *str;

	i = strchr((*save)-> content,'\n');
	str = (char *)malloc()
}

char    *fdread(int fd, t_list **save)
{
    char    temp[BUFFER_SIZE + 1];
    char    *front;
    ssize_t rd;
    int     i;

    while(1)
    {
        i = 0;
        rd = read(fd,temp,BUFFER_SIZE);
        if (rd == 0)
            break;
        temp[rd] = '\0';
        front = (*save)-> content;
		(*save)->content = ft_strjoin((*save)-> content,temp);
		if(front != NULL)
			free(front);
		while (temp[i] != '\n' && temp[i] != '\0')
			i++;
		if (temp [i] == '\n')
			break;
	}
	temp = ft_substr(str,0,i+1);
	str = ft_substr(str,i+1,BUFFER_SIZE);
	return (front);
}

char    *get_next_line(int fd)
{
    static t_list   *save;
    char            *str;

    if (BUFFER_SIZE <= 0 || fd <0)
        return (NULL);
    if (save == NULL)
    {
        save =ft_lstnew(fd);
        if(save == NULL)
            return NULL;
    }

}
