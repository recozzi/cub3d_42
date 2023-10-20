/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:17:11 by recozzi           #+#    #+#             */
/*   Updated: 2023/05/03 12:19:37 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	The strncmp() function compares the two strings s1 and s2 only the first (at 
	most) n bytes of s1 and s2.
	The comparison is done using unsigned characters.
 * @return 
	strncmp() returns an integer indicating the result of the comparison, as 
	follows:
	• 0, if the s1 and s2 are equal (diff s1 - s2);
	• a negative value if s1 is less than s2 (diff s1 - s2);
	• a positive value if s1 is greater than s2 (diff s1 - s2).
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((*str1 || *str2) && n)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		n--;
		str1++;
		str2++;
	}
	return (0);
}
