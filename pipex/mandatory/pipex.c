/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:04:00 by donghong          #+#    #+#             */
/*   Updated: 2023/06/12 21:17:24 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_base	base;

	if (ac != 5)
		error("Check arguments");
	init_pipex(ac, av, &base);
	ft_path(envp, &base);
	execute(&base, av, envp);
	return (0);
}
