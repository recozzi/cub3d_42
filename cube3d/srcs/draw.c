/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:14:00 by recozzi           #+#    #+#             */
/*   Updated: 2023/10/20 18:27:24 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_pixel_texture(t_img *texture, int x, int y)
{
	char	*pixel;

	pixel = texture->img_addr + (y * texture->line_len + x * (texture->bpp / 8));
	return (*(int *)pixel);
}

void	ft_pixel_background(t_img *background, int x, int y, int color)
{
	char	*pixel;

	pixel = background->img_addr + (y * background->line_len + x * (background->bpp / 8));
	*(int *)pixel = color;
}

void	ft_draw(t_img *background, int start_y, int until_y, int color)
{
	int	x;
	int	y;

	y = start_y;
	while (y < until_y)
	{
		x = -1;
		while (++x < background->width)
			ft_pixel_background(background, x, y, color);
		y++;
	}
}
