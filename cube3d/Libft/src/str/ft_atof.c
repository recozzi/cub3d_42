/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:37:55 by recozzi           #+#    #+#             */
/*   Updated: 2023/05/27 14:56:04 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*! 
 @brief
	The atof() function converts the initial portion of the string pointed to
	by nptr to double. This function does not detect errors.
 @return
	The converted value or 0 on error.
*/
double	ft_atof(const char *nptr)
{
	double	res;
	double	resf;
	char	*ptr;
	int		len;
	int		sign;

	sign = 1;
	ptr = (char *)nptr;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign *= -1;
		ptr++;
	}
	res = (double)ft_atoi(ptr);
	while (*ptr && *ptr != '.')
		ptr++;
	if (*ptr == '.')
		ptr++;
	resf = (double)ft_atoi(ptr);
	len = ft_strlen(ptr);
	while (len--)
		resf /= 10;
	return ((res + resf) * sign);
}
