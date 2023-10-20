/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:30:22 by recozzi           #+#    #+#             */
/*   Updated: 2023/03/23 15:42:02 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_print_str(char *str)
{
	size_t	i;

	i = 0;
	if (str == 0)
		return (ft_print_str("(null)"));
	while (str[i])
		ft_print_char(str[i++]);
	return (i);
}
