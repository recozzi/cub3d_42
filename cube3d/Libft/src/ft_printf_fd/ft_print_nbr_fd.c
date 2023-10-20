/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:00:33 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/20 20:44:28 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	This function writes a number.
 * @param n
	The parameter to be written.
 * @param fd
	The fd where the number will be written.
 * @return
	The length of the printed nbr.
*/

int	ft_print_nbr_fd(int n, int fd)
{
	char			arr[11];
	int				i;
	int				len;
	unsigned int	cn;

	i = 10;
	len = 0;
	cn = n;
	if (n < 0)
	{
		len = 1;
		cn = -n;
	}
	while (cn >= 10)
	{
		arr[i--] = (cn % 10) + 48;
		cn /= 10;
	}
	if (cn < 10)
		arr[i] = cn + 48;
	if (len == 1)
		arr[--i] = '-';
	len = 11 - i;
	write(fd, &arr[i], len);
	return (len);
}
