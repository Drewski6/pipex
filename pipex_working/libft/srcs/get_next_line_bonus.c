/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:53:18 by dpentlan          #+#    #+#             */
/*   Updated: 2022/12/29 21:37:45 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*  *** nl_loc (newline locate) ***
 *
 *  Looks for a newline in the string and 
 *  returns a signed int indicating the index in the string where the 
 *  newline is located.
 *  returns -1 if newline not found or str is null.
 */

static int	nl_loc(char *str)
{
	size_t	i;

	if (str == 0)
		return (-1);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == 0)
		return (-1);
	return (i);
}

/*  *** str_trim (string trim) ***
 *
 *  str_trim will malloc memory of size 'len' + 2.
 *  Then, copy each character until a newline is found.
 *  Then, add a newline if one is found at the end of the string
 *  Then, add a null terminator and return the resulting string.
 */

static char	*str_trim(char *s_buf, size_t len)
{
	size_t	i;
	char	*ret_s_buf;

	i = 0;
	ret_s_buf = (char *)malloc(len + 2);
	if (!ret_s_buf)
		return (0);
	while (s_buf[i] != '\n' && s_buf[i])
	{
		ret_s_buf[i] = s_buf[i];
		i++;
	}
	if (s_buf[i] == '\n')
	{
		ret_s_buf[i] = s_buf[i];
		i++;
	}
	ret_s_buf[i] = 0;
	return (ret_s_buf);
}

/*  *** ret_str_build (Return String Build) ***
 *
 *  Takes the static buffer and cuts off portion after newline to
 *  make malloced string for return.
 */

static char	*ret_str_build(char *s_buf)
{
	size_t	nl_index;
	size_t	len_s_buf;
	char	*ret_s_buf;

	len_s_buf = ft_strlen(s_buf);
	if (len_s_buf <= 0)
		return (0);
	nl_index = nl_loc(s_buf);
	if ((int) nl_index == -1 || nl_index == len_s_buf - 1)
	{
		ret_s_buf = ft_strdup(s_buf);
		return (ret_s_buf);
	}
	ret_s_buf = str_trim(s_buf, nl_index);
	return (ret_s_buf);
}

/*  *** clean_s_buf (clean static buffer) ***
 *
 *  After a static buffer has been used to find an entire newline,
 *  clean_s_buf will remove an entire newline from the static buffer
 *  to allow carry over to next usage of get_next_line without needing
 *  to read from the file again.
 *  Returns address to new saved carry over on the heap.
 */

static char	*clean_s_buf(char *s_buf)
{
	size_t	nl_index;
	size_t	len_s_buf;
	char	*ret_s_buf;

	nl_index = nl_loc(s_buf);
	if ((int) nl_index == -1)
	{
		free(s_buf);
		return (0);
	}
	len_s_buf = ft_strlen(s_buf);
	if (len_s_buf - nl_index == 1)
	{
		free(s_buf);
		return (0);
	}
	ret_s_buf = ft_strdup(&(s_buf[nl_index + 1]));
	free(s_buf);
	return (ret_s_buf);
}

/*  *** get_next_line (get next line) ***
 *
 *  Uses static char buffer to keep portion after newline
 *  for next function call if needed.
 *  Checks for negative buffer size or invalid file descriptor.
 *	User can send a file descriptor and a clear_flag.
 *	If the clear_flag is non-zero, gnl will free the pointer at s_buf[fd].
 *  Returns malloced string from staring position to next newline
 *  in open file stream.
 */

char	*get_next_line(int fd, int clear_flag)
{
	static char	*s_buf[4096];
	t_gnl		buf_info;

	if (clear_flag)
		return (free(s_buf[fd]), NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf_info.buf = malloc(BUFFER_SIZE + 1);
	if (!buf_info.buf)
		return (0);
	buf_info.r_size = 1;
	while (nl_loc(s_buf[fd]) == -1)
	{
		buf_info.r_size = read(fd, buf_info.buf, BUFFER_SIZE);
		if (buf_info.r_size <= 0)
			break ;
		buf_info.buf[buf_info.r_size] = 0;
		s_buf[fd] = ft_strjoin_gnl(s_buf[fd], buf_info.buf);
	}
	free(buf_info.buf);
	if (buf_info.r_size == -1)
		return (0);
	buf_info.ret_str = ret_str_build(s_buf[fd]);
	s_buf[fd] = clean_s_buf(s_buf[fd]);
	return (buf_info.ret_str);
}
