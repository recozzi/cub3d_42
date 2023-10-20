/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:23:55 by recozzi           #+#    #+#             */
/*   Updated: 2023/01/27 14:17:55 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_print_pointer(uintptr_t ptr)
{
	int		i;
	int		len;
	char	arr[10];
	char	*base;

	i = 9;
	base = "0123456789abcdef";
	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	while (ptr > 0)
	{
		arr[i--] = base[ptr % 16];
		ptr /= 16;
	}
	write(1, "0x", 2);
	len = 10 - (++i);
	write(1, &arr[i], len);
	return (len + 2);
}
