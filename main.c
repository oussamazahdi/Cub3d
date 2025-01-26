/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:39:17 by sslaoui           #+#    #+#             */
/*   Updated: 2025/01/26 16:02:17 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	l()
{
	system("leaks cub3d");
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int main(int ac, char **av)
{
	//atexit(l);
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
	if (!utils.map)
		return (0);
	player_detection(utils.map, &pl);
	if ((int)pl.pl_x == 0 || (int)pl.pl_y == 0)
    {
		write(2, "Cub3d: Error: You should to add player!\n", 41);
		return (free_map(utils.map), 1);
    }
	ray_casting(&utils, &mlx);
	free_map(utils.map);
}
