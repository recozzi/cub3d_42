/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:39:56 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:37:29 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	This function convert uppercase letters to lowecase.
	If c is an uppercase letter, tolower() returns its lowercase equivalent, if 
	a lowercase representation exists in the current locale, otherwise, it 
	returns c.
	If c is neither an unsigned char value nor EOF, the behavior of this 
	function is undefined.
 * @return 
	The value returned is that of the converted letter, or c if the conversion 
	was not possible.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
