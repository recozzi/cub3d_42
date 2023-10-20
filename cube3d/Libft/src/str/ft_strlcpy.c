/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:30:36 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:34:29 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
 	The strlcpy() functions copy strings. It is designed to be safer, more
	consistent, and less error prone replacements for strncpy(3).
	Unlike this function, take the full size of the buffer (not just the length) 
	and guarantee to NUL-terminate the result (as long as size is larger than 0).
	Note that a byte for the NUL should be included in size. Also note that
	strlcpy() only operate on true “C” strings, this means that for strlcpy()
	src must be NUL-terminated.
	The strlcpy() function copies up to size - 1 characters from the
	NUL-terminated string src to dst, NUL-terminating the result.
 * @return 
 	The strlcpy() function return the total length of the string it tried to 
	create. For strlcpy() that means the length of src.
	This keeps strlcat() from running off the end of a string.  
	In practice this should not	happen (as it means that either size is 
	incorrect or that dst is not a proper “C” string).  
	The check exists to prevent potential security problems in incorrect code.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;

	i = 0;
	if (destsize)
	{	
		while (src[i] && i < destsize - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
