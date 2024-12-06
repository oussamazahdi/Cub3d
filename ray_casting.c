/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:16:00 by ozahdi            #+#    #+#             */
/*   Updated: 2024/12/05 11:36:11 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//int ft_check_wall(t_data *data, double x, double y)
//{
//	int i = y / SQUER;
//	int j = x / SQUER;
//	if (x >= data->weight * SQUER || y >= data->height * SQUER || x < 0 || y < 0)
//		return 1;
//	int q = data->player->pl_x / SQUER;
//	int w = data->player->pl_y / SQUER;
//	if ((data->map[i][q] && data->map[i][q] == '1') || (data->map[w][j] && data->map[w][j] == '1'))
//		return 1;
//	if (data->map && data->map[i] && data->map[i][j] && data->map[i][j] == '1')
//		return 1;
//	return 0;
//}
//void ft_release_keys(t_data *data)
//{
//	t_player *player = data->player;
//	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_UP))
//		player->walk_dir = 0;
//	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_DOWN) || mlx_is_key_down(data->mlx->mlx, MLX_KEY_S))
//		player->walk_dir = 0;
//	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_RIGHT))
//		player->turn_dir = 0;
//	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_LEFT))
//		player->turn_dir = 0;
//	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_W))
//		player->turn_dir = 0;
//	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_S))
//		player->turn_dir = 0;
//}

//double degree_radian(double degree, int type)
//{
//	if (!type) // type == 0 => degree to rad
//		return (degree * (M_PI / 180));
//	return (degree * (180 / M_PI));
//}

//void ft_init_data(t_data *data)
//{
//	t_player *player;

//	player = data->player;
//	player->turn_dir = 0; // -1 left or 1 right
//	player->walk_dir = 0; // -1 back or 1 front
//	player->rot_angel = M_PI / 2;
//	player->redius = SQUER / 7;
//	player->speed = 50;
//	player->rot_speed = 2 * (M_PI / 180);
//	player->ang = 30;
//	player->pl_x = player->pl_x * SQUER + SQUER / 2;
//	player->pl_y = player->pl_y * SQUER + SQUER / 2;
//	player->d_x = cos(degree_radian(player->rot_angel, 0)) * player->speed;
//	player->d_y = sin(degree_radian(player->rot_angel, 0)) * player->speed;
//}



//void bresenham_line_algo2(int y0, int x0, int y1, int x1, t_data *exec)
// {
//    int dx;
//    int dy;
//    int sx ;
//    int sy ;
//    int err;
//    int e2;

//    dx = abs(x1 - x0);
//    dy = abs(y1 - y0);
//    if (x0 < x1)
//        sx = 1;
//    else 
//        sx = -1;
//    if (y0 < y1)
//        sy = 1;
//    else
//        sy = -1;
//    err = dx - dy;
//    if (x0 < 0 || y0 < 0)
//	return;
//    mlx_put_pixel(exec->mlx->image, x0, y0, 0x004E98FF);
//    while (1)
//    {
//        e2 = 2 * err;
//        if (e2 > -dy)
//        {
//          	err -= dy;
//          	x0 += sx;
//        }
//        if (e2 < dx)
//         {
//          	err += dx;
//          	y0 += sy; 
//        }
//        if ((x0 < 0 || y0 < 0 || x0 > exec->weight * 32 || y0 > exec->height * 32 ||  (x0 == x1 && y0 == y1) || !ft_check_wall(exec, x1, y1)))
//            break;
//        mlx_put_pixel(exec->mlx->image, x0, y0, 0xFF6700FF);
//    }
//    ft_release_keys(exec);
//}
//void bresenham(int y0, int x0, int y1, int x1, t_data *exec)
// {
//    int dx;
//    int dy;
//    int sx ;
//    int sy ;
//    int err;
//    int e2;

//    dx = abs(x1 - x0);
//    dy = abs(y1 - y0);
//    if (x0 < x1)
//        sx = 1;
//    else 
//        sx = -1;
//    if (y0 < y1)
//        sy = 1;
//    else
//        sy = -1;
//    err = dx - dy;
//    if (x0 < 0 || y0 < 0)
//	return;
//    mlx_put_pixel(exec->mlx->image, x0, y0, 0x004E98FF);
//    while (1)
//    {
//        e2 = 2 * err;
//        if (e2 > -dy)
//        {
//          	err -= dy;
//          	x0 += sx;
//        }
//        if (e2 < dx)
//         {
//          	err += dx;
//          	y0 += sy; 
//        }
//        if ((x0 < 0 || y0 < 0 || x0 > exec->weight * 32 || y0 > exec->height * 32 ||  (x0 == x1 && y0 == y1) || !ft_check_wall(exec, x1, y1)))
//            break;
//        mlx_put_pixel(exec->mlx->image, x0, y0, 0x004E98FF);
//    }
//    ft_release_keys(exec);
//}
//void bresenham(int y0, int x0, int y1, int x1, t_data *exec)
// {
//    int dx;
//    int dy;
//    int sx ;
//    int sy ;
//    int err;
//    int e2;

//    dx = abs(x1 - x0);
//    dy = abs(y1 - y0);
//    if (x0 < x1)
//        sx = 1;
//    else 
//        sx = -1;
//    if (y0 < y1)
//        sy = 1;
//    else
//        sy = -1;
//    err = dx - dy;
//    if (x0 < 0 || y0 < 0)
//	return;
//    mlx_put_pixel(exec->mlx->image, x0, y0, 0xFF6700FF);
//    while (1)
//    {
//        e2 = 2 * err;
//        if (e2 > -dy)
//        {
//            err -= dy;
//            x0 += sx;
//        }
//        if (e2 < dx)
//         {
//            err += dx;
//            y0 += sy; 
//        }
//        if ((x0 < 0 || y0 < 0 ||  (x0 == x1 && y0 == y1) || exec->map[y0 / SQUER][x0 / SQUER] == '1'))
//            break;
//        mlx_put_pixel(exec->mlx->image, x0, y0, 0xFF6700FF);
//    }
//}


//////////////////////////////////////
// Horizontal Ray-Grid Intersection //
//////////////////////////////////////

//void ray_facing(t_rays *ray)
//{
//	ray->facing_down = 0;
//	ray->facing_up = 0;
//	ray->facing_right = 0;
//	ray->facing_left = 0;
//	if (ray->ray_ang > 0 && ray->ray_ang < M_PI)
//		ray->facing_down = 1;
//	if (!ray->facing_down)
//		ray->facing_up = 1;
//	if (ray->ray_ang > (M_PI / 2) && ray->ray_ang < (3 * M_PI / 2))
//		ray->facing_left = 1;
//	if (!ray->facing_left)
//		ray->facing_right = 1;
//}

//void cast(int columnId, t_data *data, t_rays *ray)
//{
//	(void) columnId;
//	int xintercept;
//	int yintercept;
//	int xstep;
//	int ystep;
//	ray_facing(ray);
//	yintercept = floor(data->player->pl_y / SQUER) * SQUER;
//	if (ray->facing_down)
//		yintercept += SQUER;
//	xintercept = data->player->pl_x + ((data->player->pl_y - yintercept) / tan(ray->ray_ang));
//	ystep = SQUER;
//	if (ray->facing_up)
//		ystep *= -1;
//	xstep = SQUER / tan(ray->ray_ang);
//	if ((ray->facing_left && xstep > 0) || (ray->facing_right && xstep < 0))
//		xstep *= -1;
//	int nextHorzTouchX = xintercept;
//	int nextHorzTouchY = yintercept;
//	if (ray->facing_up)
//		nextHorzTouchY--;
//	else if (ray->facing_down)
//		nextHorzTouchY ++;

//	while (nextHorzTouchX >= 0 && nextHorzTouchX < data->weight * SQUER && nextHorzTouchY >= 0 && nextHorzTouchY < data->height * SQUER)
//	{
//		if (ft_check_wall(data, nextHorzTouchX, nextHorzTouchY))
//			break;
//		else
//		{
//			nextHorzTouchX += xstep;
//			nextHorzTouchY += ystep;
//		}
//	}
//	bresenham_line_algo2(data->player->pl_y, data->player->pl_x, nextHorzTouchY,nextHorzTouchX, data);
	
//}
//void cast(int columnId, t_data *data, t_rays *ray)
//{
//	(void) columnId;
//	int xintercept;
//	int yintercept;
//	int xstep;
//	int ystep;
//	ray_facing(ray);
//	yintercept = floor(data->player->pl_y / SQUER) * SQUER;
//	if (ray->facing_down)
//		yintercept += SQUER;
//	xintercept = data->player->pl_x + ((data->player->pl_y - yintercept) / tan(ray->ray_ang));
//	ystep = SQUER;
//	if (ray->facing_up)
//		ystep *= -1;
//	xstep = SQUER / tan(ray->ray_ang);
//	if ((ray->facing_left && xstep > 0) || (ray->facing_right && xstep < 0))
//		xstep *= -1;
//	int nextHorzTouchX = xintercept;
//	int nextHorzTouchY = yintercept;
//	if (ray->facing_up)
//		nextHorzTouchY--;

//	while (1)
//	{
//		if (ft_check_wall(data, nextHorzTouchX, nextHorzTouchY))
//			break;
//		else
//		{
//			nextHorzTouchX += xstep;
//			nextHorzTouchY += ystep;
//		}
//	}
	
//}


//double normalaize_angle(double angle)
//{
//	if (angle < 0)
//		angle += (2 * M_PI);
//	else if (angle > (2 * M_PI))
//		angle -= (2 * M_PI);
//	return angle;
//}


//void ft_put_cub(int dx, int dy, t_data *data)
//{
//	int i = dx - 2;
//	int j = dy - 2;
//	while (j < dx + 2)
//	{
//		i = dx - 2;
//		while (i < dx + 3)
//		{
//			mlx_put_pixel(data->mlx->image, j, i, 0xFFFFFF);
//			i++;
//		}
//		j++;
//	}
	
//}

//void cast(int columId, t_data *data, t_rays *ray)
//{
//	(void) columId;
//	int	xintercept;
//	int	yintercept;
//	int	xstep;
//	int	ystep;

//	ray_facing(ray);
//	yintercept = floor(data->player->pl_y / SQUER) * SQUER;
//	if (ray->facing_down)
//		yintercept += SQUER;
//	xintercept = data->player->pl_x + ((data->player->pl_y - yintercept) / tan(ray->ray_ang));
//	ystep = SQUER;
//	if (ray->facing_up)
//		ystep *= -1;
//	xstep = SQUER / tan(ray->ray_ang);
//	if ((ray->facing_left && xstep > 0) || (ray->facing_right && xstep < 0))
//		xstep *= -1;
//	ray->d_x = xintercept;
//	ray->d_y = yintercept;
//	if (ray->facing_up)
//		ray->d_y--;
//	while (ray->d_x >= 0 && ray->d_x < data->weight * SQUER && ray->d_y >= 0 && ray->d_y < data->height * SQUER)
//	{
//		if (ft_check_wall(data, ray->d_x, ray->d_y))
//			break;
//		ray->d_x += xstep;
//		ray->d_y += ystep;
//		//ft_put_cub(ray->d_x, ray->d_y, data);
//	}
//}


//void castAllRays(t_data *data)
//{
//	t_player		*player;
//	t_rays			rays;
//	//double		dx;
//	//double		dy;
//	int columnId = 0;

//	player = data->player;
//	data->rays = &rays;
//	rays.ray_ang = player->rot_angel - degree_radian(FOV_ANG / 2, 0);
//	for (int i = 0; i < 1; i++)
//	{
//		cast(columnId, data, &rays);
//		//printf("up[%d], down[%d], left[%d], right[%d]\n", rays.facing_up, rays.facing_down, rays.facing_left, rays.facing_right);
//		//dx = player->pl_x + cos(rays.ray_ang) * 60;
//		//dy = player->pl_y + sin(rays.ray_ang) * 60;
//		//mlx_put_pixel(data->mlx->image, dx, dy, 0xFF6700FF);
//		//bresenham_line_algo2(player->pl_y, player->pl_x, dy,dx, data);
//		bresenham(player->pl_y, player->pl_x, rays.d_y,rays.d_x, data);
//		rays.ray_ang += degree_radian(FOV_ANG, 0) / 1;
//		rays.ray_ang = normalaize_angle(rays.ray_ang);
//	}
//}
//void castAllRays(t_data *data)
//{
//	t_player		*player;
//	t_rays			rays;
//	double		dx;
//	double		dy;

//	player = data->player;
//	data->rays = malloc(sizeof(t_rays));
//	data->rays->ray_ang = player->rot_angel - degree_radian(FOV_ANG / 2, 0);
//	for (int i = 0; i < RAY_NBR; i++)
//	{
//		dx = player->pl_x + cos(data->rays->ray_ang) * 80;
//		dy = player->pl_y + sin(data->rays->ray_ang) * 80;
//		//printf("player x[%f], player y[%f], dx[%f], dy[%f]\n", player->d_x, player->d_y, dx, dy);
//		bresenham_line_algo2(player->pl_y, player->pl_x, dy,dx, data);
//		data->rays->ray_ang += degree_radian(FOV_ANG, 0) / RAY_NBR;
//	}
//}

//void ft_put_player(t_data *data, mlx_image_t *image)
//{
//	int i = 0;
//	int j = 0;
//	i =  data->player->pl_y - data->player->redius;
//	while (i >= 0 && i <  data->player->pl_y + data->player->redius)
//	{
//		j = data->player->pl_x - data->player->redius;
//		while (j >= 0 && j < data->player->pl_x + data->player->redius)
//		{
//			if (pow(j - data->player->pl_x, 2) + pow(i -  data->player->pl_y, 2) <= pow(data->player->redius, 2))
//				mlx_put_pixel(image, j, i, 0xFF6700FF);
//			j++;
//		}
//		i++;
//	}
//	data->player->d_x = data->player->pl_x + cos(data->player->rot_angel) * 45;
//	data->player->d_y = data->player->pl_y + sin(data->player->rot_angel) * 45;
//	/*---------------------------------------------------------------------------------------*/
//	//t_player *player = data->player;
//	//double ray_ang =player->rot_angel - degree_radian(FOV_ANG / 2, 0);
//	//double dx;
//	//double dy;
//	//for (int i = 0; i < RAY_NBR; i++)
//	//{
//	//	dx = player->pl_x + cos(ray_ang) * 200;
//	//	dy = player->pl_y + sin(ray_ang) * 200;
//	//	//printf("player x[%f], player y[%f], dx[%f], dy[%f]\n", player->d_x, player->d_y, dx, dy);
//	//	bresenham_line_algo2(player->pl_y, player->pl_x, dy,dx, data);
//	//	ray_ang += degree_radian(FOV_ANG, 0) / RAY_NBR;
//	//}
//	//t_player *player = data->player;
//	//double ray_ang =player->rot_angel - degree_radian(FOV_ANG / 2, 0);
//	//double dx;
//	//double dy;
//	//for (int i = 0; i < RAY_NBR; i++)
//	//{
//	//	dx = player->pl_x + cos(ray_ang) * 80;
//	//	dy = player->pl_y + sin(ray_ang) * 80;
//	//	//printf("player x[%f], player y[%f], dx[%f], dy[%f]\n", player->d_x, player->d_y, dx, dy);
//	//	bresenham_line_algo2(player->pl_y, player->pl_x, dy,dx, data);
//	//	ray_ang += degree_radian(FOV_ANG, 0) / RAY_NBR;
//	//}
//	//castAllRays(data);
//	/*---------------------------------------------------------------------------------------*/
//	bresenham_line_algo2(data->player->pl_y, data->player->pl_x, data->player->d_y, data->player->d_x, data);
//}


