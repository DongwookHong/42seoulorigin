/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghong <donghong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:04:00 by donghong          #+#    #+#             */
/*   Updated: 2023/06/13 18:29:45 by donghong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_base	base;

	if (ac != 5)
		file_error("Check arguments");
	init_pipex(ac, av, &base);
	ft_path(envp, &base);
	execute(&base, av, envp);
	return (0);
}
