/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:58:28 by dpentlan          #+#    #+#             */
/*   Updated: 2022/11/11 12:58:38 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  *** ft_memset (42 memory set) ***
 *
 *  Takes a character pointer 'str', an integer 'c', and a size_t 'len'.
 *  Sets 'len' number of memory addresses to value of 'c'.
 *  Returns a pointer to 'str'.
 */

void	*ft_memset(void *str, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(char *)(str + i) = (unsigned char)c;
		i++;
	}
	return (str);
}
