/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:03:16 by dpentlan          #+#    #+#             */
/*   Updated: 2022/11/28 12:03:17 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  *** ft_lstmap (42 list map) ***
 *
 *  Iterates the list 'lst' and applies the function 'f' on the content of
 *  each node. Creates a new list resulting of the successive applications of
 *  the function 'f'. The 'del' function is used to delete the content of the 
 *  node if needed.
 *  Returns a pointer to first element in the new list.
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node_new;
	t_list	*first_new;

	first_new = 0;
	node_new = 0;
	while (lst)
	{
		node_new = ft_lstnew(f(lst->content));
		if (!node_new)
		{
			ft_lstclear(&first_new, del);
			return (0);
		}
		ft_lstadd_back(&first_new, node_new);
		lst = lst->next;
	}
	return (first_new);
}
