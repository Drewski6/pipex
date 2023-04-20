/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:03:17 by dpentlan          #+#    #+#             */
/*   Updated: 2023/04/13 12:03:23 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*	*** ft_strjoin_gnl (42 string join get next line) ***
 *	Same as ft_strjoin but with a slight change so it works with gnl.
 *	
 *	Returns a pointer to newly malloced string composed for s1 and s2
 *	concatination.
 */

char	*ft_strjoin_gnl(const char *s1, const char *s2)
{
	char	*new_str;
	int		i;
	size_t	size;

	if (s1)
		size = ft_strlen(s1);
	if (s2)
		size = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc(sizeof(char) * (size + 1));
	if (!new_str)
		return (NULL);
	size = 0;
	while (s1 && s1[size])
	{
		new_str[size] = s1[size];
		size++;
	}
	i = -1;
	while (s2 && s2[++i])
		new_str[size++] = s2[i];
	new_str[size] = '\0';
	free((char *)s1);
	return (new_str);
}
