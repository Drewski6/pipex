/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:57:04 by dpentlan          #+#    #+#             */
/*   Updated: 2023/05/19 13:57:43 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../../libft/includes/libft.h"
# include <unistd.h>
# include <sys/wait.h>
# include <error.h>

typedef struct s_pipex {
	int			pipe[2];
	int			argc;
	int			prev_pipe;
	int			com_num;
	int			temp_used;
	t_list		*pid;
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
int		px_infile(t_pipex *pipex);
int		px_outfile(t_pipex *pipex);
void	ft_free_tab(char **table);

//	pipex_utils_2.c
int		px_init(t_pipex *pipex, int argc, char **argv, char **envp);
void	px_re_init(t_pipex *pipex, unsigned char flags);
int		px_exec_args(t_pipex *pipex);
void	px_close_fds(t_pipex *pipex);

//	pipex_path_utils_1.c
void	px_path_tab_add_fw_slash(t_pipex *pipex);
void	px_get_path_tab(t_pipex *pipex);
void	px_build_abspath(t_pipex *pipex);
void	px_get_abspath(t_pipex *pipex);
void	px_get_execargs(t_pipex *pipex);

//	pipex_fork_utils_1.c
void	px_pre_exec_cleanup(t_pipex *pipex);
void	px_child_process(t_pipex *pipex);
void	px_fork_loop(t_pipex *pipex);

//	pipex_list_utils_1.c
void	px_wait(t_pipex *pipex);
void	px_add_pid(t_pipex *pipex);
void	ft_lstpop(t_list **lst, void (*del)(void *));
void	ft_free_content(void *content);
t_list	*ft_lstnew_pid(pid_t pid);

#endif
