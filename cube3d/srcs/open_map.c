/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recozzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:14:38 by recozzi           #+#    #+#             */
/*   Updated: 2023/10/20 18:30:10 by recozzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_extension(char *path, char *ext)
{
	int	path_len;
	int	ext_len;

	path_len = ft_strlen(path);
	ext_len = ft_strlen(ext);
	if (path_len <= ext_len)
		return (0);
	else if (path[path_len - (ext_len + 1)] == '.' || path[path_len - (ext_len + 1)] == '/')
		return (0);
	while (path_len > 0 && path[path_len] != '.')
		path_len--;
	if (!ft_strncmp(&path[path_len], ".cub\0", 5))
		return (1);
	return (0);
}

int	ft_check_isdir(char *path)
{
	int	fd;

	fd = open(path, O_DIRECTORY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

int	ft_open_map(char *path, char *ext)
{
	int	fd;
	int	error_flag;

	fd = open(path, O_RDONLY);
	error_flag = 0;
	if (!ft_check_extension(path, ext) || !ft_check_isdir(path))
		error_flag = 1;
	if (fd == -1)
		ft_printf_fd(2, "Error\nCan't open map file\n");
	else if (error_flag)
	{
		ft_printf_fd(2, "Error\nInvalid map file\n");
		close(fd);
	}
	return (fd);
}
