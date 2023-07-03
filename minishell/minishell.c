#include "minishell.h"


int count_envp(char **envp)
{
    int i =0;

    while(envp[i])
        i++;
    return i;
}


int main(int ac, char ** av, char **env){
    // 해시테이블 메모리 할당
    hashTable = (t_hashtable *)malloc(BUCKET_SIZE * sizeof(t_hashtable));

    int i =0;
    int cnt = count_envp(env);

    while(i<cnt)
    {
        add(i,env[i]);
        i++;
    }
    display();
}