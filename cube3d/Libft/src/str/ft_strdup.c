/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:15:22 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:34:50 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	The strdup() function returns a pointer to a new string which is a duplicate 
	of the string s;
	Memory for the new string is obtained with malloc(3), and can be freed with 
	free(3).
 * @return 
	On success, the strdup() function returns a pointer to the duplicated 
	string.   
	It returns NULL if insufficient memory was available.
 */
char	*ft_strdup(const char *s)
{
	char	*snew;
	int		i;

	i = 0;
	snew = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!snew)
		return (NULL);
	while (s[i])
	{
		snew[i] = s[i];
		i++;
	}
	snew[i] = '\0';
	return (snew);
}
