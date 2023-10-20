/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:39:03 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:37:34 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	This function convert lowercase letters to uppercase.
	If c is a lowercase letter, toupper() returns its uppercase equivalent, if 
	an uppercase representation exists in the current locale, otherwise, it 
	returns c.
	If c is neither an unsigned char value nor EOF, the behavior of this 
	function is	undefined.
 * @return 
	The value returned is that of the converted letter, or c if the conversion 
	was not	possible.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
