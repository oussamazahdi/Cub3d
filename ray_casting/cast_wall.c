/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 18:14:18 by ozahdi            #+#    #+#             */
/*   Updated: 2024/12/08 16:22:00 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void put_inter(t_data *data, int x, int y)
{
	int i = y - 2;
	int j= x - 2;
	while (i < y + 3)
	{
		j= x - 2;
		while (j < x + 3)
		{
			mlx_put_pixel(data->mlx->image, j, i, 0x3D3BF3FF);
			j++;
		}
		i++;
	}
}

int RayWall(t_data *data, int x, int y)
{
	if (data->map[y / SQUER] && data->map[y / SQUER][x / SQUER] && data->map[y / SQUER][x / SQUER] == '1')
		return 1;
	return 0;
}

void	RayFacing(t_rays *ray)
{
	ray->facing_down = 0;
	ray->facing_left = 0;
	ray->facing_right = 0;
	ray->facing_up = 0;
	if (ray->ray_ang > 0 && ray->ray_ang < M_PI)
		ray->facing_down = 1;
	else
		ray->facing_up = 1;
	if (ray->ray_ang > (M_PI / 2) && ray->ray_ang < (3 * M_PI) / 2)
		ray->facing_left = 1;
	else
		ray->facing_right = 1;
}

void cast(t_data *data, t_player *player, t_rays *ray, int ColumId)
{
	(void) data;
	(void) ColumId;
	RayFacing(ray);
	ray->yintercept = floor(player->pl_y / SQUER) * SQUER;
	if (ray->facing_down)
		ray->yintercept += SQUER;
	ray->xintercept = player->pl_x + (player->pl_y - ray->yintercept) / tan(ray->ray_ang);
	ray->ystep = SQUER;
	if (ray->facing_up)
		ray->ystep *= -1;
	ray->xstep = ray->ystep / tan(ray->ray_ang);
	if ((ray->facing_left && ray->xstep > 0) || (ray->facing_right && ray->xstep < 0))
		ray->xstep *= -1;
	ray->nextHorzTouchX = ray->xintercept;
	ray->nextHorzTouchY = ray->yintercept;
	if (ray->facing_up)
		ray->nextHorzTouchY--;
	while(ray->nextHorzTouchX >= 0 && ray->nextHorzTouchX <= data->weight * SQUER && ray->nextHorzTouchY >= 0 && ray->nextHorzTouchY <= data->height * SQUER)
	{
		if (RayWall(data, ray->nextHorzTouchX, ray->nextHorzTouchY))
		{
			ray->HorizontalWallHit = true;
			ray->wallhitx = ray->nextHorzTouchX;
			ray->wallhity = ray->nextHorzTouchY;
			break;
		}
		else
		{
			ray->nextHorzTouchX += ray->xstep;
			ray->nextHorzTouchY += ray->ystep;
		}
	}
	
	//bresenham(data->player->pl_y, data->player->pl_x, ray->wallhity, ray->wallhitx, data);
}

void initray(t_rays *ray, t_data *data)
{
	ray->ray_ang = data->player->rot_angel - (degree_radian(FOV_ANG, 0) / 2);
	ray->wallhitx = 0;
	ray->wallhity = 0;
	ray->distance = 0;
	ray->VerticalWallHit = false;
	ray->HorizontalWallHit = false;
	//ray->WallHitFlag = false;
}

void		CastAllRays(t_data *data, t_player *player)
{
	t_rays	ray;
	int		i;
	int		columId;
	double	plus;
	//int dx, dy;

	columId = 0;
	data->rays = &ray;
	initray(&ray, data);
	i = -1;
	plus = degree_radian(FOV_ANG, 0) / RAY_NBR;
	while (++i < RAY_NBR)
	{
		cast(data, player, &ray, columId);
		//dx = data->player->pl_x + cos(ray.ray_ang) * 70;
		//dy = data->player->pl_y + sin(ray.ray_ang) * 70;
		//bresenham(data->player->pl_y, data->player->pl_x, dy, dx, data);
		ray.ray_ang += plus;
		ray.ray_ang = normalaize_angle(ray.ray_ang);
		//printf()
		columId++;
	}
}