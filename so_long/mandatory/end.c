/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:34:50 by donghong          #+#    #+#             */
/*   Updated: 2023/05/17 16:02:02 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(int flag)
{
	if (flag == 1)
	{
		write(1, "Error\n", 6);
		write(1, "Please check the map if it's correct\n", 37);
	}
	else if (flag == 2)
	{
		write(1, "Error\n", 6);
		write(1, "Map extension must end in .ber\n", 31);
	}
	else if (flag == 3)
	{
		write(1, "Error\n", 6);
		write(1, "Please check the file if it's correct\n", 38);
	}
	else if (flag == 4)
	{
		write(1, "Error\n", 6);
		write(1, "Check for memory failure\n", 25);
	}
	exit(1);
}

int	exit_e(void)
{
	exit(0);
	return (0);
}
