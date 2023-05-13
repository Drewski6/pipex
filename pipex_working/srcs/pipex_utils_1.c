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
	{
		free(pipex->cmd_abspath);
		pipex->cmd_abspath = 0;
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
	px_close_fds(pipex);
	exit(EXIT_FAILURE);
}

int	px_error_nonfatal(t_pipex *pipex, char *err_message)
{
	if (pipex) {}
	perror(err_message);
	//if (pipex->cmd_abspath)
	//{
	//	free(pipex->cmd_abspath);
	//	pipex->cmd_abspath = 0;
	//}
	//if (pipex->cmd_args)
	//{
	//	ft_free_tab(pipex->cmd_args);
	//	pipex->cmd_args = 0;
	//}
	return (0);
}

int	ft_infile(t_pipex *pipex)
{
	int		in_file;

	in_file = 0;
	if (pipex->temp_used < 0)
	{
		perror(pipex->argv[1]);
		in_file = open("/tmp/pipex", O_CREAT | O_RDONLY, 0666);
		if (in_file < 0)
			px_error(pipex, "open");
		dup2(in_file, STDIN_FILENO);
		close(in_file);
		return (1);
	}
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
	char	*fn;

	out_file = 0;
	fn = pipex->argv[pipex->argc - 1];
	out_file = open(fn, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (out_file < 0)
		px_error(pipex, "open");
	dup2(out_file, STDOUT_FILENO);
	close(out_file);
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
