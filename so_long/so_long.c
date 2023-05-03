#include "so_long.h"

void key_init(t_key *key)
{
    key ->row = 0;
    key ->col = 0;
}
int				key_press(int keycode, t_key *move)
{
	static int a = 0;

	if (keycode == KEY_W)
		move->col++;
	else if (keycode == KEY_S)
		move->col--;
	else if (keycode == KEY_D)
		move->row++;
	else if (keycode == KEY_A)
		move->row--;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %d, y: %d\n", move->row, move->col);
	return (0);
}

char * read_map(int fd)
{
	
}

int			main(int ac , char **av)
{
	t_game game;
	int fd; 

	fd = open (av[1],O_RDONLY);
	
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 500, 500, "my_mlx");
	mlx_loop(game.mlx);
	return (0);
}