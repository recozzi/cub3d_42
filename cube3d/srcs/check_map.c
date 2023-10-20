/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:13:40 by recozzi           #+#    #+#             */
/*   Updated: 2023/10/20 18:25:59 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_after_map(int fd)
{
	char	*line;
	int		check;

	check = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		else if (*line != '\n')
		{
			ft_printf_fd(2, "Error\nOther elements found after map.\n");
			check = 1;
			break ;
		}
	}
	free(line);
	return (check);
}

int	ft_check_map_elements_2(char **map, char *player_orientation)
{
	int	x_axis;
	int	y_axis;
	int	player_orientation_count;

	y_axis = 0;
	player_orientation_count = 0;
	while (map[y_axis])
	{
		x_axis = 0;
		while (map[y_axis][x_axis])
		{
			if (ft_strchr(player_orientation, map[y_axis][x_axis]))
				player_orientation_count++;
			x_axis++;
		}
		y_axis++;
	}
	if (player_orientation_count != 1)
		return (1);
	return (0);
}

int	ft_check_map_elements(char **map, char *valid_elements)
{
	int	x_axis;
	int	y_axis;
	int	check_elements;

	y_axis = 0;
	while (map[y_axis])
	{
		x_axis = 0;
		while (map[y_axis][x_axis])
		{
			if (!ft_strchr(valid_elements, map[y_axis][x_axis]))
				return (1);
			x_axis++;
		}
		y_axis++;
	}
	check_elements = ft_check_map_elements_2(map, &valid_elements[3]);
	return (check_elements);
}

int	ft_check_around(char **map, int y_axis, int x_axis)
{
	if (!map[y_axis - 1][x_axis] || !map[y_axis + 1] || !map[y_axis + 1][x_axis])
		return (1);
	if (!map[y_axis][x_axis - 1] || !map[y_axis][x_axis + 1])
		return (1);
	if (map[y_axis][x_axis - 1] == 32 || map[y_axis][x_axis + 1] == 32)
		return (1);
	if (map[y_axis - 1][x_axis] == 32 || map[y_axis + 1][x_axis] == 32)
		return (1);
	return (0);
}

int	ft_check_map_walls(char **map, char *elements)
{
	int	x_axis;
	int	y_axis;

	y_axis = 0;
	while (map[y_axis])
	{
		x_axis = 0;
		while (map[y_axis][x_axis])
		{
			if (ft_strchr(elements, map[y_axis][x_axis]))
			{
				if (ft_check_around(map, y_axis, x_axis))
					return (1);
			}
			x_axis++;
		}
		y_axis++;
	}
	return (0);
}

int	ft_check_valid_map(char **map)
{
	if (!map)
		return (ft_printf_fd(2, "Error\nMap not found!\n"));
	else if (ft_check_map_elements(map, " 01NSEW"))
		return (ft_printf_fd(2, "Error\nInvalid elements in map!\n"));
	else if (ft_check_map_walls(map, "0NSEW"))
		return (ft_printf_fd(2, "Unclosed walls or invalid spaces found!\n"));
	return (0);
}
