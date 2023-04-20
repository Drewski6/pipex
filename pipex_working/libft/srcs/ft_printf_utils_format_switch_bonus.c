/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_format_switch_bonus.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:16:36 by dpentlan          #+#    #+#             */
/*   Updated: 2023/02/09 20:16:39 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*  *** format_switch_buf_1 (format switch buffer #1) ***
 *
 *	Part 1 of 3 functions that act as a switch for determining which function
 *	to use to turn 'parg' to a printable string. 
 *	Takes a t_flags struct pointer and va_list pointer.
 *	Returns 0 on success or -1 on ERROR.
 */

int	format_switch_buf_1(t_flags *seq_info, va_list parg)
{
	if (seq_info->fs == 'c')
	{
		if (ft_putchar_buf(va_arg(parg, int), seq_info))
			return (-1);
	}
	else if (seq_info->fs == 's')
	{
		if (ft_putstr_buf(va_arg(parg, char *), seq_info))
			return (-1);
	}
	else if (seq_info->fs == 'p')
	{
		if (ft_pointer_handle(seq_info, parg))
			return (-1);
	}
	else
	{
		if (format_switch_buf_2(seq_info, parg))
			return (-1);
	}
	return (0);
}

/*  *** format_switch_buf_2 (format switch buffer #2) ***
 *
 *	Part 2 of 3 functions that act as a switch for determining which function
 *	to use to turn 'parg' to a printable string. 
 *	Takes a t_flags struct pointer and va_list pointer.
 *	Returns 0 on success or -1 on ERROR.
 */

int	format_switch_buf_2(t_flags *seq_info, va_list parg)
{
	if (seq_info->fs == 'd')
	{
		if (ft_putnbr_buf(va_arg(parg, int), seq_info))
			return (-1);
	}
	else if (seq_info->fs == 'i')
	{
		if (ft_putnbr_buf(va_arg(parg, int), seq_info))
			return (-1);
	}
	else if (seq_info->fs == 'u')
	{
		if (ft_putunbr_buf((unsigned int)va_arg(parg, int), seq_info))
			return (-1);
	}
	else
	{
		if (format_switch_buf_3(seq_info, parg))
			return (-1);
	}
	return (0);
}

/*  *** format_switch_buf_3 (format switch buffer #3) ***
 *
 *	Part 3 of 3 functions that act as a switch for determining which function
 *	to use to turn 'parg' to a printable string. 
 *	Takes a t_flags struct pointer and va_list pointer.
 *	Returns 0 on success or -1 on ERROR.
 */

int	format_switch_buf_3(t_flags *seq_info, va_list parg)
{
	if (seq_info->fs == 'x')
	{
		if (ft_dec_to_hex_lower_buf(va_arg(parg, int), seq_info))
			return (-1);
	}
	else if (seq_info->fs == 'X')
	{
		if (ft_dec_to_hex_upper_buf(va_arg(parg, int), seq_info))
			return (-1);
	}
	else
		return (-1);
	return (0);
}
