/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_fork_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:58:31 by dpentlan          #+#    #+#             */
/*   Updated: 2023/05/12 18:58:40 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	px_child_process(t_pipex *pipex, int fork_type)
{
	if (fork_type == 0)
		dup2(pipex->fds[1], STDOUT_FILENO);
	if (fork_type == 1)
		dup2(pipex->fds[0], STDIN_FILENO);
	close(pipex->fds[0]);
	close(pipex->fds[1]);
	execve(pipex->cmd_abspath, pipex->cmd_args, NULL);
}

/*
 *	fork_type 0 = in_fork (takes input from stdin)
 *
 */

int	px_fork(t_pipex *pipex, int fork_type)
{
	px_exec_args(pipex);
	pipex->pid = fork();
	if (pipex->pid < 0)
		px_error(pipex, "fork");
	else if (pipex->pid == 0)
		px_child_process(pipex, fork_type);
	close(pipex->fds[1]);
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
	return (0);
}
