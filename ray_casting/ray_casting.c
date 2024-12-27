/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:26:27 by ozahdi            #+#    #+#             */
/*   Updated: 2024/12/27 15:33:47 by ozahdi           ###   ########.fr       */
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
	player->redius = floor(SQUER / 7);
	player->speed = 15;
	player->rot_speed = 2 * (M_PI / 180);
	player->pl_x = player->pl_x * SQUER + floor(SQUER / 2);
	player->pl_y = player->pl_y * SQUER + floor(SQUER / 2);
	player->d_x = cos(degree_radian(player->rot_angel, 0)) * player->speed;
	player->d_y = sin(degree_radian(player->rot_angel, 0)) * player->speed;
}

void rander_2d_map(t_data *data, t_graph *mlx)
{
	mlx->mlx = mlx_init(WEIGHT, HEIGHT, "CUB3D", false);
	mlx->project = mlx_new_image(mlx->mlx, WEIGHT, HEIGHT);
	mlx->image = mlx_new_image(mlx->mlx, (data->weight - 1) * SQUER, data->height * SQUER);
	mlx_image_to_window(data->mlx->mlx, data->mlx->project, 0, 0);
	mlx_image_to_window(data->mlx->mlx, data->mlx->image, 0, 0);
	CastAllRays(data, data->player);
	//ft_fill_project(data, data->mlx);
	Randring3D(data, data->player);
	ft_put_map(data);
	mlx_loop_hook(data->mlx->mlx,ft_handek_actions, data);
	mlx_loop(mlx->mlx);
}

void ray_casting(t_data *data, t_graph *mlx)
{
	ft_init_data(data);
	rander_2d_map(data, mlx);
}