/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:28:54 by ozahdi            #+#    #+#             */
/*   Updated: 2024/11/25 14:43:34 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ray_casting(t_map *data)
{
	data->mlx = mlx_init(data->big_len * 32, data->lines_number * 32, "Cub3D", false);
	mlx_clear(data->mlx, 0x000000FF);
	mlx_loop(data->mlx);
}