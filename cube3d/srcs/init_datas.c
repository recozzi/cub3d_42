/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_datas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:14:12 by recozzi           #+#    #+#             */
/*   Updated: 2023/09/29 14:14:13 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_init_background(t_img *background)
{
	background->path_textures = NULL;
	background->img_ptr = NULL;
	background->img_addr = NULL;
	background->bpp = 0;
	background->endian = 0;
	background->height = WINDOW_HEIGHT;
	background->width = WINDOW_WIDTH;
}

void	ft_init_cp(t_img *img)
{
	img->path_textures = NULL;
	img->img_ptr = NULL;
	img->img_addr = NULL;
	img->bpp = 0;
	img->endian = 0;
	img->height = 0;
	img->width = 0;
}

void	ft_init_map(t_map *map)
{
	map->matrix = NULL;
	map->width = 0;
	map->height = 0;
	map->floor_color = -1;
	map->ceiling_color = -1;
	ft_init_cp(&map->north);
	ft_init_cp(&map->south);
	ft_init_cp(&map->west);
	ft_init_cp(&map->east);
}

void	ft_init_player_info(t_info *player)
{
	player->pos_x = 0;
	player->pos_y = 0;
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
}

void	ft_init_cube(t_cube *cube)
{
	cube->mlx_ptr = mlx_init();
	cube->win_ptr = NULL;
	cube->recalculate = 1;
	ft_init_map(&cube->map);
	ft_init_player_info(&cube->player);
	ft_init_background(&cube->background);
}
