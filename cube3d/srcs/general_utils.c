/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:14:04 by recozzi           #+#    #+#             */
/*   Updated: 2023/10/20 18:27:51 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_ac_error(int ac)
{
	if (ac == 1)
		ft_printf_fd(2, "Error\nMissing map '*.cub' argument\n");
	else
		ft_printf_fd(2, "Error\nToo many arguments\n");
	return (1);
}

int	ft_take_max_len(char **mat)
{
	int	i;
	int	max_len;
	int	potential_len;

	i = -1;
	max_len = 0;
	while (mat[++i])
	{
		potential_len = ft_strlen(mat[i]);
		if (potential_len > max_len)
			max_len = potential_len;
	}
	return (max_len);
}
