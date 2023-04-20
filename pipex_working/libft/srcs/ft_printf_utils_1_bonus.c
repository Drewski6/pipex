/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:41:16 by dpentlan          #+#    #+#             */
/*   Updated: 2022/12/31 14:41:19 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*  *** ft_putchar_buf (42 put character to buffer) ***
 *
 *	Takes a character 'c' and a t_flags struct pointer and prints character
 *	to buffer.
 *	Returns 0 on success and -1 on ERROR.
 */

int	ft_putchar_buf(char c, t_flags *seq_info)
{
	char	*ch;

	ch = (char *)ft_calloc(2, sizeof(char));
	if (!ch)
		return (-1);
	ch[0] = c;
	if (write_to_buf(seq_info, ch, 1, 0) <= 0)
	{
		free(ch);
		return (-1);
	}
	free(ch);
	return (0);
}

/*  *** ft_putstr_buf (42 put string to buffer) ***
 *
 *	Takes a string 's' and a t_flags struct pointer and prints character
 *	to buffer.
 *	Returns 0 on success and -1 on ERROR.
 */

int	ft_putstr_buf(char *s, t_flags *seq_info)
{
	size_t	str_len;

	str_len = 0;
	if (s == 0)
	{
		if (write_to_buf(seq_info, "(null)", 6, -1) <= 0)
			return (-1);
		return (0);
	}
	str_len = ft_strlen(s);
	if (write_to_buf(seq_info, s, str_len, -1) < 0)
		return (-1);
	return (0);
}

/*	*** ft_putnbr_buf_helper (42 put number to buffer helper) ***
 *
 *	Helper function to reduce size of ft_putnbr_buf.
 *	Takes long nbl and t_flags struct pointer.
 *	Returns 0 on success or -1 on ERROR.
 */

int	ft_putnbr_buf_helper(long nbl, t_flags *seq_info)
{
	if (nbl < 0)
	{
		if (ft_putnbr_buf((nbl / 10) * -1, seq_info))
			return (-1);
	}
	else
	{
		if (ft_putnbr_buf(nbl / 10, seq_info))
			return (-1);
	}
	return (0);
}

/*  *** ft_putnbr_buf (42 put number buffer) ***
 *
 *	Recursive function that takes an integer 'n' and t_flags struct pointer
 *	and prints a string representation to a buffer.
 *	Uses a helper function ft_putnbr_buf_helper to reduce function size for 
 *	42 function requirements.
 *	Takes an integer 'n' and t_flags struct pointer.
 *	Returns 0 on success or -1 on ERROR.
 */

int	ft_putnbr_buf(int n, t_flags *seq_info)
{
	long	nbl;
	char	c;

	nbl = (long)n;
	if (nbl < 0)
	{
		if (write_to_buf(seq_info, "-", 1, -1) <= 0)
			return (-1);
	}
	if (nbl / 10 != 0)
	{
		if (ft_putnbr_buf_helper(nbl, seq_info))
			return (-1);
	}
	if (nbl < 0)
		c = (((nbl % 10) * -1) + '0');
	else
		c = (nbl % 10 + '0');
	if (write_to_buf(seq_info, &c, 1, -1) <= 0)
		return (-1);
	return (0);
}
