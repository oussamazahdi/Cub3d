/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:39:17 by sslaoui           #+#    #+#             */
/*   Updated: 2025/01/17 17:50:30 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int main(int ac, char **av)
{
	t_data	utils;
	t_player	pl;
	t_graph	mlx;
	int	fd;

	if (ac != 2)
		return printf("bad arg!"), 1;
	utils.player = &pl;
	utils.mlx = &mlx;
	utils_init(&utils, av[1]);
	parsing_map(&utils, &fd);
	player_detection(utils.map, &pl);
	ray_casting(&utils, &mlx);
}
