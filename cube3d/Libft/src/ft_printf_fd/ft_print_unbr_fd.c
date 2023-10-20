/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_nbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:25:11 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/20 19:00:32 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	This function writes an unsigned number.
 * @param n
	The number to be printed.
 * @param fd
	The fd where the unsigned number will be written.
 * @return
	The length of the printed number.
*/

size_t	ft_print_unbr_fd(long int n, int fd)
{
	char	arr[11];
	int		len;
	int		i;

	i = 10;
	len = 0;
	while (n >= 10)
	{
		arr[i--] = (n % 10) + 48;
		n /= 10;
	}
	if (n < 10)
		arr[i] = n + 48;
	len = 11 - i;
	write(fd, &arr[i], len);
	return (len);
}
