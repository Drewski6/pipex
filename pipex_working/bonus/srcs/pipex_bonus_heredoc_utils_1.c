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

void	px_wait(t_pipex *pipex)
{
	while (pipex->pid)
	{
		waitpid(*(pid_t *)(ft_lstlast(pipex->pid)->content), NULL, 0);
		ft_lstpop(&(pipex->pid), &ft_free_content);
	}
}

void	ft_lstpop(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	if (!lst || !del)
		return ;
	current = *lst;
	if (!current)
		return ;
	if (!current->next)
	{
		del(current->content);
		free(current);
		*lst = 0;
		return ;
	}
	while (current->next->next)
		current = current->next;
	del(current->next->content);
	current->next->content = 0;
	free(current->next);
	current->next = 0;
	return ;
}

void	ft_free_content(void *content)
{
	free(content);
}

t_list	*ft_lstnew_pid(pid_t pid)
{
	t_list	*new;

	new = (t_list *)malloc(1 * sizeof(t_list));
	if (!new)
		return (0);
	new->content = (pid_t *)malloc(1 * sizeof(pid_t));
	if (!new->content)
		return (0);
	*(pid_t *)(new->content) = pid;
	new->next = NULL;
	return (new);
}
