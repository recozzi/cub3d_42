/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:30:46 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:34:44 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	Applies the function ’f’ on each character of the string passed as argument,
	passing its index as first argument; 
	Each character is passed by address to ’f’ to be modified if necessary.
 * @param s 
	The string on which to iterate.
 * @param f 
	The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
