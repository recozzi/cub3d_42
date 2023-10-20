/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:14:54 by recozzi           #+#    #+#             */
/*   Updated: 2023/09/29 16:41:16 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_free_cp(t_img *img, void *mlx_ptr)
{
	free(img->path_textures);
	if (img->img_ptr)
		mlx_destroy_image(mlx_ptr, img->img_ptr);
}

static char	**ft_free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix && matrix[++i])
		ft_free((void **)&matrix[i]);
	free(matrix);
	matrix = NULL;
	return (matrix);
}

static void	ft_free_map(t_map *map, void *mlx_ptr)
{
	map->matrix = ft_free_matrix(map->matrix);
	ft_free_cp(&map->north, mlx_ptr);
	ft_free_cp(&map->south, mlx_ptr);
	ft_free_cp(&map->west, mlx_ptr);
	ft_free_cp(&map->east, mlx_ptr);
}

int	ft_invalid_texture(void)
{
	ft_printf_fd(2, "Error\nTexture not found\n");
	return (1);
}

int	ft_invalid_game(t_cube *cube)
{
	ft_free_map(&cube->map, cube->mlx_ptr);
	mlx_destroy_display(cube->mlx_ptr);
	free(cube->mlx_ptr);
	get_next_line(-42);
	return (1);
}

int	ft_quit_game(t_cube *cube)
{
	mlx_loop_end(cube->mlx_ptr);
	ft_free_map(&cube->map, cube->mlx_ptr);
	mlx_destroy_window(cube->mlx_ptr, cube->win_ptr);
	mlx_destroy_display(cube->mlx_ptr);
	free(cube->mlx_ptr);
	exit(0);
}
