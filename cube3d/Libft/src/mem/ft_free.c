/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:38:30 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:36:04 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*!
 * @brief 
	If the ptr is not NULL, it is freed and set to NULL.
 * @return 
 	NULL.
 */
void	*ft_free(void **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = 0;
	}
	return (*ptr);
}
