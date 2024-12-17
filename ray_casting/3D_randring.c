/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_randring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:24:29 by ozahdi            #+#    #+#             */
/*   Updated: 2024/12/17 13:13:06 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_fill_project(t_data *data, t_graph *mlx)
{
	int i = 0;
	int j = 0;
	(void)data;
	while (i < HEIGHT)
	{
		j = -1;
		while (++j < WEIGHT)
		{
			if (i < HEIGHT / 2)
				mlx_put_pixel(mlx->project, j, i, 0xB3C8CFFF);
			else
				mlx_put_pixel(mlx->project, j, i, 0xF1F0E8FF);
		}
		i++;
	}
}

void	Randring3D(t_data *data, t_player *player)
{
	(void)player;
	ft_fill_project(data, data->mlx);
}