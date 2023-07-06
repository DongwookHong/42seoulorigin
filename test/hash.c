#include "minishell.h"



int str_cut(char * str)
{
    int i =0;
    while(str[i])
    {
        if (str[i] == '=')
            break;
        i++;
    }
    return i+1;
}

int hashFunction(char * data)
{
    int    key = 0;
    int    i = 0;
    int    find_equal=0; 
    if (!data)
        return (0);
    find_equal = str_cut(data);
    int num =0;
    long long sum =0;
    while(i< find_equal)
    {
        int j = i;
        long long r = 1;
        num = data[i];
        
        while(j)
        {
            r = (r * 31) % 1234567891;
            j--;
        }
        sum += (num * r) % 1234567891;
        i++;
    }
   return(sum % 1234567891);
    
}


int index_function(long long key)
{
    return (key%BUCKET_SIZE);
}

void add(t_hashtable** hashTable,char* value) {
    int cut = str_cut(value);
    int len = ft_strlen(value);
    char *str = ft_substr(value,cut,len -cut);
    long long key = hashFunction(value);
    int index = index_function(key);

    t_list* newlist = ft_lstnew(key, str);
    if ((*hashTable)[index].cnt == 0) {
        (*hashTable)[index].cnt = 1;
        (*hashTable)[index].head = newlist;
    }
    else {
        newlist->next = (*hashTable)[index].head;
        (*hashTable)[index].head = newlist;
        (*hashTable)[index].cnt++;
    }
}

// void ft_unset(t_hashtable ** hashTable ,char *value)
// {
//     int key = hashFunction(value);
//     int index = key_function(key);
//     int flag = 0;
//     t_hashtable *remove;

//     remove =search(*hashTable,key);
//     t_list* list;
//     t_list* previous; 
//     list = (*hashTable)[index].head;
//     while (list != NULL) 
//     {
//         if (list->key == key){
           
//             if (list == (*hashTable)[index].head){
//                 (*hashTable)[index].head = list->next; 
//             }
//             else{
//                 previous->next = list->next; 
//             }
//             (*hashTable)[index].cnt--;
//             free(list);
//             flag = 1;
//         }
//         previous = list; 
//         list = list->next;
//     }
   
//     if (flag == 1){ 
//         printf("\n [ %d ] 이/가 삭제되었습니다. \n", key);
//     }
//     else{ 
//         printf("\n [ %d ] 이/가 존재하지 않아 삭제하지 못했습니다.\n", key);
//     }
// }
void ft_unset(t_hashtable ** hashTable ,char *value)
{
    int key = hashFunction(value);
    int index = index_function(key);
    int flag = 0;
 
    t_list* list;
    t_list* previous; 
    list = (*hashTable)[index].head;
    while (list != NULL) 
    {
        if (list->key == key){
           
            if (list == (*hashTable)[index].head){
                (*hashTable)[index].head = list->next; 
            }
            else{
                previous->next = list->next; 
            }
            (*hashTable)[index].cnt--;
            free(list);
            flag = 1;
        }
        previous = list; 
        list = list->next;
    }
   
    if (flag == 1){ 
        printf("\n [ %d ] 이/가 삭제되었습니다. \n", key);
    }
    else{ 
        printf("\n [ %d ] 이/가 존재하지 않아 삭제하지 못했습니다.\n", key);
    }
}

// t_list* search(t_hashtable* hashTable, int key) {
//     int index = index_function(key);
//     t_list* list = hashTable[index].head;

//     while (list != NULL) {
//         if (list->key == key) {
//             return list;
//         }
//         list = list->next;
//     }
    
//     return NULL; 
// }

void search(t_hashtable* hashTable,int key)
{
    int index = index_function(key);
    t_list *list = hashTable[index].head;

    int flag = 0;
    while (list != NULL)
    {
        if (list->key == key){
            flag = 1;
            break;
        }
        list = list->next;
    }
    if (flag == 1){
        printf("\n 키는 [ %d ], 값은 [ %s ] 입니다.\n", list->key, list->value);
    }
    else{
        printf("NOT FOUND \n");
    }
}





void hash_play(char ** env, t_hashtable * hashTable)
{
    int i = 0;
    while (env[i]) {
        printf("%s\n", env[i]);
        add(&hashTable,env[i]);
        i++;
    }
    i =0;
    while(env[i])
    {
        int k = hashFunction(env[i]);
        search(hashTable,k);
        i++;
    }

}