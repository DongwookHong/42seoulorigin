#ifndef HASH_H
# define HASH_H

#define BUCKET_SIZE 128

typedef struct s_hash{
int              key;
char			*value;
struct s_hash	*next;
}   t_hash;

typedef struct s_hashtable{
    t_hash  *head; 
    int cnt;
}   t_hashtable;


void init_hash(t_hashtable **hashTable);
void hash_play(char ** env, t_hashtable * hashTable);
int hashFunction(char * data);
void search(t_hashtable* hashTable,int key);
void add(t_hashtable** hashTable,char* value);
void remove_key(t_hashtable ** hashTable ,char *value);
int index_function(long long key);
#endif