//void ft_put_map(t_data *data)
//{
//	int		i;
//	int		j;

//	i = 0;
//	while (i >= 0 && i < data->height * SQUER)
//	{
//		j = 0;
//		while (j >= 0 && j < data->weight * SQUER)
//		{
//			if (data->map[i / SQUER][j / SQUER] == '1')
//				mlx_put_pixel(data->mlx->image, j, i, 0x3A6EA5FF);
//			else
//			{
//				mlx_put_pixel(data->mlx->image, j, i, 0xEBEBEBFF);
//				//if (j % SQUER == 0 || i % SQUER == 0)
//				//	mlx_put_pixel(data->mlx->image, j, i, 0xC0C0C0FF);
//			}
//			j++;
//		}
//		i++;
//	}
//	ft_put_player(data, data->mlx->image);
//}




//void ft_handek_actions2(void *param)
//{
//	t_data *data = (t_data *)param;
//	t_player *player = data->player;
//	double movespeed = 0.0;
//	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_UP) || mlx_is_key_down(data->mlx->mlx, MLX_KEY_W)){
//		player->walk_dir = 1;
//	}
//	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_DOWN) || mlx_is_key_down(data->mlx->mlx, MLX_KEY_S)){
//		player->walk_dir = -1;
//	}
//	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_RIGHT)){
//		player->rot_angel += player->rot_speed;
//		if (player->rot_angel > 2 * M_PI)
//			player->rot_angel -= 2 * M_PI;
//	}
//	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_LEFT)){
//		player->rot_angel -= player->rot_speed;
//		if (player->rot_angel < 0)
//			player->rot_angel += 2 * M_PI;
//	}
//	movespeed = player->walk_dir * player->rot_speed;
	
