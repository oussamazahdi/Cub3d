/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:26:27 by ozahdi            #+#    #+#             */
/*   Updated: 2024/12/08 17:06:25 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_init_data(t_data *data)
{
	t_player *player;

	player = data->player;
	player->turn_dir = 0; // -1 left or 1 right
	player->walk_dir = 0; // -1 back or 1 front
	player->rot_angel = M_PI / 2;
	player->redius = SQUER / 7;
	player->speed = 25;
	player->rot_speed = 2 * (M_PI / 180);
	player->ang = 30;
	player->pl_x = player->pl_x * SQUER + SQUER / 2;
	player->pl_y = player->pl_y * SQUER + SQUER / 2;
	player->d_x = cos(degree_radian(player->rot_angel, 0)) * player->speed;
	player->d_y = sin(degree_radian(player->rot_angel, 0)) * player->speed;
}

void rander_2d_map(t_data *data, t_graph *mlx)
{
	mlx->mlx = mlx_init(data->weight * SQUER, data->height * SQUER, "CUB3D", false);
	mlx->image = mlx_new_image(mlx->mlx, data->weight * SQUER, data->height * SQUER);
	mlx_image_to_window(data->mlx->mlx, data->mlx->image, 0, 0);
	ft_put_map(data);
	mlx_loop_hook(data->mlx->mlx,ft_handek_actions, data);
	mlx_loop(mlx->mlx);
}

void ray_casting(t_data *data, t_graph *mlx)
{
	ft_init_data(data);
	rander_2d_map(data, mlx);
}