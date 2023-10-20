/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:07:42 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:34:39 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	Allocates (with malloc(3)) and returns a new string, which is the result of 
	the concatenation of ’s1’ and ’s2’.
 * @param s1 
	The prefix string.
 * @param s2 
	The suffix string.	
 * @return 
	The new string.
	NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*snew;
	int		i;
	int		j;

	i = 0;
	j = 0;
	snew = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!snew)
		return (0);
	while (s1 && s1[i])
	{
		snew[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		snew[i + j] = s2[j];
		j++;
	}
	snew[i + j] = '\0';
	return (snew);
}
