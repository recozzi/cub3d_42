/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:14:08 by recozzi           #+#    #+#             */
/*   Updated: 2023/10/20 18:28:25 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_set_map_2d(t_map *map)
{
	map->height = ft_matrixlen(map->matrix);
	map->width = ft_take_max_len(map->matrix);
}

static void	*ft_set_img_xpm(void *mlx_ptr, t_img *cp)
{
	return (mlx_xpm_file_to_image(mlx_ptr, cp->path_textures, &cp->width, &cp->height));
}

static char	*ft_get_img_addr(t_img *cp)
{
	return (mlx_get_data_addr(cp->img_ptr, &cp->bpp, &cp->line_len, &cp->endian));
}

static int	ft_get_img_data(t_map *map, void *mlx_ptr)
{
	map->north.img_ptr = ft_set_img_xpm(mlx_ptr, &map->north);
	map->south.img_ptr = ft_set_img_xpm(mlx_ptr, &map->south);
	map->west.img_ptr = ft_set_img_xpm(mlx_ptr, &map->west);
	map->east.img_ptr = ft_set_img_xpm(mlx_ptr, &map->east);
	if (!map->north.img_ptr || !map->south.img_ptr || !map->west.img_ptr || !map->east.img_ptr)
		return (ft_invalid_texture());
	map->north.img_addr = ft_get_img_addr(&map->north);
	map->south.img_addr = ft_get_img_addr(&map->south);
	map->west.img_addr = ft_get_img_addr(&map->west);
	map->east.img_addr = ft_get_img_addr(&map->east);
	return (0);
}

int	ft_info_game(t_cube *cube, char *path)
{
	int	fd;
	int	error_flag;

	error_flag = 0;
	fd = ft_open_map(path, ".cub");
	if (fd == -1)
		error_flag = 1;
	if (!error_flag && ft_check_textures(cube, fd))
		error_flag = 2;
	if (!error_flag && ft_map(&cube->map, fd))
		error_flag = 3;
	if (!error_flag && ft_check_after_map(fd))
		error_flag = 4;
	if (!error_flag && ft_get_img_data(&cube->map, cube->mlx_ptr))
		error_flag = 5;
	if (!error_flag)
		ft_set_map_2d(&cube->map);
	if (fd != -1)
		close(fd);
	return (error_flag);
}
