/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:56:25 by dpentlan          #+#    #+#             */
/*   Updated: 2023/05/19 13:59:36 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	t_pipex	s_pipex;

	pipex = &s_pipex;
	px_init(pipex, argc, argv, envp);
	px_fork_loop(pipex);
	if (pipex->temp_used == -1)
		unlink("/tmp/pipex");
	px_wait(pipex);
	px_re_init(pipex, 0b00000100);
	px_close_fds(pipex);
	return (0);
}
