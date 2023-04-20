/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:02:47 by dpentlan          #+#    #+#             */
/*   Updated: 2022/11/28 12:02:49 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  *** ft_lstclear (42 list clear) ***
 *
 *  Deletes and frees the given node and every successor of the that node,
 *  using the function 'del' and free.
 *  Finally, the pointer to the list is set to NULL.
 *  Returns nothing.
 */

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next_node;

	if (lst == 0 || del == 0)
		return ;
	current = *lst;
	while (current)
	{
		del(current->content);
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*lst = 0;
}
