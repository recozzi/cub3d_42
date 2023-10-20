/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:01:50 by recozzi           #+#    #+#             */
/*   Updated: 2023/06/10 11:25:30 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
    The matrixlen() function calculates the length of the matrix pointed to by **ptr, 
	excluding the terminating null byte ('\0').
 * @return 
    The matrixlen() function returns the number of bytes in the matrix pointed to 
	by **ptr.
 */
size_t	ft_matrixlen(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}
