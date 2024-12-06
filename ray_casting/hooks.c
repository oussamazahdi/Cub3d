/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:29:09 by ozahdi            #+#    #+#             */
/*   Updated: 2024/12/06 18:02:03 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_handek_actions(void *param)
{
	t_data *data = (t_data *)param;
	t_player *player = data->player;
	double movespeed = 0.0;
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_UP)){
		player->walk_dir = 1;
	}
	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_DOWN) || mlx_is_key_down(data->mlx->mlx, MLX_KEY_S)){
		player->walk_dir = -1;
	}
	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_RIGHT)){
		player->rot_angel += player->rot_speed;
		if (player->rot_angel > 2 * M_PI)
			player->rot_angel -= 2 * M_PI;
	}
	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_LEFT)){
		player->rot_angel -= player->rot_speed;
		if (player->rot_angel < 0)
			player->rot_angel += 2 * M_PI;
	}
	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_W))
		player->walk_dir = 1;
	movespeed = player->walk_dir * player->rot_speed;
	
	int x = player->pl_x + cos(player->rot_angel) * player->walk_dir * player->rot_speed * player->speed;
	int y = player->pl_y + sin(player->rot_angel) * player->walk_dir * player->rot_speed * player->speed;

	if (!ft_check_wall(data, x, y))
	{
		player->pl_x += cos(player->rot_angel) * player->walk_dir * player->rot_speed * player->speed;
		player->pl_y += sin(player->rot_angel) * player->walk_dir * player->rot_speed * player->speed;
	}
	ft_put_map(data);
}