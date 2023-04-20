/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:32:59 by dpentlan          #+#    #+#             */
/*   Updated: 2022/12/30 18:33:01 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include "../../libft/includes/libft.h"

/*	*** t_flags (struct) ***
 *
 *	char	minus_flag;			//	Set to 1 if minus flag is present.
 *	char	zero_flag;			//	Set to 1 if 0 flag is present.
 *	char	decimal_flag;		//	Set to 1 if decimal is present.
 *	char	pound_flag;			//	Set to 1 if # flag is present.
 *	char	space_flag;			//	Set to 1 if [ SPACE ] flag is present.
 *	char	plus_flag;			//	Set to 1 if + flag is present.
 *	char	fs;					//	Char that saves the format specifier.
 *	size_t	width;				//	Size of padding to add.
 *	size_t	precision;			//	Size of precision.
 *	size_t	buf_len;			//	Number of characters printed to buffer.
 *	char	*buf;				//	The string to be written to the fd.
 */

typedef struct s_flags {
	char	minus_flag;
	char	zero_flag;
	char	decimal_flag;
	char	pound_flag;
	char	space_flag;
	char	plus_flag;
	char	fs;
	size_t	width;
	size_t	precision;
	size_t	buf_len;
	char	*buf;
}			t_flags;

//		ft_printf_bonus.c
int		ft_pointer_handle(t_flags *seq_info, va_list parg);
int		percent_handler(char *s, va_list parg, int fd, int *print_count);
int		ft_printf(const char *s, ...);

//		ft_printf_utils_format_switch_bonus.c
int		format_switch_buf_1(t_flags *seq_info, va_list parg);
int		format_switch_buf_2(t_flags *seq_info, va_list parg);
int		format_switch_buf_3(t_flags *seq_info, va_list parg);

//		ft_printf_utils_1_bonus.c
int		ft_putchar_buf(char c, t_flags *seq_info);
int		ft_putstr_buf(char *s, t_flags *seq_info);
int		ft_putnbr_buf_helper(long nbl, t_flags *seq_info);
int		ft_putnbr_buf(int n, t_flags *seq_info);

//		ft_printf_utils_2_bonus.c
int		ft_dec_to_hex_upper_buf(unsigned int n, t_flags *seq_info);
int		ft_dec_to_hex_lower_buf(unsigned int n, t_flags *seq_info);
int		ft_p_to_hex_buf(void *p, t_flags *seq_info);
int		ft_putunbr_buf(unsigned int n, t_flags *seq_info);

//		ft_printf_utils_3_bonus.c
void	ft_bchar(char *str, char c, size_t len);
int		ft_iswsp(const char *c);
int		err_check(const char *seq_start);
int		subseq_b_and_p(t_flags *seq_info, va_list parg, int fd,
			int *print_count);
int		subseq_parser(const char *seq_start, va_list parg,
			int fd, int *print_count);

//		ft_printf_utils_subseq_helpers_bonus.c
int		decimal_precision(t_flags *seq_info);
int		subseq_decimal(t_flags *seq_info);
int		subseq_pound(t_flags *seq_info);
int		subseq_sign(t_flags *seq_info);
int		subseq_padding(t_flags *seq_info);

//		ft_printf_utils_t_flags_bonus.c
void	t_flags_inspect(t_flags *seq);
t_flags	*t_flags_init(void);
int		t_flags_li(char *seq_digits, size_t *seq_elem);
int		t_flags_w_p(t_flags *seq_info, const char *seq_start, int seq_len);
int		t_flags_fill(t_flags *seq_info, const char *seq_start, int seq_len);

//		ft_printf_utils_use_flags_bonus.c
int		subseq_build(t_flags *seq_info, va_list parg);
int		subseq_print(t_flags *seq_info, int fd, int *print_count);
char	*ft_memjoin(char const *s1, size_t s1_len, char const *s2,
			size_t s2_len);
char	*str_insert(t_flags *seq_info, char *new_str, size_t len, int wi);
int		write_to_buf(t_flags *seq_info, char *str, size_t len, int wi);

#endif
