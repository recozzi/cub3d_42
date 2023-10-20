/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:28:53 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/20 11:36:10 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*! 
 @brief
	The calloc() function allocates memory for an array of nmemb elements of 
	size bytes each and returns a pointer to the allocated memory.
	The memory is set to zero.
	If nmemb or size is 0, then calloc() returns either NULL, or a unique
	pointer value that can later be successfully passed to free();
	If the multiplication of nmemb and size would result in integer overflow, 
	then calloc() returns an error.
 @return
	The calloc() function return a pointer to the allocated memory.  
	On error, these functions return NULL.  
	NULL may also be returned by a successful call to calloc() with nmemb or
	size equal to zero.
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
