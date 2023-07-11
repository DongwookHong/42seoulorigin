// #include "../../incs/minishell.h"
// void init_hash(t_hashtable** hashTable) 
// {
//     int i = 0;
//     *hashTable = malloc(BUCKET_SIZE * sizeof(t_hashtable));
//     if (!(*hashTable))
//         return;
//     while (i < BUCKET_SIZE) {
//         (*hashTable)[i].cnt = 0;
//         (*hashTable)[i].head = NULL;
//         i++;
//     }
// }