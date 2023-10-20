/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:48:32 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:34:02 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	The strnstr() function locates the first occurrence of the null-terminated 
	string little in the string big, where not more than len characters are 
	searched. Characters that appear after a ‘\0’ character are not searched.
 * @return 
	If little is an empty string, big is returned; if little occurs nowhere in 
	big, NULL is returned; otherwise a pointer to the first character of the 
	first occurrence of little is returned.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[j])
		{
			j++;
			if (little[j] == '\0')
				return ((char *)big + i - j + 1);
		}
		else
		{
			i -= j;
			j = 0;
		}
		i++;
	}
	return (0);
}
