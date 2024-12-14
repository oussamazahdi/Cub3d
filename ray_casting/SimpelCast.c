/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SimpelCast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 13:38:29 by ozahdi            #+#    #+#             */
/*   Updated: 2024/12/14 13:50:00 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int wallcheckers(t_data *data, int x, int y)
{
	int i = floor(y / SQUER);
	int j = floor(x / SQUER);
	if (data->map[i][j] == '1')
		return 1;
	return 0;
}

void bresenham_Simpel(int y0, int x0, int y1, int x1, t_data *exec)
{
    int dx;
    int dy;
    int sx ;
    int sy ;
    int err;
    int e2;

    dx = abs(x1 - x0);
    dy = abs(y1 - y0);
    if (x0 < x1)
        sx = 1;
    else 
        sx = -1;
    if (y0 < y1)
        sy = 1;
    else
        sy = -1;
    err = dx - dy;
    if (x0 < 0 || y0 < 0)
	return;
    while (1)
    {
        mlx_put_pixel(exec->mlx->image, x0, y0, 0xFF6700FF);
        e2 = 2 * err;
        if (e2 > -dy)
        {
          	err -= dy;
          	x0 += sx;
        }
        if (e2 < dx)
         {
          	err += dx;
          	y0 += sy; 
        }
        if (x0 < 0 || y0 < 0 || x0 > exec->weight * 32 || y0 > exec->height * 32 ||  (x0 == x1 && y0 == y1) || wallcheckers(exec, x0, y0))
            break;
    }
    ft_release_keys(exec);
}

void SimpelCast(t_data *data)
{
	t_player *player = data->player;
	double ang = player->rot_angel - (degree_radian(FOV_ANG, 0) / 2);
	int dx, dy;
	int i = 0;
	while (i < RAY_NBR)
	{
		dx = player->pl_x + cos(ang) * 1080;
		dy = player->pl_y + sin(ang) * 1080;
		bresenham_Simpel(player->pl_y, player->pl_x, dy ,dx, data);
		ang += (degree_radian(FOV_ANG, 0) / RAY_NBR);
		i++;
	}
	
}