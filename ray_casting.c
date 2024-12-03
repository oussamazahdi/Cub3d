/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:16:00 by ozahdi            #+#    #+#             */
/*   Updated: 2024/12/03 09:57:19 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_release_keys(t_data *data)
{
	t_player *player = data->player;
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_UP))
		player->walk_dir = 0;
	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_DOWN))
		player->walk_dir = 0;
	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_RIGHT))
		player->turn_dir = 0;
	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_LEFT))
		player->turn_dir = 0;
}

double degree_radian(double degree, int type)
{
	if (!type) // type == 0 => degree to rad
		return (degree * (M_PI / 180));
	return (degree * (180 / M_PI));
}

void ft_init_data(t_data *data)
{
	t_player *player;

	player = data->player;
	player->turn_dir = 0; // -1 left or 1 right
	player->walk_dir = 0; // -1 back or 1 front
	player->rot_angel = M_PI / 2;
	player->redius = SQUER / 7;
	player->speed = 50;
	player->rot_speed = 2 * (M_PI / 180);
	player->ang = 30;
	player->pl_x = player->pl_x * SQUER + SQUER / 2;
	player->pl_y = player->pl_y * SQUER + SQUER / 2;
	player->d_x = cos(degree_radian(player->rot_angel, 0)) * player->speed;
	player->d_y = sin(degree_radian(player->rot_angel, 0)) * player->speed;
}



void bresenham_line_algo2(int y0, int x0, int y1, int x1, t_data *exec)
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
    mlx_put_pixel(exec->mlx->image, x0, y0, 0x004E98FF);
    while (1)
    {
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
        if ((x0 < 0 || y0 < 0 ||  (x0 == x1 && y0 == y1)))
            break;
        mlx_put_pixel(exec->mlx->image, x0, y0, 0x004E98FF);
    }
    ft_release_keys(exec);
}
void bresenham(int y0, int x0, int y1, int x1, t_data *exec)
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
    mlx_put_pixel(exec->mlx->image, x0, y0, 0xFF6700FF);
    while (1)
    {
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
        if ((x0 < 0 || y0 < 0 ||  (x0 == x1 && y0 == y1) || exec->map[y0 / SQUER][x0 / SQUER] == '1'))
            break;
        mlx_put_pixel(exec->mlx->image, x0, y0, 0xFF6700FF);
    }
}






void ft_put_player(t_data *data, mlx_image_t *image)
{
	int i = 0;
	int j = 0;
	i =  data->player->pl_y - data->player->redius;
	while (i >= 0 && i <  data->player->pl_y + data->player->redius)
	{
		j = data->player->pl_x - data->player->redius;
		while (j >= 0 && j < data->player->pl_x + data->player->redius)
		{
			if (pow(j - data->player->pl_x, 2) + pow(i -  data->player->pl_y, 2) <= pow(data->player->redius, 2))
				mlx_put_pixel(image, j, i, 0xFF6700FF);
			j++;
		}
		i++;
	}
	data->player->d_x = data->player->pl_x + cos(data->player->rot_angel) * 45;
	data->player->d_y = data->player->pl_y + sin(data->player->rot_angel) * 45;
	/*---------------------------------------------------------------------------------------*/
	t_player *player = data->player;
	double ray_ang =player->rot_angel - degree_radian(FOV_ANG / 2, 0);
	double dx;
	double dy;
	for (int i = 0; i < RAY_NBR; i++)
	{
		dx = player->pl_x + cos(ray_ang) * 200;
		dy = player->pl_y + sin(ray_ang) * 200;
		//printf("player x[%f], player y[%f], dx[%f], dy[%f]\n", player->d_x, player->d_y, dx, dy);
		bresenham(player->pl_y, player->pl_x, dy,dx, data);
		ray_ang += degree_radian(FOV_ANG, 0) / RAY_NBR;
	}
	/*---------------------------------------------------------------------------------------*/
	bresenham_line_algo2(data->player->pl_y, data->player->pl_x, data->player->d_y, data->player->d_x, data);
}


void ft_put_map(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i >= 0 && i < data->height * SQUER)
	{
		j = 0;
		while (j >= 0 && j < data->weight * SQUER)
		{
			if (data->map[i / SQUER][j / SQUER] == '1')
				mlx_put_pixel(data->mlx->image, j, i, 0x3A6EA5FF);
			else
			{
				mlx_put_pixel(data->mlx->image, j, i, 0xEBEBEBFF);
				if (j % SQUER == 0 || i % SQUER == 0)
					mlx_put_pixel(data->mlx->image, j, i, 0xC0C0C0FF);
			}
			j++;
		}
		i++;
	}
	ft_put_player(data, data->mlx->image);
}


int ft_check_wall(t_data *data, double x, double y)
{
	int i = y / SQUER;
	int j = x / SQUER;
	if (data->map[i][j] == '1')
		return 1;
	return 0;
}

void ft_handek_actions2(void *param)
{
	t_data *data = (t_data *)param;
	t_player *player = data->player;
	double movespeed = 0.0;
	if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_UP)){
		player->walk_dir = 1;
	}
	else if (mlx_is_key_down(data->mlx->mlx, MLX_KEY_DOWN)){
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
	movespeed = player->walk_dir * player->rot_speed;
	
	int x = player->pl_x + cos(player->rot_angel) * player->walk_dir * player->rot_speed * player->speed;
	int y = player->pl_y + sin(player->rot_angel) * player->walk_dir * player->rot_speed * player->speed;

	if (!ft_check_wall(data, x, y))
	{
		player->pl_x += cos(player->rot_angel) * player->walk_dir * player->rot_speed * player->speed;
		player->pl_y += sin(player->rot_angel) * player->walk_dir * player->rot_speed * player->speed;
	}
	//printf("[%f]\n", player->pl_x);
	ft_put_map(data);
}
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

void rander_2d_map(t_data *data, t_graph *mlx)
{
	mlx->mlx = mlx_init(data->weight * SQUER, data->height * SQUER, "CUB3D", false);
	mlx->image = mlx_new_image(mlx->mlx, data->weight * SQUER, data->height * SQUER);
	mlx_image_to_window(data->mlx->mlx, data->mlx->image, 0, 0);
	ft_put_map(data);
	mlx_loop_hook(data->mlx->mlx,ft_handek_actions2, data);
	mlx_loop(mlx->mlx);
}

void ray_casting(t_data *data, t_graph *mlx)
{
	ft_init_data(data);
	rander_2d_map(data, mlx);
}
