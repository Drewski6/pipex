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
	pid_t		pid1;
	pid_t		pid2;
}				t_pipex;

//	pipex.c
//	int main (int argc, char **argv, char **envp);

//	pipex_utils_1.c
int		px_error(char *err_message);
int 	px_err_args(void);
void	ft_free_tab(char **table);
char	*px_env_check(int com, char **argv, char **envp);
int		px_access_check(int argc, char **argv, char **envp);


#endif
