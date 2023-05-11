#include "so_long.h"


void square_check(t_map map)
{
   int base= ft_strlen(map.map_down[0]);
   int i =0;
   int j;
    int len =0;
    while(i < map.height-1)
    {
        len = ft_strlen(map.map_down[i]);
        // printf("%d\n",len);
        if(base != len)
        {
            error();
            return;
        }
        i++;
    }
    if(i ==map.height-1)
    {
        len = ft_strlen(map.map_down[i]);
        if(base-1 != len)
         {
            error();
            return;
        }
    }
}


void surround(t_map map)
{
    int i =0; 
    int j;

    while (i<map.height)
    {
        j=0;
        while (j < map.width)
        {
            if (i == 0 || i == map.height-1 || j==0 || j == map.width-1)
            {
                if(map.map_down[i][j] != '1')
                {
                    error();
                    exit(1);
                }
            }
            j++;
        }
        i++;
    }
}

void map_check(t_map map)
{
    square_check(map);
    surround(map);
}