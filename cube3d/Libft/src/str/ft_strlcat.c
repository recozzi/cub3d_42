/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:45:07 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:34:34 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief
	The strlcat() function concatenate strings. It is designed to be safer,
	more consistent, and less error prone replacements for strncat(3).
	Unlike this function, strlcat() take the full size of the buffer (not just 
	the length) and guarantee to NUL-terminate the result (as long as size is 
	larger than 0 or, in the case of strlcat(), as long as there is at least one 
	byte free in dst). Note that a byte for the NUL should be included in size.
	Also note that strlcat() only operate on true “C” strings, this means that
	for strlcat() both src and dst must be NUL-terminated.
	The strlcat() function appends the NUL-terminated string src to the end of 
	dst. It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the 
	result.
 * @return 
	The strlcat() function return the total length of the string they tried to 
	create.
	For strlcat() that means the initial length of dst plus the length of src.
	Note, however, that if strlcat() traverses size characters without finding a 
	NUL, the length of the string is considered to be size and the destination 
	string will not be NUL-terminated (since there was no space for the NUL).  
	This keeps strlcat() from running off the end of a string.  
	In practice this should not happen (as it means that either size is 
	incorrect or that dst is not a proper “C” string).  
	The check exists to prevent potential security problems in incorrect code.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = 0;
	j = 0;
	s = (char *)src;
	while (i < dstsize && dst[i])
		i++;
	while (i + j + 1 < dstsize && s[j])
	{
		dst[i + j] = s[j];
		j++;
	}
	if (i + j < dstsize)
		dst[i + j] = '\0';
	return (i + ft_strlen(s));
}
