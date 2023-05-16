/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_heredoc_utils_1.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:46:23 by dpentlan          #+#    #+#             */
/*   Updated: 2023/05/13 23:46:35 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	px_heredoc(t_pipex *pipex)
{
	char	*stdin_line;
	int		here_doc;

	here_doc = open("/tmp/pipex", O_CREAT | O_RDWR, 0666);
	if (here_doc < 0)
		px_error(pipex, "open");
	while (1)
	{
		write(1, "heredoc> ", 9);
		stdin_line = get_next_line(0, 0);
		if (!stdin_line)
		{
			close(here_doc);
			px_error(pipex, "malloc");
		}
		if (!ft_strncmp(stdin_line, pipex->hd_limiter,
				ft_strlen(pipex->hd_limiter)))
			break ;
		ft_putstr_fd(stdin_line, here_doc);
		free(stdin_line);
	}
	free(stdin_line);
	get_next_line(0, 1);
	close(here_doc);
}
