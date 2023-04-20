/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:48:08 by dpentlan          #+#    #+#             */
/*   Updated: 2022/11/28 11:48:10 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  *** ft_lstdelone (42 list delete one) ***
 *
 *  Takes as a parameter a node and frees the memory of the node's content using
 *  the function 'del' given as a parameter and free the node.
 *  The memory address 'next' is not freed.
 *  Returns nothing.
 */

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == 0 || del == 0)
		return ;
	del(lst->content);
	free(lst);
}
