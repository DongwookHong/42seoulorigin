#include <unistd.h>

#include "pushswap.h"


void init_que(t_queue *q, int size)
{
    q-> front = 0;
    q-> rear = 0;
    q -> size = size;
    q-> data = (int *)malloc(sizeof(int )* size); 
}

int is_empty(t_queue *q)
{
    if(q -> front == q -> rear) return 1;
    else 
        return 0;
}
int is_full(t_queue *q) {

    if (((q->rear + 1) % (q->size)) == q->front) return 1;

    else return 0;

}

void enque(t_queue *q, int item){
    if(is_full(q)){
        printf("que is full");
        return;
    }
    else {
        q->rear = (q->rear +1) %(q->size);
        q ->data[q->rear] =item;
    }
    return ;
}

int deque(t_queue *q)
{
    if(is_empty(q)){
        printf("empty\n");
        return -1;
    }
    q -> front =(q ->front+1) % (q -> size);
    int item =  q-> data[q->front];
    return item;
}



int main(int argc, char **argv){

    t_queue *a;
    a  =(t_queue *)malloc(sizeof(t_queue));
    if(!a)
        return 0;
    init_que(a,10);
    enque(a,1);
    enque(a,2);
    enque(a,3);
    enque(a,4);
    enque(a,5);
    enque(a,7);
    enque(a,8);
    enque(a,9);
    for (int i =a-> front; i <= a->rear; i++)
    {
        printf("%d\n",a->data[i]);
    }

    printf("------------------\n");
    deque(a);
    deque(a);
    deque(a);

     for (int i =a->front; i <= a->rear; i++)
    {
        printf("%d\n",a->data[i]);
    }
}