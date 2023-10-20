/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:39:49 by recozzi           #+#    #+#             */
/*   Updated: 2023/10/20 19:03:51 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_custom_realloc(void *ptr, size_t new_size, size_t nmemb_size)
{
	void	*new_ptr;

	if (!ptr)
		return (ft_calloc(new_size, nmemb_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = ft_calloc(new_size, nmemb_size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, new_size * nmemb_size);
	free(ptr);
	return (new_ptr);
}
