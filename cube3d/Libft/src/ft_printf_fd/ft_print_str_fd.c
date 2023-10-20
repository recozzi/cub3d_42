/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:12:47 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/20 19:00:07 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	This function writes a string char by char.
 * @param str
	The string to be printed.
 * @param fd
	The fd where the string will be written.
 * @return
	The length of the printed string.
*/

int	ft_print_str_fd(char *str, int fd)
{
	size_t	i;

	i = 0;
	if (!str)
		return (ft_print_str_fd("(null)", fd));
	while (str[i])
		ft_print_char_fd(str[i++], fd);
	return (i);
}
