/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:15:06 by recozzi           #+#    #+#             */
/*   Updated: 2023/10/20 18:30:41 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_ray(t_cube *cube, t_cam *cam, int column_counter)
{
	cam->cam_x = 2 * column_counter / (double)WINDOW_WIDTH - 1;
	cam->raydir_x = cube->player.dir_x + cube->player.plane_x * cam->cam_x;
	cam->raydir_y = cube->player.dir_y + cube->player.plane_y * cam->cam_x;
	cam->mapcoord_x = cube->player.pos_x;
	cam->mapcoord_y = cube->player.pos_y;
	if (cam->raydir_x)
		cam->delta_d_x = fabs(1 / cam->raydir_x);
	else
		cam->delta_d_x = (double)INT_MAX;
	if (cam->raydir_y)
		cam->delta_d_y = fabs(1 / cam->raydir_y);
	else
		cam->delta_d_y = (double)INT_MAX;
}

void	ft_init_side_distance(t_cube *cube, t_cam *cam)
{
	if (cam->raydir_x < 0)
	{
		cam->step_x = -1;
		cam->side_d_x = (cube->player.pos_x - cam->mapcoord_x) * cam->delta_d_x;
	}
	else
	{
		cam->step_x = 1;
		cam->side_d_x = (cam->mapcoord_x + 1.0 - cube->player.pos_x) * cam->delta_d_x;
	}
	if (cam->raydir_y < 0)
	{
		cam->step_y = -1;
		cam->side_d_y = (cube->player.pos_y - cam->mapcoord_y) * cam->delta_d_y;
	}
	else
	{
		cam->step_y = 1;
		cam->side_d_y = (cam->mapcoord_y + 1.0 - cube->player.pos_y) * cam->delta_d_y;
	}
}

int	ft_wall_collision_detection(t_cube *cube, t_cam *cam)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (cam->side_d_x < cam->side_d_y)
		{
			cam->side_d_x += cam->delta_d_x;
			cam->mapcoord_x += cam->step_x;
			cam->side = 1 + cam->step_x;
		}
		else
		{
			cam->side_d_y += cam->delta_d_y;
			cam->mapcoord_y += cam->step_y;
			cam->side = 2 + cam->step_y;
		}
		if (cam->mapcoord_x < 0 || cam->mapcoord_x >= cube->map.height || cam->mapcoord_y < 0 || cam->mapcoord_y >= cube->map.width)
			break ;
		else if (cube->map.matrix[cam->mapcoord_x][cam->mapcoord_y] == '1')
			hit = 1;
	}
	return (hit);
}

void	ft_raycasting(t_cube *cube)
{
	t_cam	cam;
	int		column_counter;

	column_counter = 0;
	while (column_counter < WINDOW_WIDTH)
	{
		ft_init_ray(cube, &cam, column_counter);
		ft_init_side_distance(cube, &cam);
		if (ft_wall_collision_detection(cube, &cam))
			ft_draw_wall(cube, &cam, column_counter);
		column_counter++;
	}
}
