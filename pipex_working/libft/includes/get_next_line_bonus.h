/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:53:29 by dpentlan          #+#    #+#             */
/*   Updated: 2022/12/30 18:02:06 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <stdlib.h>
# include <unistd.h>

typedef struct s_gnl
{
	char		*buf;
	char		*ret_str;
	int			r_size;
}	t_gnl;

char	*get_next_line(int fd, int clear_flag);
void	ft_bzero(void *str, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_strdup(const char *src);

#endif
