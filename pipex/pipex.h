#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define cur 0;
#define prev 1;

typedef struct s_pid{
    pid_t pid;
    int fd[2];
}t_pid;


typedef struct s_base{
    int infile;
    int outfile;
    int file_num;
    int ac_num;
    t_pid *com;
    char *cmd_path;
    char **path;
    char *exc;
    char **tot;
}t_base;


void init_pipex(int ac,t_base *base);

int	ft_strncmp(const char *s1, const char *s2, size_t n);
char **ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void    ft_path(char **env,t_base *base);

char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *s);
#endif