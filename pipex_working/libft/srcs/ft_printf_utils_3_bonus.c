/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 13:13:23 by dpentlan          #+#    #+#             */
/*   Updated: 2023/02/05 13:13:33 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*	*** ft_bchar (42 byte char) ***
 *
 *	Sets 'len' number of bytes equal to 'c' starting at address 'str'.
 *	Takes string 'str', character 'c' and size_t 'len'.
 *	Returns nothing.
 */

void	ft_bchar(char *str, char c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return ;
}

/*	*** ft_iswsp (42 is whitespace or percent) ***
 *
 *	Takes a character 'c'.
 *	Returns 1 if 'c' is a whitespace or a percent symbol or 0 if not.
 */

int	ft_iswsp(const char *c)
{
	if (*c == 32 || *c == '\f' || *c == '\n'
		|| *c == '\r' || *c == '\t' || *c == '\v' || *c == '%')
		return (1);
	return (0);
}

/*	*** err_check (error checker) ***
 *
 *	Checks for initial conditions where the subsequence is not valid.
 *	First while loop gets seq_len by checking for whitespace, or NULL,
 *		increases len, then checks for format specifier. If one is found, break.
 *	Second while loop makes sure all characters are format specifiers, flags
 *		or digits for padding.
 *	Takes pointer to sequence start 'seq_start'.
 *	Returns length of sequence 'seq_len' on success and -1 on ERROR.
 */

int	err_check(const char *seq_start)
{
	int	seq_len;
	int	i;

	seq_len = 0;
	i = 0;
	if (seq_start[i] == ' ')
		seq_len++;
	while (!ft_iswsp(&seq_start[seq_len]) && seq_start[seq_len] != '\0')
	{
		seq_len++;
		if (ft_strchr("cspdiuxX%", seq_start[seq_len - 1]))
			break ;
	}
	while (i < seq_len)
	{
		if (ft_strchr("-0.# +cspdiuxX%", seq_start[i])
			|| ft_isdigit(seq_start[i]))
			i++;
		else
			return (-1);
	}
	if (seq_len == 0)
		return (-1);
	return (seq_len);
}

/*	***  subseq_b_and_p (subsequence build and print) ***
 *
 *	Calls subseq_build and subseq_print respectively. This function is mostly
 *	for handling errors and reducing function size from subseq_perser.
 *	Takes t_flags struct pointer, va_list pointer 'parg', file descriptor 'fd',
 *	and pointer to int 'print_count'.
 *	Returns 0 on success or -1 on ERROR.
 */

int	subseq_b_and_p(t_flags *seq_info, va_list parg, int fd, int *print_count)
{
	if (subseq_build(seq_info, parg))
		return (-1);
	if (subseq_print(seq_info, fd, print_count))
		return (-1);
	return (0);
}

/*	*** subseq_parser (subsequence parser) ***
 *
 *	Parses the subsequence (flags, precision, format specifiers) after a % sign.
 *	After error checking and allocating for struct and buffer, calls
 *	subseq_b_and_p to build and print the buffer.
 *	Frees all allocated memory at the end.
 *	Takes the address of the beginning of the subsequence 'seq_start', va_list
 *	pointer 'parg', file descriptor 'fd', and pointer to integer 'print_count'
 *	Returns 'seq_len' on success or -1 on ERROR.
 */

int	subseq_parser(const char *seq_start, va_list parg,
	int fd, int *print_count)
{
	int		seq_len;
	t_flags	*seq_info;

	seq_len = err_check(seq_start);
	if (seq_len < 0)
		return (-1);
	seq_info = t_flags_init();
	if (seq_info == 0)
		return (-1);
	if (t_flags_fill(seq_info, seq_start, seq_len))
		return (-1);
	seq_info->buf = (char *)ft_calloc(10 * sizeof(char), 1);
	if (!seq_info->buf)
		return (-1);
	if (subseq_b_and_p(seq_info, parg, fd, print_count))
	{
		free(seq_info->buf);
		free(seq_info);
		return (-1);
	}
	free(seq_info->buf);
	free(seq_info);
	return (seq_len);
}
