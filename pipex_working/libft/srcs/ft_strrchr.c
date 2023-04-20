/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:18:16 by dpentlan          #+#    #+#             */
/*   Updated: 2022/11/11 17:18:18 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  *** ft_strrchr (42 string reverse character)
 *
 *  Takes a string 's' and a character 'c'.
 *  Returns the address of the last instance of character 'c' in string 's'.
 */

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	last = 0;
	i = 0;
	if ((unsigned char)c == 0)
		return ((char *)s + ft_strlen(s));
	while (s[i] != 0)
	{
		if (s[i] == (unsigned char)c)
			last = (char *)&s[i];
		i++;
	}
	return (last);
}
