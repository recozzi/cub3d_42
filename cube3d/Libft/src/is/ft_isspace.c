/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 13:34:39 by recozzi           #+#    #+#             */
/*   Updated: 2023/10/20 19:01:44 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	This function checks if an integer is a number between 9 and 13 or 32.
 * @param c 
	The integer to be checked.
 * @return 
	1 if it really is a space, 0 if it is not.
*/
int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}
