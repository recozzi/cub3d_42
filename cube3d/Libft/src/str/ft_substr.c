/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:10:48 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:32:59 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	Allocates (with malloc(3)) and returns a substring from the string ’s’.
	The substring begins at index ’start’ and is of	maximum size ’len’.
 * @param s 
	The string from which to create the substring.
 * @param start 
	The start index of the substring in the string ’s.
 * @param len 
	The maximum length of the substring.
 * @return 
	The substring.
	NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	while (i < len && start < ft_strlen(s))
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
