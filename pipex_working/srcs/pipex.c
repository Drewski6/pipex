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
	int		in_file;
	int		out_file;

	if (envp) {}
	in_file = 0;
	out_file = 0;
	if (argc < 5)
		return (px_err_args(), 1);
	pipex = (t_pipex *)malloc(1 * sizeof(t_pipex));
	if (!pipex)
		return (1);
	if (pipe(pipex->fds))
		return (free(pipex), 1);

//	need to put file into stdin at first. access and all that to error check.
	in_file = open(argv[1], O_RDONLY);
	if (in_file < 0)
		px_error("open");
	dup2(in_file, STDIN_FILENO);
	close(in_file);

	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		px_error("fork");
	else if (pipex->pid1 == 0)
	{
		char *args[] = {"/usr/bin/cat", "cat", NULL};
		dup2(pipex->fds[1], STDOUT_FILENO);
		close(pipex->fds[0]);
		close(pipex->fds[1]);
		execve(args[0], args + 1, NULL);
	}
	waitpid(pipex->pid1, NULL, 0);

	out_file = open(argv[4], O_CREAT | O_WRONLY, 0666);
	if (out_file < 0)
		px_error("open");
	dup2(out_file, STDOUT_FILENO);
	close(out_file);


	pipex->pid2 = fork();
	if (pipex->pid1 < 0)
		px_error("fork");
	if (pipex->pid2 == 0)
	{
		char *args[] = {"/usr/bin/wc", "wc", "-l", NULL};
		dup2(pipex->fds[0], STDIN_FILENO);
		close(pipex->fds[0]);
		close(pipex->fds[1]);
		execve(args[0], args + 1, NULL);
	}

	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	close(pipex->fds[0]);
	close(pipex->fds[1]);
	waitpid(pipex->pid2, NULL, 0);

	free(pipex);
	return (0);
}
