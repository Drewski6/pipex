/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:41:51 by dpentlan          #+#    #+#             */
/*   Updated: 2022/11/26 12:41:54 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  *** ft_strmapi (42 string map by index) ***
 *
 *  Applies function f to each character of the string 's', and passing its 
 *  index as the first argument to create a newly allocated string, resulting
 *  from successive applications of 'f'.
 *  Returns newly allocated string.
 *  Returns 0 if ft_strdup fails or either argument is null.
 */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s_new;
	int		i;

	i = 0;
	s_new = 0;
	if (s == 0 || f == 0)
		return (0);
	s_new = ft_strdup((char *)s);
	if (!s_new)
		return (0);
	while (s_new[i])
	{
		s_new[i] = f(i, s_new[i]);
		i++;
	}
	return (s_new);
}
