/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 17:02:46 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:35:10 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*! 
 @brief
	The atoi() function converts the initial portion of the string pointed to
	by nptr to int. This function does not detect errors.
 @return
	The converted value or 0 on error.
*/
int	ft_atoi(const char *nptr)
{
	char	*ptr;
	int		sign;
	int		res;

	ptr = (char *)nptr;
	sign = 1;
	res = 0;
	while (*ptr == 32 || (*ptr >= 9 && *ptr <= 13))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign *= -1;
		ptr++;
	}
	while (*ptr >= 48 && *ptr <= 57)
	{
		res = (res * 10) + (*ptr - 48);
		ptr++;
	}
	return (res * sign);
}
