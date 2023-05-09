/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:56:25 by dpentlan          #+#    #+#             */
/*   Updated: 2023/04/29 16:03:05 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc < 5)
		return (px_error(), 1);
	pipex = (t_pipex *)malloc(1 * sizeof(t_pipex));
	if (!pipex)
		return (1);
	if (pipe(pipex->fds))
		return (free(pipex), 1);

	// Not how youre supposed to do this.
	if (px_access_check(argc, argv, envp))
		return (1);

	pipex->pid1 = fork();
	if (pipex->pid1 == 0)
	{
		char *args[] = {"/usr/bin/ping", "ping", "-c", "1", "google.com", NULL};
		ft_printf("checking %s: result %d\n", args[0], access(args[0], F_OK | X_OK));
		dup2(pipex->fds[1], STDOUT_FILENO);
		close(pipex->fds[0]);
		close(pipex->fds[1]);
		execve(args[0], args + 1, NULL);
	}
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
	{
		char *args[] = {"/usr/bin/grep", "grep", "rtt", NULL};
		ft_printf("checking %s: result %d\n", args[0], access(args[0], F_OK | X_OK));
		dup2(pipex->fds[0], STDIN_FILENO);
		dup2(pipex->fds[1], STDOUT_FILENO);
		close(pipex->fds[0]);
		close(pipex->fds[1]);
		execve(args[0], args + 1, NULL);
	}

	close(pipex->fds[0]);
	close(pipex->fds[1]);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	free(pipex);
	return (0);
}
