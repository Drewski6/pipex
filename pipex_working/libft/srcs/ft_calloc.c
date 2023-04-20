/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:57:36 by dpentlan          #+#    #+#             */
/*   Updated: 2022/11/17 10:57:39 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  *** ft_calloc (42 contiguous allocation) ***
 *
 *  Takes a size_t 'nmemb' (number of members) and a size_t 'size' (member size).
 *  Allocates memory for the product of 'nmemb' and 'size'
 *  and initializes all memory to 0.
 *  Returns freeable pointer to 1 NULL byte if 'nmemb' or 'size' is 0.
 *  Returns address to allocated memory space.
 */

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pvoid;
	char	*pchar;

	if (nmemb == 0 || size == 0)
	{
		pchar = malloc(sizeof(char));
		if (!pchar)
			return (0);
		pchar[0] = 0;
		return (pchar);
	}
	if (nmemb > SIZE_MAX / size)
		return (0);
	pvoid = malloc(nmemb * size);
	if (pvoid)
		ft_bzero (pvoid, nmemb * size);
	return (pvoid);
}
