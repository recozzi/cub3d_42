/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:34:00 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:37:50 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	Outputs the character ’c’ to the given file descriptor.
 * @param c 
	The character to output.
 * @param fd 
	The file descriptor on which to write.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
