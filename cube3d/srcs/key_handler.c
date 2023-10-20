/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:14:24 by recozzi           #+#    #+#             */
/*   Updated: 2023/09/29 14:14:25 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_minimap_handler(t_cube *cube)
{
	(void)cube;
	printf("la minimappa ancora non c'e'\n");
}

void	ft_arrow_handler(int keycode, t_cube *cube)
{
	if (keycode == LEFT_ARR)
		ft_move_pov_left(cube);
	else if (keycode == RIGHT_ARR)
		ft_move_pov_right(cube);
}

void	ft_wasd_handler(int keycode, t_cube *cube)
{
	if (keycode == W)
		ft_move_plr_forward(cube);
	else if (keycode == S)
		ft_move_plr_backward(cube);
	else if (keycode == D)
		ft_move_plr_right(cube);
	else if (keycode == A)
		ft_move_plr_left(cube);
}

int	ft_key_handler(int keycode, t_cube *cube)
{
	if (keycode == ESC)
		ft_quit_game(cube);
	if (ft_iswasd(keycode))
		ft_wasd_handler(keycode, cube);
	if (ft_isarrow(keycode))
		ft_arrow_handler(keycode, cube);
	if (keycode == TAB)
		ft_minimap_handler(cube);
	ft_game_calculate(cube);
	return (0);
}
