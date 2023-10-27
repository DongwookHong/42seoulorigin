#include "../include/cube3d.h"

int main(int ac , char **av)
{
	t_monitor monitor;
	if (ac !=2)
		exit(1);
	setting_mlx(&monitor);
	init_map(av[1]);
}