#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct s_queue{
    int     *data;
    int     size;
    int     rear;
    int     front;
}t_queue;

void sa(t_queue *a);
void ra(t_queue *a);
void rra(t_queue *a);
void pa(t_queue *a, t_queue *b);
void pb(t_queue *a, t_queue *b);
int deque(t_queue *q);
void enque(t_queue *q, int item);
#endif