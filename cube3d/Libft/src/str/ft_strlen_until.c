/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:09:55 by cscelfo           #+#    #+#             */
/*   Updated: 2023/10/20 19:05:07 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_strlen_until(char *str, char *until)
{
	int	i;

	i = 0;
	while (str && str[i] && !ft_strchr(until, str[i]))
		i++;
	return (i);
}
