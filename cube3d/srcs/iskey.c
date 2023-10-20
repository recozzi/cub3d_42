/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iskey.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:14:18 by recozzi           #+#    #+#             */
/*   Updated: 2023/09/29 14:14:21 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	ft_isarrow(int keycode)
{
	return (keycode == LEFT_ARR || keycode == RIGHT_ARR);
}

bool	ft_iswasd(int keycode)
{
	return (keycode == W || keycode == A || keycode == S || keycode == D);
}
