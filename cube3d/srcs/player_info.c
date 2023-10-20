/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:14:45 by recozzi           #+#    #+#             */
/*   Updated: 2023/09/29 14:14:46 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	set_plr_pov(double *v_x, double *v_y, double val_x, double val_y)
{
	*v_x = val_x;
	*v_y = val_y;
}

static void	ft_get_player_pov(t_info *player, char direction)
{
	if (direction == 'N')
	{
		set_plr_pov(&player->dir_x, &player->dir_y, -1, 0);
		set_plr_pov(&player->plane_x, &player->plane_y, 0, FOV);
	}
	else if (direction == 'S')
	{
		set_plr_pov(&player->dir_x, &player->dir_y, 1, 0);
		set_plr_pov(&player->plane_x, &player->plane_y, 0, -FOV);
	}
	else if (direction == 'W')
	{
		set_plr_pov(&player->dir_x, &player->dir_y, 0, -1);
		set_plr_pov(&player->plane_x, &player->plane_y, -FOV, 0);
	}
	else if (direction == 'E')
	{
		set_plr_pov(&player->dir_x, &player->dir_y, 0, 1);
		set_plr_pov(&player->plane_x, &player->plane_y, FOV, 0);
	}
	else
		ft_printf_fd(2, "Invalid player direction: '%c'\n", direction);
}

void	ft_get_player_pos(char **map, t_info *player)
{
	int	x_axis;
	int	y_axis;

	x_axis = 0;
	while (map[x_axis])
	{
		y_axis = 0;
		while (map[x_axis][y_axis])
		{
			if (ft_strchr("NSWE", map[x_axis][y_axis]))
			{
				player->pos_x = x_axis + 0.5;
				player->pos_y = y_axis + 0.5;
				ft_get_player_pov(player, map[x_axis][y_axis]);
				map[x_axis][y_axis] = '0';
				return ;
			}
			y_axis++;
		}
		x_axis++;
	}
}
