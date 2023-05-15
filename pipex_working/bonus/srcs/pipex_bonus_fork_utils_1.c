/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_fork_utils_1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:58:31 by dpentlan          #+#    #+#             */
/*   Updated: 2023/05/12 18:58:40 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	px_pre_exec_cleanup(t_pipex *pipex)
{
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	if (pipex->prev_pipe != -1)
		close(pipex->prev_pipe);
	if (!pipex->cmd_abspath)
	{
		px_close_fds(pipex);
		exit(EXIT_FAILURE);
	}
}

void	px_child_process(t_pipex *pipex)
{
	px_exec_args(pipex);
	if (access(pipex->cmd_abspath, F_OK | X_OK))
		px_error(pipex, pipex->cmd_args[0]);
	if ((!pipex->hd_limiter && pipex->com_num == 2)
	|| (pipex->hd_limiter && pipex->com_num == 4))
	{
		px_infile(pipex);
		dup2(pipex->pipe[1], STDOUT_FILENO);
	}
	else if (pipex->com_num != pipex->argc - 2)
	{
		dup2(pipex->prev_pipe, STDIN_FILENO);
		dup2(pipex->pipe[1], STDOUT_FILENO);
	}
	else if (pipex->com_num == pipex->argc - 2)
	{
		px_outfile(pipex);
		dup2(pipex->prev_pipe, STDIN_FILENO);
	}
	px_pre_exec_cleanup(pipex);
	execve(pipex->cmd_abspath, pipex->cmd_args, pipex->envp);
}

void	px_fork_loop(t_pipex *pipex)
{
	if (pipex->hd_limiter)
		pipex->com_num = 4;
	else
		pipex->com_num = 2;
	while (pipex->com_num < pipex->argc - 1)
	{
		if (pipe(pipex->pipe))
			px_error(pipex, "pipe");
		pipex->pid = fork();
		if (pipex->pid < 0)
			px_error(pipex, "fork");
		if (pipex->pid == 0)
			px_child_process(pipex);
		else
		{
			close(pipex->pipe[1]);
			if (pipex->prev_pipe != -1)
				close(pipex->prev_pipe);
			pipex->prev_pipe = pipex->pipe[0];
		}
		pipex->com_num++;
		waitpid(pipex->pid, NULL, 0);
	}
}
