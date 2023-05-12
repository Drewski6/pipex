/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:20:54 by dpentlan          #+#    #+#             */
/*   Updated: 2023/05/09 15:31:54 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	px_error(t_pipex *pipex, char *err_message)
{
	if (pipex->cmd_args)
		ft_free_tab(pipex->cmd_args);
	perror(err_message);
	px_close_fds(pipex);
	exit(EXIT_FAILURE);
}

int px_err_args(void)
{
	ft_putstr_fd("Usage: pipex [infile] ['command'] ... [outfile]\n", 1);
	exit(EXIT_FAILURE);
}

int	ft_infile(t_pipex *pipex)
{
	int		in_file;

	in_file = 0;
	if (access(pipex->argv[1], F_OK | R_OK))
		px_error(pipex, "access");
	in_file = open(pipex->argv[1], O_RDONLY);
	if (in_file < 0)
		px_error(pipex, "open");
	dup2(in_file, STDIN_FILENO);
	close(in_file);
	return (0);
}

int	ft_outfile(t_pipex *pipex)
{
	int		out_file;

	out_file = 0;
	out_file = open(pipex->argv[pipex->argc - 1], O_CREAT | O_WRONLY, 0666);
	if (out_file < 0)
		px_error(pipex, "open");
	dup2(out_file, STDOUT_FILENO);
	close(out_file);
	return (0);
}

int	ft_px_init(t_pipex *pipex, int argc, char **argv, char **envp)
{
	if (argc < 5)
		return (px_err_args(), 1);
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->envp = envp;
	return (0);
}

void	ft_free_tab(char **table)
{
	int	i;

	i = 0;
	while (table[i])
	{
		free(table[i]);
		i++;
	}
	free(table);
	return ;
}

char	*px_get_path(char **envp)
{
	char	*path;

	path = 0;
	while (*envp)
	{
		path = ft_strnstr(*envp, "PATH=", 5);
		if (path)
			return (path);
		envp++;
	}
	return (0);
}

void	px_get_execargs(t_pipex *pipex, int com_num)
{
	pipex->cmd_args = ft_split(pipex->argv[com_num], ' ');
	if (!pipex->cmd_args)
		px_error(pipex, "malloc");
}

void	px_get_abspath(t_pipex *pipex)
{
	if (pipex->cmd_args[0][0] == '/')
		pipex->cmd_abspath = pipex->cmd_args[0];
	else
	{

	}
	if (access(pipex->cmd_abspath, F_OK | X_OK))	
		px_error(pipex, "access");
}

int	px_exec_args(t_pipex *pipex)
{
	static int	com_num;

	if (pipex) {}
	if (com_num == 0)
		com_num = 2;
	else
		com_num++;
	px_get_execargs(pipex, com_num);
	//ft_printf("pipex->cmd_args[0] = %s\n", pipex->cmd_args[0]);
	px_get_abspath(pipex);
	return (0);
}

void	px_close_fds(t_pipex *pipex)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	close(pipex->fds[0]);
	close(pipex->fds[1]);
}
