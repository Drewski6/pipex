/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:20:47 by dpentlan          #+#    #+#             */
/*   Updated: 2022/11/17 17:21:34 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  *** ft_in_charset (42 in character set) ***
 *
 *  Takes int 'c' as a character and string 'set'.
 *  Returns 1 if character 'c' is found in 'set'.
 *  Returns 0 if character 'c' is not found in 'set'.
 */

static int	ft_in_charset(int c, char *set)
{
	while (*set)
	{
		if (*set == (unsigned char)c)
			return (1);
		set++;
	}
	return (0);
}

/*  *** ft_strtrim (42 string trim) ***
 *
 *  Takes a string 's1' and a character set 'set'.
 *  Returns a newly allocated memory space (via ft_substr)
 *  with any characters present in 'set' removed from the beginning
 *  and the end of the 's1'.
 *  Returns 0 if either 's1' or 'set' are 0.
 */

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*ptr;
	size_t	s1_len;

	i = 0;
	j = 0;
	if (s1 == 0 || set == 0)
		return (0);
	s1_len = ft_strlen(s1);
	while (ft_in_charset(*((char *)s1 + i), (char *)set))
		i++;
	while (ft_in_charset(*((char *)s1 + (s1_len - 1 - j)), (char *)set))
		j++;
	ptr = ft_substr(s1, i, (s1_len - (i + j)));
	return (ptr);
}
