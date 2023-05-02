#include <so_long.h>

void key_init(t_key *key)
{
    key ->x = 0;
    key ->y = 0;
}


int set_keyboard(int click, t_key *key)
{
    if (click == 1)
        key ->y++;
    else if(click ==2)
        key-> y--;
    else if(click ==3)
        key-> x++;
    else if(click ==4)
        key-> x--;
    else if(click ==5)
        exit(0);
    else
        return (0); 
}