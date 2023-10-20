/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:56:21 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:33:36 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	The strrchr() function returns a pointer to the last occurrence of the 
	character c in the string s.
	Here "character" means "byte"; this functions do not work with wide or 
	multibyte characters.
 * @return 
	The strrchr() function return a pointer to the matched character or NULL if 
	the character is not found.  
	The terminating null byte is considered part of the string, so that if c is 
	specified as '\0', this functions return a pointer to the terminator.
 */
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
	{
		while (s[i])
			i++;
		return ((char *) s + i);
	}
	c %= 256;
	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *) s + i);
		i--;
	}
	return (0);
}
