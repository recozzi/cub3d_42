/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:01:41 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:37:12 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	Checks  for an alphabetic character. In some locales, there may be
	additional characters for which isalpha() is true—letters which are neither
	uppercase nor lowercase.
 * @return 
 	The values returned are nonzero if the character c falls into the tested 
	class, and zero if not.
 */
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
