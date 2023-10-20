/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 11:25:21 by recozzi           #+#    #+#             */
/*   Updated: 2023/01/27 14:20:30 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_print_hex(unsigned int nbr, char format)
{
	int		i;
	int		len;
	char	array[10];
	char	*base;

	base = "0123456789abcdef";
	i = 9;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (nbr > 0)
	{
		if (format == 'X' && base[nbr % 16] >= 97 && base[nbr % 16] <= 102)
			array[--i] = base[nbr % 16] - 32;
		else
			array[--i] = base[nbr % 16];
		nbr /= 16;
	}
	len = 9 - i;
	write(1, &array[i], len);
	return (len);
}
