#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
    char            *content;
    int             fd;
    struct s_lst    *next;
}t_list;

int	ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char *read_gnl(int fd,t_list **head);
char *get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
t_list	*ft_lstnew(int fd);
void	lstfree(t_list **backup);
#endif