#include "minishell.h"

int hashFunction(int key){
    return key%BUCKET_SIZE;
}


void add(int key, char * value){
    // 어느 버켓에 추가할지 인덱스를 계산
    int hashIndex = hashFunction(key);
    // 새로 노드 생성
   t_list * newlist = ft_lstnew(key, value);
    if (hashTable[hashIndex].cnt == 0){
        hashTable[hashIndex].cnt = 1;
        hashTable[hashIndex].head = newlist; // head를 교체
    }
    else{
        newlist->next = hashTable[hashIndex].head;
        hashTable[hashIndex].head = newlist;
        hashTable[hashIndex].cnt++;
    }
}

void remove_key(int key){

    int hashIndex = hashFunction(key);
    // 삭제가 되었는지 확인하는 flag 선언
    int flag = 0;
    // 키를 찾아줄 iterator 선언
    t_list * list;
    t_list * before; // 노드가 지나간 바로 전 노드
    // 버켓의 head부터 시작
    list = hashTable[hashIndex].head;
    // 버켓을 순회하면서 key를 찾는다.
    while (list != NULL) // NULL 이 나올때까지 순회
    {
        if (list->key == key){
            // 포인터 바꿔주기 노드가 1 . 헤드인 경우 2 . 헤드가 아닌경우
            if (list == hashTable[hashIndex].head){
                hashTable[hashIndex].head = list->next; // 다음 노드가 이제 헤드
            }
            else{
                before->next = list->next; // 전노드가 이제 내 다음 노드를 가르킴
            }
            // 나머지 작업 수행
            hashTable[hashIndex].cnt--;
            free(list);
            flag = 1;
        }
        before = list; // 노드 바꿔주기 전에 저장
        list = list->next;
    }
    // flag의 값에 따라 출력 다르게 해줌
    if (flag == 1){ // 삭제가 되었다면
        printf("\n [ %d ] 이/가 삭제되었습니다. \n", key);
    }
    else{ // 키가 없어서 삭제가 안된 경우
        printf("\n [ %d ] 이/가 존재하지 않아 삭제하지 못했습니다.\n", key);
    }
}



void search(int key){
    int hashIndex = hashFunction(key);
    t_list * list = hashTable[hashIndex].head;
    int flag = 0;
    while (list != NULL)
    {
        if (list->key == key){
            flag = 1;
            break;
        }
        list = list->next;
    }
    if (flag == 1){ // 키를 찾았다면
        printf("\n 키는 [ %d ], 값은 [ %s ] 입니다. \n", list->key, list->value);
    }
    else{
        printf("\n 존재하지 않은 키는 찾을 수 없습니다. \n");
    }
}


void display(){
    // 반복자 선언
    t_list * iterator;
    printf("\n========= display start ========= \n");

    for (int i = 0; i<BUCKET_SIZE; i++){
        iterator = hashTable[i].head;
        printf("Bucket[%d] : ", i);
        while (iterator != NULL)
        {
            printf("(key : %d, val : %s)  -> ", iterator->key, iterator->value);
            iterator = iterator->next;
        }
        printf("\n");
    }
    printf("\n========= display complete ========= \n");
}