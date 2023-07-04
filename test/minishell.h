#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <term.h>
#include <stdbool.h>

#define BUCKET_SIZE 128


typedef struct s_list{
int              key;
char			*value;
struct s_list	*next;
}   t_list;



typedef struct s_hashtable{
    t_list  *head; 
    int cnt;
}   t_hashtable;





t_list	*ft_lstnew(int key,char *value);

size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

int index_function(long long key);
int hashFunction(char * data);
void search(t_hashtable* hashTable,int key);
void add(t_hashtable** hashTable,char* value);
void remove_key(t_hashtable ** hashTable ,char *value);
#endif
