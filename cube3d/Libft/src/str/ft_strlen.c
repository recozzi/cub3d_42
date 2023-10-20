/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:32:24 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:34:19 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
    The strlen() function calculates the length of the string pointed to by s, 
	excluding the terminating null byte ('\0').
 * @return 
    The strlen() function returns the number of bytes in the string pointed to 
	by s.
 */
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
