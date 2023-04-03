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


#endif