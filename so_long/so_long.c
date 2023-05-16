#include "so_long.h"
void leaks()
{
	system("leaks a.out");
}
int main(int ac, char **av)
{
	t_map map;

	// atexit(leaks);
	initialize_map(&map);
	setting(ac,av,&map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.width * 50,map.height * 50, "map");
	show_map(&map, 0, 0);
	mlx_hook(map.win, X_EVENT_KEY_RELEASE, 0, &key_press, &map);
	mlx_loop(map.mlx);
    return (0);
}



