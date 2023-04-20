/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:26:39 by dpentlan          #+#    #+#             */
/*   Updated: 2022/11/28 11:26:49 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  *** ft_lstadd_back (42 list add back) ***
 *
 *  Adds the node 'new' at the end of the list.
 *  Returns nothing.
 */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = 0;
	current = ft_lstlast(*lst);
	if (!current)
		*lst = new;
	else
		current->next = new;
}
