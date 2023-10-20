/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:15:15 by recozzi           #+#    #+#             */
/*   Updated: 2023/09/29 14:15:17 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_move_plr_left(t_cube *cube)
{
	int		move_x;
	int		move_y;
	double	speed;
	double	wall_offset;

	speed = cube->player.dir_y * SPEED_MOVEMENT;
	wall_offset = cube->player.dir_y * WALL_CHANGE;
	move_x = (int)(cube->player.pos_x - speed - wall_offset);
	move_y = (int)(cube->player.pos_y);
	if (move_x >= 0 || move_x < cube->map.height)
		if (cube->map.matrix[move_x][move_y] != '1')
			cube->player.pos_x -= speed;
	speed = cube->player.dir_x * SPEED_MOVEMENT;
	wall_offset = cube->player.dir_x * WALL_CHANGE;
	move_x = (int)(cube->player.pos_x);
	move_y = (int)(cube->player.pos_y + speed + wall_offset);
	if (move_y >= 0 || move_y < cube->map.width)
		if (cube->map.matrix[move_x][move_y] != '1')
			cube->player.pos_y += speed;
}

void	ft_move_plr_right(t_cube *cube)
{
	int		move_x;
	int		move_y;
	double	speed;
	double	wall_offset;

	speed = cube->player.dir_y * SPEED_MOVEMENT;
	wall_offset = cube->player.dir_y * WALL_CHANGE;
	move_x = (int)(cube->player.pos_x + speed + wall_offset);
	move_y = (int)(cube->player.pos_y);
	if (move_x >= 0 || move_x < cube->map.height)
		if (cube->map.matrix[move_x][move_y] != '1')
			cube->player.pos_x += speed;
	speed = cube->player.dir_x * SPEED_MOVEMENT;
	wall_offset = cube->player.dir_x * WALL_CHANGE;
	move_x = (int)(cube->player.pos_x);
	move_y = (int)(cube->player.pos_y - speed - wall_offset);
	if (move_y >= 0 || move_y < cube->map.width)
		if (cube->map.matrix[move_x][move_y] != '1')
			cube->player.pos_y -= speed;
}

void	ft_move_plr_backward(t_cube *cube)
{
	int		move_x;
	int		move_y;
	double	speed;
	double	wall_offset;

	speed = cube->player.dir_x * SPEED_MOVEMENT;
	wall_offset = cube->player.dir_x * WALL_CHANGE;
	move_x = (int)(cube->player.pos_x - speed - wall_offset);
	move_y = (int)(cube->player.pos_y);
	if (move_x >= 0 || move_x < cube->map.height)
		if (cube->map.matrix[move_x][move_y] != '1')
			cube->player.pos_x -= speed;
	speed = cube->player.dir_y * SPEED_MOVEMENT;
	wall_offset = cube->player.dir_y * WALL_CHANGE;
	move_x = (int)(cube->player.pos_x);
	move_y = (int)(cube->player.pos_y - speed - wall_offset);
	if (move_y >= 0 || move_y < cube->map.width)
		if (cube->map.matrix[move_x][move_y] != '1')
			cube->player.pos_y -= speed;
}

void	ft_move_plr_forward(t_cube *cube)
{
	int		move_x;
	int		move_y;
	double	speed;
	double	wall_offset;

	speed = cube->player.dir_x * SPEED_MOVEMENT;
	wall_offset = cube->player.dir_x * WALL_CHANGE;
	move_x = (int)(cube->player.pos_x + speed + wall_offset);
	move_y = (int)(cube->player.pos_y);
	if (move_x >= 0 || move_x < cube->map.height)
		if (cube->map.matrix[move_x][move_y] != '1')
			cube->player.pos_x += speed;
	speed = cube->player.dir_y * SPEED_MOVEMENT;
	wall_offset = cube->player.dir_y * WALL_CHANGE;
	move_x = (int)(cube->player.pos_x);
	move_y = (int)(cube->player.pos_y + speed + wall_offset);
	if (move_y >= 0 || move_y < cube->map.width)
		if (cube->map.matrix[move_x][move_y] != '1')
			cube->player.pos_y += speed;
}
