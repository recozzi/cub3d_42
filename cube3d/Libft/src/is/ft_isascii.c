/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:27:38 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:37:17 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
 	Checks whether c is a 7-bit unsigned char value that fits into the ASCII
	character set.
 * @return 
 	The values returned are nonzero if the character c falls into the tested 
	class, and zero if not.
 */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
