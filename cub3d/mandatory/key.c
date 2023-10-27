#include "../include/cube3d.h"

int	exit_event_handler(int key_code, void *param)
{
	(void)key_code;
	(void)param;
	exit(0);
}

int	press_event_handler(int key_code, t_move *move)
{
	if (key_code == KEY_W)
		move->w = TRUE;
	if (key_code == KEY_S)
		move->s = TRUE;
	if (key_code == KEY_A)
		move->a = TRUE;
	if (key_code == KEY_D)
		move->d = TRUE;
	if (key_code == KEY_LEFT)
		move->left = TRUE;
	if (key_code == KEY_RIGHT)
		move->right = TRUE;
	if (key_code == KEY_ESC)
		exit(0);
	return (0);
}

int	release_event_handler(int key_code, t_move *move)
{
	if (key_code == KEY_W)
		move->w = FALSE;
	if (key_code == KEY_S)
		move->s = FALSE;
	if (key_code == KEY_A)
		move->a = FALSE;
	if (key_code == KEY_D)
		move->d = FALSE;
	if (key_code == KEY_LEFT)
		move->left = FALSE;
	if (key_code == KEY_RIGHT)
		move->right = FALSE;
	return (0);
}
