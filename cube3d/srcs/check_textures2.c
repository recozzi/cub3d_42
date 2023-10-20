/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:13:55 by recozzi           #+#    #+#             */
/*   Updated: 2023/10/20 18:27:10 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_check_color_in_depth(char *line_mover)
{
	int	i;
	int	num_commas;

	i = 0;
	num_commas = 0;
	while (1)
	{
		if (ft_atoi(&line_mover[i]) > 255 || ft_atoi(&line_mover[i]) < 0)
			return (1);
		while (line_mover[i] && ft_isdigit(line_mover[i]))
			i++;
		if (line_mover[i] && line_mover[i++] == ',')
			num_commas++;
		else if (!line_mover[i] || ft_isspace(line_mover[i]))
			break ;
		else
			return (1);
	}
	if (num_commas != 2)
		return (1);
	return (0);
}

int	ft_check_color_validity(int *color, char *line_mover, int i)
{
	int	check;
	int	j;

	check = 0;
	j = i;
	if (!line_mover[1] || !ft_isspace(line_mover[1]))
		check = ft_printf_fd(2, "Error\nNo color were given: %s", line_mover);
	else if (*color != -1)
		check = ft_printf_fd(2, "Error\nReassignment of color: %s", line_mover);
	if (!check)
	{
		j += ft_strlen_until(&line_mover[i], "\t\n\v\f\r ");
		if (!line_mover[j])
			check = ft_printf_fd(2, "Error\nNo color were given: %s", &line_mover[i]);
		else
		{
			if (ft_check_color_in_depth(&line_mover[i]))
				check = ft_printf_fd(2, "Error\nInvalid color given: %s", &line_mover[i]);
		}
	}
	return (check);
}

static int	ft_check_texture_extension(char *path)
{
	int		len;

	len = ft_strlen_until(path, "\t\n\v\f\r ");
	if (!ft_strncmp(&path[len - 4], ".xpm", 4))
		return (0);
	return (1);
}

int	ft_check_texture_validity(char *path_textures, char *line_mover, int i)
{
	int		check;
	int		j;

	check = 0;
	j = i;
	if (!line_mover[2] || !ft_isspace(line_mover[2]))
		check = ft_printf_fd(2, "Error\nInvalid texture given: %s", line_mover);
	else if (path_textures != 0)
		check = ft_printf_fd(2, "Error\nReassignment of texture: %s", line_mover);
	if (!check)
	{
		j += ft_strlen_until(&line_mover[i], "\t\n\v\f\r ");
		if (!line_mover[j])
			check = ft_printf_fd(2, "Error\nNo path given for texture: %s", &line_mover[i]);
		else
		{
			if (ft_check_texture_extension(&line_mover[i]))
				check = ft_printf_fd(2, "Extension error\nExpected a .xpm\n");
		}
	}
	return (check);
}
