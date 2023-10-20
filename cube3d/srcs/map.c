/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:14:34 by recozzi           #+#    #+#             */
/*   Updated: 2023/09/29 16:40:55 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_first_line(int fd)
{
	char	*line;
	char	*mapstr;

	line = get_next_line(fd);
	while (line && *line == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	mapstr = ft_strdup(line);
	free(line);
	return (mapstr);
}

char	**ft_read_map(int fd)
{
	char	**matrix;
	char	*mapstr;
	char	*line;
	char	*tmp;

	mapstr = ft_first_line(fd);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (*line == '\n')
			break ;
		tmp = ft_strjoin(mapstr, line);
		free(mapstr);
		free(line);
		line = NULL;
		mapstr = ft_custom_realloc(tmp, ft_strlen(tmp) + 1, sizeof(char));
	}
	free(line);
	line = NULL;
	matrix = ft_split(mapstr, '\n');
	free(mapstr);
	return (matrix);
}

int	ft_map(t_map *map, int fd)
{
	int	check_map;

	map->matrix = ft_read_map(fd);
	check_map = ft_check_valid_map(map->matrix);
	return (check_map);
}
