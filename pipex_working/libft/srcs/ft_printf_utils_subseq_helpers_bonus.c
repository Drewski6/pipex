/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_subseq_helpers.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:34:59 by dpentlan          #+#    #+#             */
/*   Updated: 2023/02/09 18:35:02 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*	*** decimal_precision (decimal precision) ***
 *
 *	Adds 0 padding after sign if precision is greater than current buffer 
 *	length.
 *	Takes t_flags struct pointer 'seq_info'.
 *	Returns 0 on success or -1 on ERROR.
 */

int	decimal_precision(t_flags *seq_info)
{
	int		padding;
	char	*buf_padding;
	int		sign;

	padding = 0;
	padding = seq_info->precision - seq_info->buf_len;
	sign = 0;
	if (*(seq_info->buf) == '-')
		padding++;
	if (*(seq_info->buf) == '-')
		sign = 1;
	if (padding > 0)
	{
		buf_padding = (char *)ft_calloc((padding + 1), sizeof(char));
		if (!buf_padding)
			return (-1);
		ft_bchar(buf_padding, '0', padding);
		if (write_to_buf(seq_info, buf_padding, padding, sign) <= 0)
		{
			free(buf_padding);
			return (-1);
		}
		free(buf_padding);
	}
	return (0);
}

/*	*** subseq_decimal (subsequence decimal) ***
 *
 *	Used with decimal_precision to edit buffer when a decimal flag is present.
 *	If format specifier is for a string, ft_memcpy only precision amount. This
 *	will retain only 'seq_info->precision' amount of the buffer.
 *	If format specifier is anything other than a string, then decimal_precision
 *	is called.
 *	Takes a t_flags struct pointer 'seq_info'.
 *	Returns precision length on success or -1 on ERROR.
 */

int	subseq_decimal(t_flags *seq_info)
{
	char	*new_buf;

	new_buf = 0;
	if (seq_info->decimal_flag == 1 && seq_info->fs == 's'
		&& (seq_info->buf_len > seq_info->precision))
	{
		new_buf = (char *)ft_calloc(seq_info->precision + 1, sizeof(char));
		if (!new_buf)
			return (-1);
		if (!ft_memcpy(new_buf, seq_info->buf, seq_info->precision))
			return (-1);
		free(seq_info->buf);
		seq_info->buf_len = seq_info->precision;
		seq_info->buf = new_buf;
	}
	else if (seq_info->fs != 's')
	{
		if (decimal_precision(seq_info) < 0)
			return (-1);
	}
	return (seq_info->precision);
}

/*	*** subseq_pound (subsequence pound) ***
 *
 *	Adds 0x or 0X in beginning of buffer if format specifier is a x or X (d is
 *	a passthrough).
 *	Takes a t_flags struct pointer 'seq_info'.
 *	Returns 0 on success or -1 on ERROR.
 */

int	subseq_pound(t_flags *seq_info)
{
	if (!ft_memcmp(seq_info->buf, "0", 2))
		return (0);
	if (seq_info->fs == 'x')
	{
		if (write_to_buf(seq_info, "0x", 2, 0) <= 0)
			return (-1);
	}
	else if (seq_info->fs == 'X')
	{
		if (write_to_buf(seq_info, "0X", 2, 0) <= 0)
			return (-1);
	}
	else if (seq_info->fs == 'd')
		return (0);
	else
		return (-1);
	return (0);
}

/*	*** subseq_sign (subsequence sign) ***
 *
 *	Adds a sign to the buffer if the space_flag OR the plus_flag is set (but
 *	not both).
 *	Takes a t_flags struct pointer 'seq_info'.
 *	Returns 0 on success or -1 on ERROR.
 */

int	subseq_sign(t_flags *seq_info)
{
	if (seq_info->space_flag && seq_info->plus_flag)
		return (-1);
	else if (seq_info->space_flag == 1)
	{
		if (*(seq_info->buf) == '-')
			return (0);
		else
		{
			if (write_to_buf(seq_info, " ", 1, 0) <= 0)
				return (-1);
		}
	}
	else if (seq_info->plus_flag == 1)
	{
		if (*(seq_info->buf) == '-')
			return (0);
		else
		{
			if (write_to_buf(seq_info, "+", 1, 0) <= 0)
				return (-1);
		}
	}
	return (0);
}

/*	*** subseq_padding (subsequence padding) ***
 *
 *	Adds padding to buffer after '-' symbol if one is present but before number.
 *	Takes a t_flags struct pointer 'seq_info'.
 *	Returns 0 on success or -1 on ERROR.
 */

int	subseq_padding(t_flags *seq_info)
{
	int		padding;
	int		offset;
	char	*buf_padding;

	offset = seq_info->minus_flag;
	if (*(seq_info->buf) == '-' && seq_info->zero_flag == 1)
		offset++;
	padding = seq_info->width - seq_info->buf_len;
	if (padding > 0)
	{
		buf_padding = (char *)ft_calloc((padding + 1), sizeof(char));
		if (!buf_padding)
			return (-1);
		if (seq_info->zero_flag == 0)
			ft_bchar(buf_padding, ' ', padding);
		else
			ft_bchar(buf_padding, '0', padding);
		if (write_to_buf(seq_info, buf_padding, padding, offset) <= 0)
		{
			free(buf_padding);
			return (-1);
		}
		free(buf_padding);
	}
	return (0);
}
