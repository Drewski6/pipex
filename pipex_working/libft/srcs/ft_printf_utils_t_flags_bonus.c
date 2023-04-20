/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_t_flags_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:02:57 by dpentlan          #+#    #+#             */
/*   Updated: 2023/02/06 13:03:00 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*	*** t_flags_init (type flags (struct) initializer) ***
 *
 *	Creates a new instance of t_flags struct and initializes values to 0.
 *	Takes nothing.
 *	Returns 0 on error or address of 'new_t_flags' struct on success.
 */

t_flags	*t_flags_init(void)
{
	t_flags	*new_t_flags;

	new_t_flags = (t_flags *)malloc(1 * sizeof(t_flags));
	if (!new_t_flags)
		return (0);
	new_t_flags->minus_flag = 0;
	new_t_flags->zero_flag = 0;
	new_t_flags->decimal_flag = 0;
	new_t_flags->pound_flag = 0;
	new_t_flags->space_flag = 0;
	new_t_flags->plus_flag = 0;
	new_t_flags->fs = 0;
	new_t_flags->width = 0;
	new_t_flags->precision = 0;
	new_t_flags->buf_len = 0;
	new_t_flags->buf = 0;
	return (new_t_flags);
}

/*	*** t_flags_li (type flags (struct) load integers) ***
 *
 *	Runs atoi on a digit in the subsequence.
 *	Takes address of the digits in a subsequence 'seq_digits' and a pointer
 *	to a size_t 'seq_elem' counter / atoi return.
 *	Returns len in bytes of parsed string 'i' on success or -1 on ERROR.
 */

int	t_flags_li(char *seq_digits, size_t *seq_elem)
{
	char	*p_str;
	int		i;

	p_str = 0;
	i = 0;
	while (ft_isdigit(seq_digits[i]))
	{
		(*seq_elem)++;
		i++;
	}
	if ((*seq_elem) > 0)
	{
		p_str = ft_substr(seq_digits, i - (*seq_elem), (*seq_elem));
		if (p_str == 0)
			return (-1);
		(*seq_elem) = ft_atoi(p_str);
		free(p_str);
	}
	return (i);
}

/*	*** t_flags_w_p (type flags (struct) width and precision) ***
 *
 *	Parces sequence string and fills t_flags struct width and precision
 *	values.
 *	Takes t_flags struct pointer 'seq_info', address in main string 's' where
 *	the sequence starts 'seq_start', and an integer indicating the length of
 *	the sequence 'seq_len'.
 *	Returns 0 on success or -1 on error.
 */

int	t_flags_w_p(t_flags *seq_info, const char *seq_start, int seq_len)
{
	int		i;
	int		load_int;

	i = 0;
	load_int = 0;
	while (!ft_isdigit(seq_start[i]) && i < seq_len && seq_start[i] != '.')
		i++;
	if (seq_start[i] == '0')
	{
		seq_info->zero_flag = 1;
		i++;
	}
	load_int = t_flags_li((char *)&seq_start[i], &(seq_info->width));
	if (load_int == -1)
		return (-1);
	i += load_int;
	if (seq_start[i] == '.')
	{
		i++;
		load_int = t_flags_li((char *)&seq_start[i], &(seq_info->precision));
		if (load_int == -1)
			return (-1);
		i += load_int;
	}
	return (0);
}

/*	*** t_flags_fill (type flags (struct) fill) ***
 *
 *	Parses subsequence and fills t_flags with info.
 *	Takes t_flags struct pointer 'seq_info', address in main string 's' where
 *	the sequence starts 'seq_start', and an integer indicating the length of
 *	the sequence 'seq_len'.
 *	Returns 0 on success and -1 on error.
 */

int	t_flags_fill(t_flags *seq_info, const char *seq_start, int seq_len)
{
	if (ft_strnstr(seq_start, "-", seq_len))
		seq_info->minus_flag = -1;
	if (ft_strnstr(seq_start, ".", seq_len))
		seq_info->decimal_flag = 1;
	if (ft_strnstr(seq_start, "#", seq_len))
		seq_info->pound_flag = 1;
	if (ft_strnstr(seq_start, " ", seq_len))
		seq_info->space_flag = 1;
	if (ft_strnstr(seq_start, "+", seq_len))
		seq_info->plus_flag = 1;
	if (t_flags_w_p(seq_info, seq_start, seq_len))
		return (-1);
	seq_info->fs = *ft_strchr("cspdiuxX%", seq_start[seq_len - 1]);
	return (0);
}
