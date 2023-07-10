#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <term.h>
#include <stdbool.h>
#include <stdio.h>
#include <signal.h>
#include <termios.h>
#include <readline/readline.h>
#include <readline/history.h>

#define BUCKET_SIZE 128
typedef struct termios term;
typedef struct sigaction sig;

typedef struct s_list{
int              key;
char			*value;
struct s_list	*next;
}   t_list;



typedef struct s_hashtable{
    t_list  *head; 
    int cnt;
}   t_hashtable;

/*signal*/
void main_signal();


void init_hash(t_hashtable **hashTable);
t_list	*ft_lstnew(int key,char *value);

void hash_play(char ** env, t_hashtable * hashTable);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

void get_pwd();
int	ft_lstsize(t_list *lst);
int index_function(long long key);
int hashFunction(char * data);
void search(t_hashtable* hashTable,int key);
void add(t_hashtable** hashTable,char* value);
void remove_key(t_hashtable ** hashTable ,char *value);
#endif
