/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:39:13 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:37:59 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	Outputs the integer ’n’ to the given file descriptor.
 * @param n 
	The integer to output.
 * @param fd 
	The file descriptor on which to write.
 */
void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	n;
	int				i;
	int				len;
	char			array[11];

	i = 10;
	array[i] = '0';
	if (nb >= 0)
		n = nb;
	else
		n = -nb;
	while (n > 0)
	{
		array[i] = (n % 10 + '0');
		n = (n / 10);
		i--;
	}
	if (nb < 0)
		array[i] = '-';
	else if (nb > 0)
		i++;
	len = 11 - i;
	write(fd, &array[i], len);
}
