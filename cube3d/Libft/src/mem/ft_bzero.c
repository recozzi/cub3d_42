/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:34:19 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:36:16 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*! 
 @brief
	The bzero() function erases the data in the n bytes of the memory starting 
	at the location pointed to by s, by writing zeros (bytes containing '\0') 
	to that area.
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
