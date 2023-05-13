/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:56:25 by dpentlan          #+#    #+#             */
/*   Updated: 2023/04/29 16:03:05 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	t_pipex	s_pipex;

	pipex = &s_pipex;
	ft_px_init(pipex, argc, argv, envp);
	px_fork_loop(pipex);
	if (pipex->temp_used == -1)
		unlink("/tmp/pipex");
	if (pipex->path_tab)
	{
		ft_free_tab(pipex->path_tab);
		pipex->path_tab = 0;
	}
	px_close_fds(pipex);
	return (0);
}
