/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:19:03 by recozzi           #+#    #+#             */
/*   Updated: 2023/05/17 12:36:29 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	The strcmp() function compares the two strings s1 and s2.
	The comparison is done using unsigned characters.
 * @return 
	strcmp() returns an integer indicating the result of the comparison, as 
	follows:
	• 0, if the s1 and s2 are equal (diff s1 - s2);
	• a negative value if s1 is less than s2 (diff s1 - s2);
	• a positive value if s1 is greater than s2 (diff s1 - s2).
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
