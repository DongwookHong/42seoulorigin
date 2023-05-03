#include <so_long.h>

void key_init(t_key *key)
{
    key ->x = 0;
    key ->y = 0;
}


int set_keyboard(int click, t_key *key)
{
    if (click == KEY_W)
        key ->y++;
    else if(click ==KEY_S)
        key-> y--;
    else if(click ==KEY_D)
        key-> x++;
    else if(click ==KEY_A)
        key-> x--;
    else if(click ==KEY_ESC)
        exit(0);
    else
        return (0); 
}