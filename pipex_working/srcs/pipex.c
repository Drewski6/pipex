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
	if (pipe(pipex->fds))
		px_error(pipex, "pipe");
	ft_infile(pipex);

// fork loop start here //
	px_exec_args(pipex);
	pipex->pid = fork();
	if (pipex->pid < 0)
		px_error(pipex, "fork");
	else if (pipex->pid == 0)
	{
		dup2(pipex->fds[1], STDOUT_FILENO);
		close(pipex->fds[0]);
		close(pipex->fds[1]);
		execve(pipex->cmd_abspath, pipex->cmd_args, NULL);
	}
	waitpid(pipex->pid, NULL, 0);
	if (pipex->cmd_args)
	{
		ft_free_tab(pipex->cmd_args);
		pipex->cmd_args = 0;
	}
	if (pipex->cmd_abspath)
	{
		free(pipex->cmd_abspath);
		pipex->cmd_abspath = 0;
	}
// fork loop end here //

	ft_outfile(pipex);

	px_exec_args(pipex);
	pipex->pid = fork();
	if (pipex->pid < 0)
		px_error(pipex, "fork");
	if (pipex->pid == 0)
	{
		dup2(pipex->fds[0], STDIN_FILENO);
		close(pipex->fds[0]);
		close(pipex->fds[1]);
		execve(pipex->cmd_abspath, pipex->cmd_args, NULL);
	}
	if (pipex->cmd_args)
	{
		ft_free_tab(pipex->cmd_args);
		pipex->cmd_args = 0;
	}
	if (pipex->path_tab)
	{
		ft_free_tab(pipex->path_tab);
		pipex->path_tab = 0;
	}
	if (pipex->cmd_abspath)
	{
		free(pipex->cmd_abspath);
		pipex->cmd_abspath = 0;
	}

	px_close_fds(pipex);
	waitpid(pipex->pid, NULL, 0);
	return (0);
}
