/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:00:02 by dpentlan          #+#    #+#             */
/*   Updated: 2023/02/11 09:18:57 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	*** ft_substr (42 sub-string) ***
 *
 *	Takes string 's', unsigned int 'start', and size_t 'len'.
 *	Returns a newly allocated memory space containing a copy of the byte
 *	values after 'start' byte offset for 'len' number of bytes.
 *	Returns 0 (NULL) on error.
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;

	if (s == 0)
		return (0);
	if (start > ft_strlen(s))
		s_len = 0;
	else
		s_len = ft_strlen((char *)s + start);
	if (s_len < len)
	{
		ptr = (char *)ft_calloc((s_len + 1), sizeof(char));
		if (s_len > 0 && ptr)
			ft_strlcpy(ptr, (char *)s + start, s_len + 1);
	}
	else
	{
		ptr = (char *)ft_calloc((len + 1), sizeof(char));
		if (ptr)
			ft_strlcpy(ptr, (char *)s + start, len + 1);
	}
	return (ptr);
}
