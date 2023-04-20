/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:58:12 by dpentlan          #+#    #+#             */
/*   Updated: 2022/11/14 10:58:16 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  *** ft_memchr (42 memory character) ***
 *
 *  Takes a pointer 's', an integer 'c' and size_t 'n'.
 *  Checks 'n' number of bytes for character 'c'.
 *  Returns address of first found byte that matches 'c'.
 *  If none is found, returns 0.
 */

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return (((unsigned char *)s + i));
		i++;
	}
	return (0);
}
