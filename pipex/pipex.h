#ifndef PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

typedef struct s_pid{
    pid_t pid;
    int fd[2];
}t_pid;


typedef struct s_base{
    int infile;
    int outfile;
    int file_num;
    t_pid *com;
    char **path;
}t_base;


void init_pipex(int ac,t_base *base);

int	ft_strncmp(const char *s1, const char *s2, size_t n);
char **ft_split(char const *s, char c);
#endif