/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpentlan <dpentlan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:10:36 by dpentlan          #+#    #+#             */
/*   Updated: 2022/11/08 17:10:39 by dpentlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  *** ft_isalnum (42 is alpha-numeric) ***
 *
 *  Takes an integer value for ascii character.
 *  Inclusive OR of result of ft_isalpha and ft_isdigit functions.
 *  Returns 1 if the character is an alpha-numeric character.
 *  Returns 0 if the character is not an alpha-numeric character.
 */

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}
