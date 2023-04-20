/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:39:37 by dpentlan          #+#    #+#             */
/*   Updated: 2022/11/14 14:39:38 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  *** ft_strnstr (42 string n string) ***
 *
 *  Takes a big string 'big' and a little string 'little' and size_t 'len'.
 *  Searches through 'big' for the first occurance of 'little' substring.
 *  Searches max 'len' number of bytes.
 *  Returns address of first instance of 'little' in 'big'.
 *  Returns 0 if no match found.
 */

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == 0 || big == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] != 0)
		{
			j++;
		}
		if (little[j] == 0 && i + j <= len)
			return ((char *)big + i);
		i++;
	}
	return (0);
}
