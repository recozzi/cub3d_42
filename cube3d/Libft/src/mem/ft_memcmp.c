/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:47:59 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:35:55 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	The memcmp() function compares the first n bytes (each interpreted as 
	unsigned char) of the memory areas s1 and s2.
 * @return 
	The memcmp() function returns an integer less than, equal to, or greater 
	than zero if the first n bytes of s1 is found, respectively, to be less 
	than, to match, or be greater than the first n bytes of s2.
	For a nonzero return value, the sign is determined by the sign of the  
	difference between the first pair of bytes (interpreted as unsigned char) 
	that differ in s1 and s2.
	If n is zero, the return value is zero.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	p_s1 = (unsigned char *) s1;
	p_s2 = (unsigned char *) s2;
	while (n)
	{
		if (*p_s1 != *p_s2)
			return (*p_s1 - *p_s2);
		n--;
		p_s1++;
		p_s2++;
	}
	return (0);
}
