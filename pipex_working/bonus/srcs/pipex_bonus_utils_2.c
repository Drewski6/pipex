/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:57:46 by dpentlan          #+#    #+#             */
/*   Updated: 2023/05/12 18:57:59 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	px_init(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->pipe[0] = 0;
	pipex->pipe[1] = 0;
	pipex->prev_pipe = -1;
	pipex->com_num = 0;
	pipex->cmd_abspath = 0;
	pipex->cmd_args = 0;
	pipex->path_tab = 0;
	pipex->hd_limiter = 0;
	pipex->pid = 0;
	if (argc < 5)
		px_error(pipex, "args");
	if (!ft_strncmp(argv[1], "here_doc", 9))
		pipex->hd_limiter = argv[2];
	if (pipex->hd_limiter && argc < 6)
		px_error(pipex, "here_doc");
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->envp = envp;
	if (pipex->hd_limiter)
		pipex->temp_used = -1;
	else
		pipex->temp_used = access(pipex->argv[1], F_OK | R_OK);
	return (0);
}

void	px_re_init(t_pipex *pipex, unsigned char flags)
{
	if (pipex->cmd_abspath && flags & 0b00000001)
	{
		free(pipex->cmd_abspath);
		pipex->cmd_abspath = 0;
	}
	if (pipex->cmd_args && flags & 0b00000010)
	{
		ft_free_tab(pipex->cmd_args);
		pipex->cmd_args = 0;
	}
	if (pipex->path_tab && flags & 0b00000100)
	{
		ft_free_tab(pipex->path_tab);
		pipex->path_tab = 0;
	}
	if (pipex->pid && flags & 0b00001000)
	{
		ft_lstclear(&(pipex->pid), &ft_free_content);
		pipex->pid = 0;
	}
}

int	px_exec_args(t_pipex *pipex)
{
	px_get_execargs(pipex);
	px_get_abspath(pipex);
	return (0);
}

void	px_close_fds(t_pipex *pipex)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	if (pipex->prev_pipe != -1)
		close(pipex->prev_pipe);
}

void	px_heredoc(t_pipex *pipex)
{
	char	*stdin_line;
	int		here_doc;

	here_doc = open("/tmp/pipex", O_CREAT | O_RDWR, 0666);
	if (here_doc < 0)
		px_error(pipex, "open");
	while (1)
	{
		write(1, "heredoc> ", 9);
		stdin_line = get_next_line(0, 0);
		if (!stdin_line)
		{
			close(here_doc);
			px_error(pipex, "malloc");
		}
		if (!ft_strncmp(stdin_line, pipex->hd_limiter,
				ft_strlen(pipex->hd_limiter)))
			break ;
		ft_putstr_fd(stdin_line, here_doc);
		free(stdin_line);
	}
	free(stdin_line);
	get_next_line(0, 1);
	close(here_doc);
}
