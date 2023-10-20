/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:14:24 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:35:41 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
 	The memset() function fills the first n bytes of the memory area pointed to 
	by s with the constant byte c.
 * @return 
 	The memset() function returns a pointer to the memory area s.
 */
void	*ft_memset(void *p_s, int c, size_t n)
{
	char	*s;
	char	t;
	size_t	i;

	s = (char *) p_s;
	t = (char) c;
	i = 0;
	while (i < n)
	{
		s[i] = t;
		i++;
	}
	return (s);
}
