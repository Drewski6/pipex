/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:33:09 by dpentlan          #+#    #+#             */
/*   Updated: 2022/11/26 13:33:13 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  *** ft_putchar_fd (42 put character file descriptor) ***
 *
 *  Outputs the character 'c' to the given file descriptor.
 *  Returns nothing.
 */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
