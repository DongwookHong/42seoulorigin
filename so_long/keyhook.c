#include "so_long.h"

void	key_init(t_map *map)
{
	t_key *move;

	move = (t_key *)malloc(sizeof(t_key));
	if (move == NULL)
	{
		exit(1);
	}
	move->row = map->p[0];
	move->col = map->p[1];
	map->move = move;
}

int				key_press(int keycode, t_map *map)
{
	int cnt;
	if (keycode == KEY_W)
		move_w(map);
	else if (keycode == KEY_S)
		move_s(map);
	else if (keycode == KEY_D)
		move_d(map);
	else if (keycode == KEY_A)
		move_a(map);
	else if (keycode == KEY_ESC)
		exit(0);
	cnt++;
	// writemove(cnt);
	return (0);
}
