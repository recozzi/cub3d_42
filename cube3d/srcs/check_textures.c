/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:13:51 by recozzi           #+#    #+#             */
/*   Updated: 2023/09/29 15:19:51 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_set_color(int *color, char **line_ref)
{
	char	*line_mover;
	int		i;
	int		red;
	int		green;
	int		blue;

	line_mover = *line_ref;
	i = 1;
	while (ft_isspace(line_mover[++i]))
		continue ;
	if (ft_check_color_validity(color, line_mover, i))
		return (-1);
	red = ft_atoi(&line_mover[i]);
	i += ft_strlen_until(&line_mover[i], ",") + 1;
	green = ft_atoi(&line_mover[i]);
	i += ft_strlen_until(&line_mover[i], ",") + 1;
	blue = ft_atoi(&line_mover[i]);
	i += ft_strlen_until(&line_mover[i], "\t\n\v\f\r ");
	*color = (red << 16) + (green << 8) + blue;
	line_mover += i;
	*line_ref = line_mover;
	return (1);
}

static int	ft_set_texture_path(t_img *img, char **line_ref)
{
	char	*line_mover;
	int		i;
	int		path_len;

	line_mover = *line_ref;
	i = 2;
	while (ft_isspace(line_mover[i]))
		i++;
	if (ft_check_texture_validity(img->path_textures, line_mover, i))
		return (-1);
	path_len = ft_strlen_until(&line_mover[i], "\t\n\v\f\r ");
	img->path_textures = ft_substr(&line_mover[i], 0, path_len);
	line_mover += path_len + i;
	*line_ref = line_mover;
	return (1);
}

static int	ft_get_wall_texture(t_cube *cube, char **line_ref)
{
	int		error_check;

	error_check = 0;
	if (!ft_strncmp(*line_ref, "NO", 2))
		error_check = ft_set_texture_path(&cube->map.north, line_ref);
	else if (!ft_strncmp(*line_ref, "SO", 2))
		error_check = ft_set_texture_path(&cube->map.south, line_ref);
	else if (!ft_strncmp(*line_ref, "WE", 2))
		error_check = ft_set_texture_path(&cube->map.west, line_ref);
	else if (!ft_strncmp(*line_ref, "EA", 2))
		error_check = ft_set_texture_path(&cube->map.east, line_ref);
	else if (!ft_strncmp(*line_ref, "F", 1))
		error_check = ft_set_color(&cube->map.floor_color, line_ref);
	else if (!ft_strncmp(*line_ref, "C", 1))
		error_check = ft_set_color(&cube->map.ceiling_color, line_ref);
	else if (**line_ref)
	{
		ft_printf_fd(2, "Error\nInvalid map info\n");
		error_check = -1;
	}
	return (error_check);
}

static int	ft_get_info_img(t_cube *cube, char *line, int info_count)
{
	int		error_check;

	while (*line)
	{
		while (ft_isspace(*line))
			line++;
		error_check = ft_get_wall_texture(cube, &line);
		if (error_check == -1)
			return (-1);
		info_count += error_check;
	}
	return (info_count);
}

int	ft_check_textures(t_cube *cube, int fd)
{
	char	*line;
	int		info_count;

	line = NULL;
	info_count = 0;
	while (info_count != -1 && info_count < 6)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		else if (*line == '\n')
			continue ;
		info_count = ft_get_info_img(cube, line, info_count);
	}
	free(line);
	if (info_count == -1)
		return (1);
	return (0);
}
