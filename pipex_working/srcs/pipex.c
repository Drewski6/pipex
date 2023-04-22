/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:56:25 by dpentlan          #+#    #+#             */
/*   Updated: 2023/04/20 12:56:37 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		ret;

	if (argc) {}
	if (argv) {}
	if (envp) {}

	ret = 1;
	pid = fork();
	ft_printf("pid = %d\n", pid);

	if (pid != 0)
	{
		ft_printf("waiting: %d\n", pid);
		wait(NULL);
		if (ret < 0)
			return (1);
		ft_printf("waiting over: %d\n", pid);
	}
	
	if (pid == 0)
		ft_printf("Hey! I'm the child! %d\n", pid);
	if (pid != 0)
		ft_printf("Hey! I'm the parent! %d\n", pid);

	return (0);
}
