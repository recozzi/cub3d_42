/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:48:13 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/20 20:44:30 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	This function writes the address of a pointer.
 * @param ptr
	The parameter to be printed.
 * @param fd
	The fd where the pointer address will be written.
 * @return
	The length of the printed pointer + 2 for 0x.
*/

int	ft_print_ptr_fd(uintptr_t ptr, int fd)
{
	char	*hex_arr;
	char	arr[16];
	int		i;
	int		len;

	hex_arr = "0123456789abcdef";
	i = 15;
	if (ptr == 0)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	while (ptr > 0)
	{
		arr[i] = hex_arr[ptr % 16];
		ptr /= 16;
		i--;
	}
	write(fd, "0x", 2);
	len = 16 - (++i);
	write(fd, &arr[i], len);
	return (len + 2);
}
