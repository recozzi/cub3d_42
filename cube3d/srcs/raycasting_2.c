/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:15:01 by recozzi           #+#    #+#             */
/*   Updated: 2023/10/20 18:30:08 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_wall_height(t_cam *cam, t_ray *ray)
{
	if (cam->side % 2 == 0)
		cam->vert_wall_d = (cam->side_d_x - cam->delta_d_x);
	else
		cam->vert_wall_d = (cam->side_d_y - cam->delta_d_y);
	if (cam->vert_wall_d < 0.000001)
		cam->vert_wall_d = 0.000001;
	ray->height = (int)((double)WINDOW_HEIGHT / cam->vert_wall_d);
	ray->start = -(ray->height) / 2 + WINDOW_HEIGHT / 2;
	if (ray->start < 0)
		ray->start = 0;
	ray->end = ray->height / 2 + WINDOW_HEIGHT / 2;
	if (ray->end >= WINDOW_HEIGHT)
		ray->end = WINDOW_HEIGHT - 1;
}

void	ft_texture_coord(t_cube *cube, t_cam *cam, t_ray *ray)
{
	if (cam->side % 2 == 0)
		ray->wall = cube->player.pos_y + cam->vert_wall_d * cam->raydir_y;
	else
		ray->wall = cube->player.pos_x + cam->vert_wall_d * cam->raydir_x;
	ray->wall -= (int)(ray->wall);
	ray->texture_x = (int)(ray->wall * (double)(TEXTURE_WIDTH));
	if (cam->side % 2 == 0 && cam->raydir_x > 0)
		ray->texture_x = TEXTURE_WIDTH - ray->texture_x - 1;
	if (cam->side % 2 == 1 && cam->raydir_y < 0)
		ray->texture_x = TEXTURE_WIDTH - ray->texture_x - 1;
	ray->jump = (double)TEXTURE_HEIGHT / (double)ray->height;
	ray->texture_pos = (ray->start - WINDOW_HEIGHT / 2 + ray->height / 2) * ray->jump;
}

void	ft_render(t_cube *cube, t_cam *cam, t_ray *ray, int column_counter)
{
	int		y;
	int		color;

	y = ray->start;
	while (y < ray->end)
	{
		color = 0;
		ray->texture_y = (int)ray->texture_pos % TEXTURE_HEIGHT;
		if (cam->side == 0)
			color = ft_pixel_texture(&cube->map.north, ray->texture_x, ray->texture_y);
		else if (cam->side == 1)
			color = ft_pixel_texture(&cube->map.west, ray->texture_x, ray->texture_y);
		else if (cam->side == 2)
			color = ft_pixel_texture(&cube->map.south, ray->texture_x, ray->texture_y);
		else if (cam->side == 3)
			color = ft_pixel_texture(&cube->map.east, ray->texture_x, ray->texture_y);
		ft_pixel_background(&cube->background, column_counter, y, color);
		ray->texture_pos += ray->jump;
		y++;
	}
}

void	ft_draw_wall(t_cube *cube, t_cam *cam, int column_counter)
{
	t_ray	ray;

	ft_wall_height(cam, &ray);
	ft_texture_coord(cube, cam, &ray);
	ft_render(cube, cam, &ray, column_counter);
}
