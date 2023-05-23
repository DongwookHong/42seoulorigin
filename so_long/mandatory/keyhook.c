/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong < donghong@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:20:07 by donghong          #+#    #+#             */
/*   Updated: 2023/05/23 18:24:32 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_len(long n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		cnt++;
	while (n > 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;

	num = (long)n;
	len = ft_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len--] = '\0';
	if (num == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

void	writemove(t_map *map)
{
	char	*str;

	str = ft_itoa(map->cnt);
	write(1, "movement: ", 10);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	free(str);
}

int	key_press(int keycode, t_map *map)
{
	int	count;

	count = map->cnt;
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
	if (count != map->cnt)
		writemove(map);
	return (0);
}
