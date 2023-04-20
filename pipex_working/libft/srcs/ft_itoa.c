/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:26:08 by dpentlan          #+#    #+#             */
/*   Updated: 2022/11/25 19:26:13 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  *** ft_count (count) ***
 *
 *  Takes integer 'n'.
 *  Returns the number of bytes needed to represent integer 'n' as a string.
 */

static int	ft_count(int n)
{
	int	n_size;

	n_size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n_size += 2;
		n /= -10;
	}
	while (n != 0)
	{
		n_size += 1;
		n /= 10;
	}
	return (n_size);
}

/*  *** ft_itoa (42 integer to ascii) ***
 *
 *  Takes an integer 'n'.
 *  Returns a newly allocated memory space containing a string 
 *  representation of int 'n'.
 */

char	*ft_itoa(int n)
{
	static int	s_len;
	char		*s;

	s_len = 0;
	s_len = ft_count(n);
	s = (char *)ft_calloc(1, (s_len + 1) * sizeof(char));
	if (!s)
		return (0);
	if (n == 0)
		*s = '0';
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	while ((unsigned int) n > 0)
	{
		s[(s_len - 1)] = ((unsigned int) n % 10) + '0';
		n = (unsigned int) n / 10;
		s_len--;
	}
	return (s);
}
