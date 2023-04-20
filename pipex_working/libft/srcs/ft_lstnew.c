/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:00:36 by dpentlan          #+#    #+#             */
/*   Updated: 2022/11/26 23:00:42 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  *** ft_lstnew (42 list new) ***
 *
 *  Allocates and returns a new node. The member variable 'content' is
 *  initialized with the value of the parameter 'content'. The variable 'next'
 *  is initialized to NULL.
 *  Returns 0 if allocation unsuccessful.
 *  Returns pointer to new list head if successful.
 */

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(1 * sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}
