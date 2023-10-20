/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:26:28 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/20 20:44:43 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	This function writes a hexadecimal.
 * @param n
	The parameter to be converted and written.
 * @param format
	If lower or upper case.
 * @param fd
	The fd where the hex will be written.
 * @return
	The length of the printed hex.
*/

int	ft_print_hex_fd(unsigned int n, char format, int fd)
{
	char	*hex_arr;
	char	arr[16];
	int		i;
	int		len;

	i = 15;
	hex_arr = "0123456789abcdef";
	len = 0;
	while (n > 15)
	{
		arr[i--] = hex_arr[n % 16];
		if (format == 'X' && hex_arr[n % 16] >= 97 && hex_arr[n % 16] <= 122)
			arr[i + 1] -= 32;
		n /= 16;
	}
	if (n <= 15)
		arr[i] = hex_arr[n];
	if (format == 'X' && hex_arr[n % 16] >= 97 && hex_arr[n % 16] <= 122)
		arr[i] -= 32;
	len = 16 - i;
	write(fd, &arr[i], len);
	return (len);
}
