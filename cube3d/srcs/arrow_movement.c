/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:13:35 by recozzi           #+#    #+#             */
/*   Updated: 2023/10/20 18:24:49 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_move_pov_right(t_cube *cube)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cube->player.dir_x;
	old_plane_x = cube->player.plane_x;
	cube->player.dir_x = cube->player.dir_x * cos(-ROTATION_SPEED) - cube->player.dir_y * sin(-ROTATION_SPEED);
	cube->player.dir_y = old_dir_x * sin(-ROTATION_SPEED) +	cube->player.dir_y * cos(-ROTATION_SPEED);
	cube->player.plane_x = cube->player.plane_x * cos(-ROTATION_SPEED) - cube->player.plane_y * sin(-ROTATION_SPEED);
	cube->player.plane_y = old_plane_x * sin(-ROTATION_SPEED) + cube->player.plane_y * cos(-ROTATION_SPEED);
}

void	ft_move_pov_left(t_cube *cube)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cube->player.dir_x;
	old_plane_x = cube->player.plane_x;
	cube->player.dir_x = cube->player.dir_x * cos(ROTATION_SPEED) - cube->player.dir_y * sin(ROTATION_SPEED);
	cube->player.dir_y = old_dir_x * sin(ROTATION_SPEED) + cube->player.dir_y * cos(ROTATION_SPEED);
	cube->player.plane_x = cube->player.plane_x * cos(ROTATION_SPEED) - cube->player.plane_y * sin(ROTATION_SPEED);
	cube->player.plane_y = old_plane_x * sin(ROTATION_SPEED) + cube->player.plane_y * cos(ROTATION_SPEED);
}
