/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:15:10 by recozzi           #+#    #+#             */
/*   Updated: 2023/10/20 18:31:30 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_reset_background(t_img *background, int ceiling, int floor)
{
	ft_draw(background, 0, background->height / 2, ceiling);
	ft_draw(background, background->height / 2, background->height, floor);
}

void	ft_game_calculate(t_cube *cube)
{
	cube->background.img_ptr = mlx_new_image(cube->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	cube->background.img_addr = mlx_get_data_addr(cube->background.img_ptr, &cube->background.bpp, &cube->background.line_len, &cube->background.endian);
	ft_reset_background(&cube->background, cube->map.ceiling_color, cube->map.floor_color);
	ft_raycasting(cube);
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->background.img_ptr, 0, 0);
	mlx_destroy_image(cube->mlx_ptr, cube->background.img_ptr);
}

void	ft_start_game(t_cube *cube)
{
	cube->win_ptr = mlx_new_window(cube->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	ft_game_calculate(cube);
	mlx_hook(cube->win_ptr, KEY_PRESS, 1l << 0, &ft_key_handler, cube);
	mlx_hook(cube->win_ptr, DESTROY_BUTTON, 1l << 17, &ft_quit_game, cube);
	mlx_loop(cube->mlx_ptr);
}
