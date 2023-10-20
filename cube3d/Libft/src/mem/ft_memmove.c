/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:58:39 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:35:46 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	The memmove() function copies n bytes from memory area src to memory area 
	dest; 
	The memory areas may overlap: copying takes place as though the bytes in src 
	are first copied into a temporary array that does not overlap src or dest, 
	and the bytes are then copied from the temporary array to dest.
 * @return 
	The memmove() function returns a pointer to dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dest;
	s = src;
	if (!dest && !src)
		return (NULL);
	if (d < s)
		ft_memcpy(d, s, n);
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}
