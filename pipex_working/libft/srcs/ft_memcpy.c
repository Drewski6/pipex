/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:57:55 by dpentlan          #+#    #+#             */
/*   Updated: 2022/11/11 12:57:56 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  *** ft_memcpy (42 memory copy) ***
 *
 *  Takes a destination pointer 'dest', a source pointer 'src',
 *  and a size_t 'len'.
 *  Copies byte by byte starting from memory address 'src' to memory address
 *  'dest' for 'len' number of bytes.
 *  Returns pointer to beginning of 'dest'.
 */

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dest == 0 && src == 0)
		return (0);
	while (i < len)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	return (dest);
}
