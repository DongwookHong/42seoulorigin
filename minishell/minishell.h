#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <term.h>
#include <stdbool.h>

#define BUCKET_SIZE 30



typedef struct s_list{
int              key;
char			*value;
struct s_list	*next;
}   t_list;



typedef struct s_hashtable{
    t_list  *head; // 버켓 가장 앞에 있는 노드의 포인터
    int cnt; // 버켓에 들어있는 노드의 개수
}   t_hashtable;

t_hashtable * hashTable =NULL;



t_list	*ft_lstnew(int key,char *value);
int h_key_maker(char *value);
int hashFunction(int key);

void add(int key, char * value);
void remove_key(int key);
void search(int key);
void display();
#endif
