#include "pushswap.h"

void sa(t_queue *a){
    int temp;
    int front = a -> front;
        temp = a->data[front];
        a->data[front] = a-> data[front+1];
        a->data[front+1] = temp;

}

void pa(t_queue *a, t_queue *b)
{
    int temp ;
    temp = deque(a);
    enque(b,temp);
}
void pb(t_queue *a, t_queue *b)
{
    int temp ;
    temp = deque(b);
    enque(a,temp);
}

void sb(t_queue *a){
    int temp;
    int back = a -> rear;
    temp = a->data[back];
    a->data[back] = a-> data[back-1];
    a->data[back-1] = temp;
}

void    ra(t_queue *a)
{
	int	tmp;

	tmp = a->data[a->front];

	a->front = (a->front + 1) % a->size;
	a->rear = (a->rear + 1) % a->size;
	a->data[a->rear] = tmp;
}

void    rb(t_queue *a)
{
	int	tmp;

	tmp = a->data[a->front];

	a->front = (a->front + 1) % a->size;
	a->rear = (a->rear + 1) % a->size;
	a->data[a->rear] = tmp;
	
}


void rra(t_queue *a)
{
    int	tmp;

	tmp = a->data[a->rear];

	a->front = (a->front - 1) % a->size;
	a->rear = (a->rear -1 ) % a->size;
	a->data[a->front] = tmp;
}

void rrb(t_queue *a)
{
    int	tmp;

	tmp = a->data[a->rear];

	a->front = (a->front - 1) % a->size;
	a->rear = (a->rear -1 ) % a->size;
	a->data[a->front] = tmp;
}