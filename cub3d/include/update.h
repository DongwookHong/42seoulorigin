#include "cube3d.h"

typedef struct s_monitor t_monitor;

typedef enum e_id
{
	invalid = -1,
	we,
	so,
	no,
	ea,
	f,
	c
}t_id;


typedef struct s_move{
	t_bool	w;
	t_bool	a;
	t_bool	s;
	t_bool	d;
	t_bool	left;
	t_bool	right;
}t_move;

typedef struct s_monitor
{
	void *mlx;
	void *win;
	t_move move;
} t_monitor;

typedef struct s_map
{

    char **down_map;
    char *elements[6];
    int width;
    int height;

} t_map;

