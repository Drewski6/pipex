/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:58:53 by dpentlan          #+#    #+#             */
/*   Updated: 2022/11/11 12:59:00 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  *** ft_strlcat (42 size-bounded string concatination) ***
 *
 *  Takes destination pointer 'dest', source string 'src', and size_t 'size'.
 *  Concatenates string 'src' to the end of 'dest' by first seeking the first
 *  Null terminator at the end of 'dest' and copying 'size' number of bytes
 *  from 'src' to the end of 'dest'.
 *  Returns number of bytes coppied.
 */

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0U;
	src_len = 0U;
	i = 0U;
	if (src == 0 || dest == 0)
		return (0);
	while (dest[dest_len] != '\0')
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	while (src[i] != '\0' && dest_len + i < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	if (dest_len > size)
		return (src_len + size);
	return (dest_len + src_len);
}
