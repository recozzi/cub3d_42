/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:22:37 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:36:00 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	The memchr() function scans the initial n bytes of the memory area pointed 
	to by s for the first instance of c; 
	Both c and the bytes of the memory area pointed to by s are interpreted as 
	unsigned char.
 * @return 
	The memchr() function return a pointer to the matching byte or NULL if the 
	character does not occur in the given memory area.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p_s;
	unsigned char	chr;

	p_s = (unsigned char *) s;
	chr = (unsigned char) c;
	while (n)
	{
		if (*p_s == chr)
			return (p_s);
		n--;
		p_s++;
	}
	return (0);
}
