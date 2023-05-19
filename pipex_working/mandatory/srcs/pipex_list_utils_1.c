/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_list_utils_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 23:46:23 by dpentlan          #+#    #+#             */
/*   Updated: 2023/05/19 14:00:28 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	px_wait(t_pipex *pipex)
{
	while (pipex->pid)
	{
		waitpid(*(pid_t *)(ft_lstlast(pipex->pid)->content), NULL, 0);
		ft_lstpop(&(pipex->pid), &ft_free_content);
	}
}

void	px_add_pid(t_pipex *pipex)
{
	t_list	*new_node;

	new_node = 0;
	new_node = ft_lstnew_pid(fork());
	if (!new_node)
		px_error(pipex, "malloc");
	ft_lstadd_back(&(pipex->pid), new_node);
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
