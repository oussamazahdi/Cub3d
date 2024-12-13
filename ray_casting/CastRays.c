/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CastRays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:04:10 by ozahdi            #+#    #+#             */
/*   Updated: 2024/12/13 14:07:07 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void put_inter(t_data *data, int x, int y)
{
	int i = y - 2;
	int j= x - 2;
	while (i < y + 2)
	{
		j= x - 2;
		while (j < x + 2)
		{
			mlx_put_pixel(data->mlx->image, j, i, 0x03045eFF);
			j++;
		}
		i++;
	}
}

double NormalizeAngle(double angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return angle;
}


void RayFacing(t_cast *ray, t_facing *facing)
{
	facing->facing_down = 0;
	facing->facing_left = 0;
	facing->facing_right = 0;
	facing->facing_up = 0;
	if (ray->ray_ang > 0 && ray->ray_ang < M_PI)
		facing->facing_down = 1;
	else
		facing->facing_up = 1;
	//if (ray->ray_ang > (M_PI / 2) && ray->ray_ang < (3 * M_PI) / 2)
	//	facing->facing_left = 1;
	//else
	//	facing->facing_right = 1;
	if (ray->ray_ang < (M_PI * 0.5) || ray->ray_ang > 1.5 * M_PI)
		facing->facing_right = 1;
	else
		facing->facing_left = 1;
}
//void RayFacing(t_data *data, t_facing *facing)
//{
//	t_player *player = data->player;
//	facing->facing_down = 0;
//	facing->facing_left = 0;
//	facing->facing_right = 0;
//	facing->facing_up = 0;
//	if (player->rot_angel > 0 && player->rot_angel < M_PI)
//		facing->facing_down = 1;
//	else
//		facing->facing_up = 1;
//	//if (ray->ray_ang > (M_PI / 2) && ray->ray_ang < (3 * M_PI) / 2)
//	//	facing->facing_left = 1;
//	//else
//	//	facing->facing_right = 1;
//	if (player->rot_angel < (M_PI * 0.5) || player->rot_angel > 1.5 * M_PI)
//		facing->facing_right = 1;
//	else
//		facing->facing_left = 1;
//}

int RayWall(t_data *data, int x, int y)
{
	if (data->map[y / SQUER] && data->map[y / SQUER][x / SQUER] && data->map[y / SQUER][x / SQUER] == '1')
		return 1;
	return 0;
}

	//int i = ray->yintercept / SQUER;
	//int j = ray->xintercept / SQUER;
	//if (data->map && data->map[i] && data->map[i][j] && data->map[i][j] == '1')
	//	printf("You hit a wall!\n");
	//else
	//	printf("We dont found a wall yet!\n");
	//if (ray->xintercept >= 0 && ray->yintercept >= 0 && ray->xintercept < data->weight * SQUER && ray->yintercept < data->height * SQUER)
	//	put_inter(data, ray->xintercept, ray->yintercept);
void VerticatIntercept(t_cast *ray, t_data *data, t_player *player, t_facing *facing)
{
	ray->xintercept = floor(player->pl_x / SQUER) * SQUER;
	ray->yintercept = player->pl_y + (ray->xintercept - player->pl_x) * tan(ray->ray_ang); 
	if (facing->facing_right == 1)
		ray->xintercept += SQUER;
	ray->xstep = SQUER;
	ray->ystep = ray->xstep * tan(ray->ray_ang);
	if (facing->facing_left == 1)
		ray->xstep *= -1;
	if ((facing->facing_up && ray->ystep > 0) || (facing->facing_down && ray->ystep < 0))
		ray->ystep *= -1;
	ray->VWallHitx = ray->xintercept;
	ray->VWallHity = ray->yintercept;
	if (facing->facing_left)
		ray->VWallHitx--;
	while (ray->VWallHitx >= 0 && ray->VWallHity >= 0 && ray->VWallHitx < data->weight * SQUER && ray->VWallHity < data->height * SQUER)
	{
		if (RayWall(data, ray->VWallHitx, ray->VWallHity))
		{
			ray->WallHitVert = true;
			break;
		}
		else
		{
			ray->VWallHitx += ray->xstep;
			ray->VWallHity += ray->ystep;
		}
	}
	//mlx_put_pixel(data->mlx->image, ray->VWallHitx, ray->VWallHity, 0xFCC737FF);
	//put_inter(data, ray->VWallHitx, ray->VWallHity);
}
void HorizontalIntercept(t_cast *ray, t_data *data, t_player *player, t_facing *facing)
{
	ray->yintercept = floor(player->pl_y / SQUER) * SQUER;
	if (ray->facing->facing_down == 1)
		ray->yintercept += SQUER;
	if (facing->facing_up)
		ray->yintercept--;
	ray->xintercept = floor(player->pl_x + (ray->yintercept - player->pl_y) / tan(ray->ray_ang));
	ray->ystep = SQUER;
	if (facing->facing_up)
		ray->ystep *= -1;
	ray->xstep = ray->ystep / tan(ray->ray_ang);
	if ((facing->facing_left == 1 && ray->xstep > 0) || (facing->facing_right == 1 && ray->xstep < 0))
		ray->xstep *= -1;
	ray->HWallHitx = ray->xintercept;
	ray->HWallHity = ray->yintercept;
	while (ray->HWallHitx >= 0 && ray->HWallHity >= 0 && ray->HWallHitx < data->weight * SQUER  && ray->HWallHity < data->height * SQUER)
	{
		if (RayWall(data, ray->HWallHitx, ray->HWallHity))
		{
			ray->WallHitHorz = true;
			break;
		}
		else
		{
			ray->HWallHitx += ray->xstep;
			ray->HWallHity += ray->ystep;
		}
	}
	//put_inter(data, ray->HWallHitx, ray->HWallHity);
	//bresenham(player->pl_y, player->pl_x, ray->HWallHity, ray->HWallHity, data);
}

double FoundDistance(double x0, double y0, double x1, double y1)
{
	double	value;

	value = ((x1 - x0) * (x1 - x0)) + ((y1 - y0) * (y1 - y0));
	return (sqrt(value));
}

void CastRays(t_cast *ray, t_data *data, t_player *player)
{
	t_facing		facing;

	ray->facing = &facing;
	//RayFacing(data, &facing);
	RayFacing(ray, &facing);
	HorizontalIntercept(ray, data, player, &facing);
	VerticatIntercept(ray, data, player, &facing);
	ray->HorzDistance = FoundDistance(player->pl_x, player->pl_y, ray->HWallHitx, ray->HWallHity);
	ray->VertDistance = FoundDistance(player->pl_x, player->pl_y, ray->VWallHitx, ray->VWallHity);
	ray->d_x = ray->VWallHitx;
	ray->d_y = ray->VWallHity;
	if (ray->HorzDistance < ray->VertDistance)
	{
		ray->d_x = ray->HWallHitx;
		ray->d_y = ray->HWallHity;
	}
	//mlx_put_pixel(data->mlx->image, ray->d_x, ray->d_y, 0x000000FF);
	//put_inter(data, ray->d_x, ray->d_y);
	bresenham(player->pl_y, player->pl_x, ray->d_y, ray->d_x, data);
}
void InitVar(t_data *data, t_cast *ray)
{
	(void) data;
	//ray->ray_ang = data->player->rot_angel - degree_radian(FOV_ANG, 0) / 2;
	ray->distance = 0;
	ray->d_x = 0;
	ray->d_y = 0;
	ray->xstep = 0;
	ray->ystep = 0;
	ray->HWallHitx = 0;
	ray->HWallHity = 0;
	ray->VWallHitx = 0;
	ray->VWallHity = 0;
	ray->xintercept = 0;
	ray->yintercept = 0;
	ray->HorzDistance = 0;
	ray->VertDistance = 0;
	ray->WallHitVert = false;
	ray->WallHitHorz = false;
}

void		CastAllRays(t_data *data, t_player *player)
{
	t_cast	ray;
	int		i;
	double	plus;

	data->ray = &ray;
	i = -1;
	plus = degree_radian(FOV_ANG, 0) / RAY_NBR;
	ray.ray_ang = data->player->rot_angel - (degree_radian(FOV_ANG, 0) / 2);
	while (++i < RAY_NBR)
	{
		InitVar(data, &ray);
		//ray.d_x = data->player->pl_x + cos(ray.ray_ang) * 70;
		//ray.d_y = data->player->pl_y + sin(ray.ray_ang) * 70;
		//bresenham(player->pl_y, player->pl_x, ray.d_y, ray.d_x, data);
		CastRays(&ray, data, player);
		ray.ray_ang += plus;
		ray.ray_ang = NormalizeAngle(ray.ray_ang);
	}
}