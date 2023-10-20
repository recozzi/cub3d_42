/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cscelfo <cscelfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:14:29 by recozzi           #+#    #+#             */
/*   Updated: 2023/09/29 15:23:53 by cscelfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int ac, char **av)
{
	t_cube	cube;

	if (ac != 2)
		return (ft_ac_error(ac));
	ft_init_cube(&cube);
	if (ft_info_game(&cube, av[1]))
		return (ft_invalid_game(&cube));
	ft_get_player_pos(cube.map.matrix, &cube.player);
	ft_start_game(&cube);
	return (0);
}
