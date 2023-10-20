/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:08:09 by recozzi           #+#    #+#             */
/*   Updated: 2023/04/12 19:13:05 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters 
	specified in ’set’ removed from the beginning and the end of the string.
 * @param s1 
	The string to be trimmed.
 * @param set 
	The reference set of characters to trim.	
 * @return 
	The trimmed string.
	NULL if the allocation fails.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*newstr;

	start = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (ft_strdup(s1));
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	if (s1[start] == '\0')
		return (ft_strdup(&s1[start]));
	while (ft_strchr(set, s1[end]))
		end--;
	newstr = ft_substr(s1, start, (end - start + 1));
	return (newstr);
}
