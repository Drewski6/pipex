/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_use_flags_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:06:47 by dpentlan          #+#    #+#             */
/*   Updated: 2023/02/07 13:06:49 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*	*** subseq_build (subsequence build) ***
 *
 *	First calls format_switch_buf_1 to write parg to buffer.
 *	Then makes a series of function calls based on which flags are present in
 *	subsequence.
 *	Takes t_flags struct pointer 'seq_info', and va_list pointer 'parg'.
 *	Returns 0 on success or -1 on ERROR.
 */

int	subseq_build(t_flags *seq_info, va_list parg)
{
	if (format_switch_buf_1(seq_info, parg))
		return (-1);
	if (seq_info->decimal_flag == 1)
	{
		if (subseq_decimal(seq_info) < 0)
			return (-1);
	}
	if (seq_info->pound_flag == 1)
	{
		if (subseq_pound(seq_info))
			return (-1);
	}
	if (seq_info->fs == 'd' || seq_info->fs == 'i')
	{
		if (subseq_sign(seq_info))
			return (-1);
	}
	if (seq_info->width > 0)
	{
		if (subseq_padding(seq_info))
			return (-1);
	}
	return (0);
}

/*	*** subseq_print (subsequence print) ***
 *
 *	Takes the buffer 'seq_info->buf' and prints 'seq_info->buf_len' to 'fd'.
 *	Takes t_flags struct poitner 'seq_into', file descriptor integer 'fd',
 *	and pointer to int 'print_count'.
 *	Returns 0 on success.
 */

int	subseq_print(t_flags *seq_info, int fd, int *print_count)
{
	write(fd, seq_info->buf, seq_info->buf_len);
	*print_count += seq_info->buf_len;
	return (0);
}

/*  *** ft_memjoin (42 memory join) ***
 *
 *	Works the same as ft_strjoin but uses s1_len and s2_len as parameters.
 *	This allows the user to copy specific number of bytes rather than scanning
 *	for a null terminator.
 *	Takes string 's1', size_t 's1_len', string 's2', size_t 's2_len'.
 *	Returns address of newly created pointer 'ptr'.
 */

char	*ft_memjoin(char const *s1, size_t s1_len, char const *s2,
	size_t s2_len)
{
	char	*ptr;

	if (s1 == 0 || s2 == 0)
		return (0);
	ptr = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, (s1_len + s2_len + 1));
	ft_memcpy(ptr, (char *)s1, s1_len);
	ft_memcpy((ptr + s1_len), (char *)s2, s2_len);
	return (ptr);
}

/*	*** str_insert (string insert) ***
 *
 *	Based on 'wi' (write index) this function will insert string 'new_str'
 *	at the beginning, end or in the middle of 'seq_info->buf'.
 *	Allows more 'pythonic' string manipulation.
 *	Takes t_flags struct pointer, address of string to add 'new_str', size_t
 *	'len' for amount of bytes from 'new_str' to write, and int 'wi' for the
 *	index in buf to insert 'new_str'.
 *	Returns address of 'new_buf' on success or 0 on ERROR.
 */

char	*str_insert(t_flags *seq_info, char *new_str, size_t len, int wi)
{
	char	*new_buf;
	char	*new_buf_beg;
	char	*new_buf_end;

	if (wi < 0)
		new_buf = ft_memjoin(seq_info->buf, seq_info->buf_len, new_str, len);
	else
	{
		new_buf_beg = ft_substr(seq_info->buf, 0, wi);
		if (!new_buf_beg)
			return (0);
		new_buf_end = ft_memjoin(new_str, len, &(seq_info->buf[wi]),
				seq_info->buf_len - wi);
		if (!new_buf_end)
			return (0);
		new_buf = ft_memjoin(new_buf_beg, wi, new_buf_end,
				len + seq_info->buf_len - wi);
		free(new_buf_beg);
		free(new_buf_end);
	}
	if (new_buf == 0)
		return (0);
	return (new_buf);
}

/*	*** write_to_buf (write to print buffer) ***
 *
 *	Rather than writing to a file descriptor, this write writes
 *	to a buffer.
 *	Basically str_join with len.
 *	Also uses str_insert to copy 'str' into specific index in buffer.
 *	Takes a t_flags struct pointer 'seq_info', a string 'str', size_t 'len'
 *	for the amount of bytes from the 'str' to write, and int 'wi' (write index)
 *	for the starting place in 'str' to start writing.
 *	Returns 'len' on success indicating number of bytes copied or -1 on ERROR.
 */

int	write_to_buf(t_flags *seq_info, char *str, size_t len, int wi)
{
	char	*new_buf;
	char	*new_str;

	if (*str == 0 && len == 1)
	{
		*(seq_info->buf) = 0;
		seq_info->buf_len++;
		return (1);
	}
	new_str = ft_strdup(str);
	if (!new_str)
		return (-1);
	new_buf = str_insert(seq_info, new_str, len, wi);
	free(new_str);
	if (!new_buf)
		return (-1);
	free(seq_info->buf);
	seq_info->buf = new_buf;
	seq_info->buf_len += len;
	return (len);
}
