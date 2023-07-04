#include "minishell.h"

int main(int ac, char **av, char **env) {
    // 해시테이블 메모리 할당
    t_hashtable *hashTable = malloc(BUCKET_SIZE * sizeof(t_hashtable));


    for (int i = 0; i < BUCKET_SIZE; i++) {
     hashTable[i].cnt = 0;
      hashTable[i].head = NULL;
        }


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
    return 0;
}
