/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:34:41 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:35:05 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_countnb(int num)
{
	int	i;

	i = 1;
	if (num < 0)
		i++;
	while (num / 10)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

/*!
 * @brief 
	Allocates (with malloc(3)) and returns a string	representing the integer 
	received as an argument;
	Negative numbers must be handled.
 * @param n 
	the integer to convert.
 * @return 
	The string representing the integer.
	NULL if the allocation fails.
 */
char	*ft_itoa(int n)
{
	unsigned int	nb;
	unsigned int	i;
	char			*s;

	nb = n;
	i = ft_countnb(n);
	s = (char *)malloc(sizeof(char) * i + 1);
	if (!s)
		return (0);
	s[i] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		s[0] = '-';
		nb = -n;
	}
	while (nb)
	{
		s[--i] = nb % 10 + 48;
		nb = nb / 10;
	}
	return (s);
}
