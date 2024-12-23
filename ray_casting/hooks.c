/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:29:09 by ozahdi            #+#    #+#             */
/*   Updated: 2024/12/17 17:13:35 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_handek_actions(void *param)
{
	t_data *data = (t_data *)param;
	t_player *player = data->player;
	data->update = false;
	double movespeed = 0.0;
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_UP)){
		data->update = true;
		player->walk_dir = 1;
	}
	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_DOWN) || mlx_is_key_down(data->mlx->mlx, MLX_KEY_S)){
		data->update = true;
		player->walk_dir = -1;
	}
	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_RIGHT)){
		data->update = true;
		player->rot_angel += player->rot_speed;
		if (player->rot_angel > 2 * M_PI)
			player->rot_angel -= 2 * M_PI;
	}
	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_LEFT)){
		data->update = true;
		player->rot_angel -= player->rot_speed;
		if (player->rot_angel < 0)
			player->rot_angel += 2 * M_PI;
	}
	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_W))
	{
		data->update = true;
		player->walk_dir = 1;
	}
	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_ESCAPE))
		exit (0);
	movespeed = player->walk_dir * player->rot_speed;
	
	int x = player->pl_x + cos(player->rot_angel) * player->walk_dir * player->rot_speed * player->speed;
	int y = player->pl_y + sin(player->rot_angel) * player->walk_dir * player->rot_speed * player->speed;

	if (!ft_check_wall(data, x, y))
	{
		player->pl_x += cos(player->rot_angel) * player->walk_dir * player->rot_speed * player->speed;
		player->pl_y += sin(player->rot_angel) * player->walk_dir * player->rot_speed * player->speed;
	}
	if (data->update == true)
	{
		ft_put_map(data);
		CastAllRays(data, player);
		Randring3D(data, player);
	}
}