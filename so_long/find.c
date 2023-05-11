#include "so_long.h"



int	find_p(t_map *map)
{
	int	i;
    int j;
    int flag =0;
	i = 0;
	while (i < map->height)
	{   
        j =0;
        while (j < map->width)
        {
		    if (map->map_down[i][j] == 'P')
            {
			    map->p[0]=i;
                map->p[1]=j;
                flag =1;
                break;
            }
            j++;
        }
        i++;
	}
    return flag;
}

int	find_e(t_map *map)
{
	int	i;

	i = 0;
    int flag =0;
    int j;
	while (i < map->height)
	{    
        j =0;
        while (j < map->width)
        {
		    if (map->map_down[i][j] == 'E')
            {
			    map->e[0]=i;
                map->e[1]=j;
                flag= 1;
                break;
            }
            j++;
        }
        i++;
	}
    return flag;
}


int	find_c(t_map *map)
{
	int	i;

	i = 0;
    int j;
    int cnt =0;
	while (i < map->height)
	{   
        j=0;
        while (j < map->width)
        {
		    if (map->map_down[i][j] == 'C')
            {
               cnt++;
            }
            j++;
        }
        i++;
	}
    map -> c = cnt;
    return cnt;
}

void find(t_map *map)
{
    int character;
    int exit;
    int obstacle;

    obstacle =find_c(map);
    exit=find_e(map);
    character =find_p(map);

    if ( obstacle < 1 || exit == 0 || character ==0 )
    {
        error();
        return ;
    }
}