//	int x = player->pl_x + cos(player->rot_angel) * player->walk_dir * player->rot_speed * player->speed;
//	int y = player->pl_y + sin(player->rot_angel) * player->walk_dir * player->rot_speed * player->speed;

//	if (!ft_check_wall(data, x, y))
//	{
//		player->pl_x += cos(player->rot_angel) * player->walk_dir * player->rot_speed * player->speed;
//		player->pl_y += sin(player->rot_angel) * player->walk_dir * player->rot_speed * player->speed;
//	}
//	ft_put_map(data);
//}
//void ft_handek_actions2(void *param)
//{
//	t_data *data = (t_data *)param;
//	t_player *player = data->player;
//	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_UP))
//	{
//		if (player->rot_angel > 0 && player->rot_angel <= M_PI / 2 )
//		{
//			player->pl_x += cos(player->rot_angel) * 2;
//			player->pl_y += sin(player->rot_angel) * 2;
//		}
//		else if (player->rot_angel > M_PI / 2 && player->rot_angel <= M_PI)
//		{
//			player->pl_x -= cos(player->rot_angel) * 2;
//			player->pl_y += sin(player->rot_angel) * 2;
			
//		}
//		else if (player->rot_angel > M_PI && player->rot_angel <= (3 * M_PI) / 2 )
//		{
//			player->pl_x -= cos(player->rot_angel) * 2;
//			player->pl_y -= sin(player->rot_angel) * 2;
//		}
//		else if (player->rot_angel > (3 * M_PI) / 2  && player->rot_angel <= 2 * M_PI)
//		{
//			player->pl_x += cos(player->rot_angel) * 2;
//			player->pl_y -= sin(player->rot_angel) * 2;
//		}
//	}
//	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_DOWN))
//	{
//	}
//	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_RIGHT))
//		player->rot_angel += player->rot_speed;
//	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_LEFT))
//		player->rot_angel -= player->rot_speed;
//	data->player->d_x = data->player->pl_x + cos(data->player->rot_angel) * 35;
//	data->player->d_y = data->player->pl_y + sin(data->player->rot_angel) * 35;
//	ft_put_map(data);
//}
//void ft_handek_actions2(void *param)
//{
//	t_data *data = (t_data *)param;
//	t_player *player = data->player;
//	//double movestep = 0.0;
//	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_UP))
//	{
//		player->walk_dir = 1;
//		player->pl_x += cos(player->rot_angel) * 2;
//		player->pl_y += sin(player->rot_angel) * 2;
//	}
//	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_DOWN))
//	{
//		player->walk_dir = -1;
//		player->pl_x -= cos(player->rot_angel) * 2;
//		player->pl_y -= sin(player->rot_angel) * 2;
//	}
//	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_RIGHT))
//	{
//		player->turn_dir = 1;
//		player->rot_angel += player->turn_dir * player->rot_speed;
//		if (player->rot_angel > 2 * M_PI)
//			player->rot_angel -= 2 * M_PI;
//	}
//	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_LEFT))
//	{
//		player->turn_dir = -1;
//		player->rot_angel += player->turn_dir * player->rot_speed;
//		if (player->rot_angel < 0)
//			player->rot_angel = 2 * M_PI + player->rot_angel;
//	}
//	data->player->d_x = data->player->pl_x + cos(data->player->rot_angel) * 35;
//	data->player->d_y = data->player->pl_y + sin(data->player->rot_angel) * 35;
//	ft_put_map(data);
//}
//void ft_handek_actions(void *param)
//{
//	t_data *data = (t_data *)param;
//	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_RIGHT))
//	{
//		data->player->turn_dir = 1;
//		data->player->ang += 2;
//		if (data->player->ang > 360)
//			data->player->ang = data->player->ang - 360;
//	}
//	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_LEFT))
//	{
//		data->player->turn_dir = -1;
//		data->player->ang -= 2;
//		if (data->player->ang < 0)
//			data->player->ang = 360 + data->player->ang;
//	}
//	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_D))
//		data->player->pl_x += 2;
//	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_A))
//		data->player->pl_x -= 2;
//	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_W) || mlx_is_key_down(data->mlx->mlx, MLX_KEY_UP))
//	{
//		if (data->player->ang == 1)
//		{	
//			data->player->ang += 2;
//			if (data->player->ang > 360)
//				data->player->ang -= 360;
//		}else if (data->player->turn_dir == -1) 
//		{
//			data->player->ang -= 2;
//			if (data->player->ang < 0)
//				data->player->ang += 360;
//		}
//		data->player->pl_x += cos(degree_radian(data->player->ang, 0)) * 2;
//		data->player->pl_y += sin(degree_radian(data->player->ang, 0)) * 2;
//	}
//	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_S))
//	{
//		data->player->pl_x -= cos(degree_radian(data->player->ang, 0)) * 2;
//		data->player->pl_y -= sin(degree_radian(data->player->ang, 0)) * 2;
//	}
//	ft_put_map(data);
//}

//void rander_2d_map(t_data *data, t_graph *mlx)
//{
//	mlx->mlx = mlx_init(data->weight * SQUER, data->height * SQUER, "CUB3D", false);
//	mlx->image = mlx_new_image(mlx->mlx, data->weight * SQUER, data->height * SQUER);
//	mlx_image_to_window(data->mlx->mlx, data->mlx->image, 0, 0);
//	ft_put_map(data);
//	//mlx_loop_hook(data->mlx->mlx,ft_handek_actions2, data);
//	mlx_loop(mlx->mlx);
//}

//void ray_casting(t_data *data, t_graph *mlx)
//{
//	ft_init_data(data);
//	rander_2d_map(data, mlx);
//}
