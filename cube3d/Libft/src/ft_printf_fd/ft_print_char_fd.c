/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:09:23 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/20 20:44:47 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	This function writes a char in a specific fd.
 * @param c
	The parameter to be written.
 * @param fd
	The fd where the char will be written.
 * @return
	Just 1.
*/

int	ft_print_char_fd(int c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
