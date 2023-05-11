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

int	px_error(char *err_message)
{
	perror(err_message);
	exit(EXIT_FAILURE);
}

int px_err_args(void)
{
	ft_putstr_fd("Usage: pipex [infile] ['command'] ... [outfile]\n", 1);
	exit(EXIT_FAILURE);
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

char	*px_add_abs_path(char *command, char **envp)
{
	char	**path_tab;
	char	**path_tab_start;
	char	*path;
	char	*full_path;
	char	*fuller_path;

	full_path = 0;
	fuller_path = 0;
	path = 0;
	path_tab = 0;
	path = px_get_path(envp);
	if (!path)
		return (0);
	path = path + 5;
	path_tab = ft_split(path, ':');
	if (!path_tab)
		return (0);
	path_tab_start = path_tab;
	while (*path_tab)
	{
		full_path = ft_strjoin(*path_tab, "/");
		if (!full_path)
		{
			ft_free_tab(path_tab_start);
			return (0);
		}
		fuller_path = ft_strjoin(full_path, command);
		free(full_path);
		//ft_printf("fuller_path = %s\n", fuller_path);
		if (!fuller_path)
		{
			ft_free_tab(path_tab_start);
			return (0);
		}
		if (!access(fuller_path, F_OK | X_OK))
		{
			ft_free_tab(path_tab_start);
			return (fuller_path);
		}
		free(fuller_path);
		path_tab++;
	}
	ft_free_tab(path_tab_start);
	//ft_printf("bruhhhh.\n");
	return (0);
}

char	*px_env_check(int com, char **argv, char **envp)
{
	char	**buf_table;
	char	*full_path;

	full_path = 0;
	buf_table = ft_split(argv[com], ' ');
	if (!buf_table || !buf_table[0])
		return (0);
	//ft_printf("%s\n", buf_table[0]);
	if (buf_table[0][0] != '/')
		full_path = px_add_abs_path(buf_table[0], envp);
	ft_free_tab(buf_table);
	return (full_path);
}

int	px_access_check(int argc, char **argv, char **envp)
{
	int		i;
	char	*full_path;

	i = 2;
	if (access(argv[1], F_OK | W_OK))
		return (-1);
	if (access(argv[argc - 1], F_OK | W_OK))
		return (-1);
	while (i < argc - 1)
	{
		full_path = px_env_check(i, argv, envp);
		if (!full_path)
		{
			free(full_path);
			return (-1);
		}
		free(full_path);
		i++;
	}
	return (0);
}

