/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:16:23 by dpentlan          #+#    #+#             */
/*   Updated: 2022/11/17 15:16:34 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  *** ft_strjoin (42 string join) ***
 *
 *  Takes two strings 's1' and 's2'.
 *  Returns a newly allocated memory space containing copies of 's1' memory
 *  space followed by 's2' memory space.
 */

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len + s2_len == 0)
		return (0);
	ptr = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, (s1_len + s2_len + 1));
	ft_memcpy(ptr, (char *)s1, s1_len);
	ft_memcpy((ptr + s1_len), (char *)s2, s2_len);
	return (ptr);
}
