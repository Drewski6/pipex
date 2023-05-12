/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:57:04 by dpentlan          #+#    #+#             */
/*   Updated: 2023/04/20 12:57:37 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <sys/wait.h>
# include <error.h>

typedef struct	s_pipex {
	int 		fds[2];
	pid_t		pid;
	int			argc;
	char		**argv;
	char		**envp;
	char		*cmd_abspath;
	char		**cmd_args;
	char		**path_tab;
}				t_pipex;

//	pipex.c
//	int main (int argc, char **argv, char **envp);

//	pipex_utils_1.c
int		px_error(t_pipex *pipex, char *err_message);
int 	px_err_args(void);
int		px_err_malloc(t_pipex *pipex);
int		ft_infile(t_pipex *pipex);
int		ft_outfile(t_pipex *pipex);
int		ft_px_init(t_pipex *pipex, int argc, char **argv, char **envp);
void	ft_free_tab(char **table);
int		px_exec_args(t_pipex *pipex);
void	px_close_fds(t_pipex *pipex);

#endif
