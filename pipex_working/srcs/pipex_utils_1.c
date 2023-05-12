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
	if (ft_strnstr(err_message, "args", 4))
		ft_putstr_fd("Usage: pipex [infile] ['command'] ... [outfile]\n", 1);
	else if (ft_strnstr(err_message, "no_path", 7))
		ft_putstr_fd("path: No valid path found in envp\n", 1);
	else
		perror(err_message);
	if (pipex->cmd_abspath)
		free(pipex->cmd_abspath);
	if (pipex->cmd_args)
		ft_free_tab(pipex->cmd_args);
	if (pipex->path_tab)
		ft_free_tab(pipex->path_tab);
	px_close_fds(pipex);
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
	out_file = open(pipex->argv[pipex->argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (out_file < 0)
		px_error(pipex, "open");
	dup2(out_file, STDOUT_FILENO);
	close(out_file);
	return (0);
}

int	ft_px_init(t_pipex *pipex, int argc, char **argv, char **envp)
{
	if (argc < 5)
		px_error(pipex, "args");
	pipex->argc = argc;
	pipex->argv = argv;
	pipex->envp = envp;
	pipex->cmd_abspath = 0;
	pipex->cmd_args = 0;
	pipex->path_tab = 0;
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

void	px_path_tab_add_fw_slash(t_pipex *pipex)
{
	int		i;
	char	*buf;

	i = 0;
	buf = 0;
	while (pipex->path_tab[i])
	{
		if (pipex->path_tab[i][ft_strlen(pipex->path_tab[i]) - 1] != '/')
		{
			buf = ft_strjoin(pipex->path_tab[i], "/");
			free(pipex->path_tab[i]);
			pipex->path_tab[i] = buf;
			if (!pipex->path_tab[i])
				px_error(pipex, "malloc");
		}
		i++;
	}
}

void	px_get_path_tab(t_pipex *pipex)
{
	char	*path;
	char	**env_elem;

	path = 0;
	env_elem = pipex->envp;
	while (*env_elem)
	{
		path = ft_strnstr(*env_elem, "PATH=", 5);
		if (path)
			break ;
		env_elem++;
	}
	if (!*env_elem)
		px_error(pipex, "no_path");
	pipex->path_tab = ft_split(path + 5, ':');
	if (!pipex->path_tab)
		px_error(pipex, "malloc");
	px_path_tab_add_fw_slash(pipex);
}

void	px_build_abspath(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->path_tab[i])
	{
		if (pipex->cmd_abspath)
			free(pipex->cmd_abspath);
		pipex->cmd_abspath = ft_strjoin(pipex->path_tab[i], pipex->cmd_args[0]);
		if (!pipex->cmd_abspath)
			px_error(pipex, "malloc");
		if (!access(pipex->cmd_abspath, F_OK | X_OK))
			break ;
		i++;
	}
}

void	px_get_abspath(t_pipex *pipex)
{
	if (pipex->cmd_args[0][0] == '/')
	{
		pipex->cmd_abspath = ft_strdup(pipex->cmd_args[0]);
		if (!pipex->cmd_abspath)
			px_error(pipex, "malloc");
	}
	else
	{
		if (!pipex->path_tab)
			px_get_path_tab(pipex);
		px_build_abspath(pipex);
	}
	if (access(pipex->cmd_abspath, F_OK | X_OK))	
		px_error(pipex, "access");
}

void	px_get_execargs(t_pipex *pipex, int com_num)
{
	pipex->cmd_args = ft_split(pipex->argv[com_num], ' ');
	if (!pipex->cmd_args)
		px_error(pipex, "malloc");
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
