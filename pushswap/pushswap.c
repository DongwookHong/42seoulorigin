#include <unistd.h>
#include <string.h>
#include "pushswap.h"

void init_que(t_queue *q)
{
    q-> front = 0;
    q-> rear = 0;
    q -> size = 500;
    q-> data = (int *)malloc(sizeof(int )* q->size);
    memset(q->data, 0, sizeof(int) * q->size);
}

int is_empty(t_queue *q)
{
    if(q -> front == q -> rear+1) return 1;
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
    else{
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

void	check_parsing(t_queue *a, char **argv)
{
	int			i=1;

	int			idx =0;
	int         put;

	
}


int main(int argc, char **argv){

    t_queue *a;
    
    a  =(t_queue *)malloc(sizeof(t_queue));  
    init_que(a);
    int i =1;
    int put;
    int idx =0;
   while (argv[i])
	{
		int j = 0;
		while (argv[i][j])
		{
			put = atoi(&argv[i][j]);
			a->data[idx++] = (int)put;
            enque(a,a->data[idx]);
            j++;
		}
		i++;
	}

    for (int i =a->front; i <= a->rear; i++)
    {
        printf("%d\n",a->data[i]);
    }
    
}