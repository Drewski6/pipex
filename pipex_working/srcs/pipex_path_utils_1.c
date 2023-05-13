/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 18:58:17 by dpentlan          #+#    #+#             */
/*   Updated: 2023/05/12 18:58:25 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
}

void	px_get_execargs(t_pipex *pipex)
{
	pipex->cmd_args = ft_split(pipex->argv[pipex->com_num], ' ');
	if (!pipex->cmd_args)
		px_error(pipex, "malloc");
}
