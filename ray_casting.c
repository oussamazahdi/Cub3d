/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:28:54 by ozahdi            #+#    #+#             */
/*   Updated: 2024/11/28 09:48:37 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


//void ft_put_rays(t_map *data, mlx_image_t *image)
//{
//	int i = data->player->y;
//	int j = data->player->x;
//	int z = 0;
//	//data->player->rot_ang += data->player->turn_dir * (2 * (M_PI / 180));
//	while (i < data->player->y + 30 )
//	{
//		//mlx_put_pixel(image, j + (cos(M_PI / 2) * 1 * 2), i + (sin(M_PI / 2) * 1 * 2),0xD9F8A1);
//		//mlx_put_pixel(image, j + (cos(180) * 0 * 2), i + (sin(180) * 0 * 2),0xD9F8A1);
//		//mlx_put_pixel(image, j, i,0xD9F8A1);
//		//printf("[%f]\n", j + cos(data->player->rot_ang) * z);
//		mlx_put_pixel(image, j + cos(data->player->rot_ang) * z, i + sin(data->player->rot_ang) * z,0xD9F8A1);
//		z++;
//		i++;
//	}
//	data->player->turn_dir = 0;
//}

/*

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int x = x1;
    int y = y1;

    int p = 2 * dy - dx;
    int twoDy = 2 * dy;
    int twoDyDx = 2 * (dy - dx);

    printf("Plot: (%d, %d)\n", x, y);

    while (x < x2) {
        x++;
        if (p < 0) {
            p += twoDy;
        } else {
            y++;
            p += twoDyDx;
        }
        printf("Plot: (%d, %d)\n", x, y);
    }
}




void drawLine(t_map *data, mlx_image_t *image) {
    int dx = data->player->d_x - data->player->x;
    int dy = data->player->d_y - data->player->y;

    int x = data->player->x;
    int y = data->player->y;

    int p = 2 * dy - dx;
    int twoDy = 2 * dy;
    int twoDyDx = 2 * (dy - dx);

    printf("Plot: (%d, %d)\n", x, y);

    while (x < data->player->d_x) {
        x++;
        if (p < 0) {
            p += twoDy;
        } else {
            y++;
            p += twoDyDx;
        }
        printf("Plot: (%d, %d)\n", x, y);
    }
}

*/

//void ft_put_rays(t_map *data, mlx_image_t *image)
//{
//	int	dx = data->player->d_x - data->player->x;
//	int	dy = data->player->d_y - data->player->y;
//	int x = data->player->x;
//	int y = data->player->y;
//}

//void drawLine(t_map *data, mlx_image_t *image) {
	
//    int dx = data->player->d_x - data->player->x;
//    int dy = data->player->d_y - data->player->y;

//    int x = data->player->x;
//    int y = data->player->y;

//    int p = 2 * dy - dx;
//    int twoDy = 2 * dy;
//    int twoDyDx = 2 * (dy - dx);

//		//printf("[%d], [%d]\n", x,y);
//	mlx_put_pixel(image, x, y, 0xFFFF0000);

//	//printf("destination x[%d], destination y[%d]\n", data->player->d_x, data->player->d_y);
//	while (x < data->player->d_x) {
//		x++;
//		if (p < 0) {
//			p += twoDy;
//		} else {
//			y++;
//			p += twoDyDx;
//		}
//		//printf("[%d], [%d]\n", x,y);
//		mlx_put_pixel(image, x, y, 0xFFFF0000);
//	}
//	data->player->turn_dir = 0;
//}
void bresenham_line_algo2(int y0, int x0, int y1, int x1, t_map *exec)
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
    mlx_put_pixel(exec->image, x0, y0, 0x12FF0012);
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
        mlx_put_pixel(exec->image, x0, y0, 0x00000000);
    }
}
double degree_radian(double degree, int type)
{
	if (!type) // type == 0 => degree to rad
		return (degree * (M_PI / 180));
	return (degree * (180 / M_PI));
}

void ft_put_player(t_map *data, mlx_image_t *image)
{
	int i = 0;
	int j = 0;
	data->player->redius = SQUER / 8;
	i =  data->player->y - data->player->redius;
	while (i <  data->player->y + data->player->redius)
	{
		j = data->player->x - data->player->redius;
		while (j < data->player->x + data->player->redius)
		{
			if (pow(j - data->player->x, 2) + pow(i -  data->player->y, 2) <= pow(data->player->redius, 2))
				mlx_put_pixel(image, j, i, 0xD4EBF8);
			j++;
		}
		i++;
	}
	data->player->d_x = data->player->x + cos(degree_radian(data->player->ang, 0)) * 30;
	data->player->d_y = data->player->y + sin(degree_radian(data->player->ang, 0)) * 30;
	//data->player->d_x = data->player->x + cos(degree_radian(data->player->ang, 0)) * 30;
	//data->player->d_y = data->player->y + sin(degree_radian(data->player->ang, 0)) * 30;
	bresenham_line_algo2(data->player->y, data->player->x, data->player->d_y, data->player->d_x, data);
	//data->player->d_x = data->player->x + cos(degree_radian(data->player->ang, 0)) * 1 * 40;
	//data->player->d_y = data->player->y + sin(degree_radian(data->player->ang, 0)) * 1 * 40;
	//mlx_put_pixel(image, data->player->d_x, data->player->d_y, 0xFFFF0000);
	//drawLine(data, image);
	//ft_put_rays(data, image);
}

void rander_2d_map(t_map *data, mlx_image_t *image)
{
	int i = 0;
	int j = 0;
	while (i < data->lines_number * SQUER)
	{
		j = 0;
		while (j < data->big_len * SQUER)
		{
			if (data->map[i / SQUER][j/SQUER] == '1')
				mlx_put_pixel(image, j, i, 255);
			else
				mlx_put_pixel(image, j, i, 0xFFFFFFFF);
			if (j % SQUER == 0 || i % SQUER == 0)
				mlx_put_pixel(image, j, i, 255);
			j++;
		}
		i++;
	}
	ft_put_player(data, image);
}

void ft_handek_actions(void *param)
{
	t_map *data = (t_map *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		data->player->turn_dir = 1;
		data->player->ang += 2;
		if (data->player->ang > 360)
			data->player->ang = data->player->ang - 360;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		data->player->turn_dir = -1;
		data->player->ang -= 2;
		if (data->player->ang < 0)
			data->player->ang = 360 + data->player->ang;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		data->player->x += 2;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		data->player->x -= 2;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_W))
	{
		if (data->player->ang == 1)
		{	
			data->player->ang += 2;
			if (data->player->ang > 360)
				data->player->ang = 0 + data->player->ang - 360;
		}else if (data->player->turn_dir == -1) 
		{
			data->player->ang -= 2;
			if (data->player->ang < 0)
				data->player->ang = 360 + data->player->ang;
		}
		data->player->x += cos(degree_radian(data->player->ang, 0)) * 2;
		data->player->y += sin(degree_radian(data->player->ang, 0)) * 2;
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		data->player->x -= cos(degree_radian(data->player->ang, 0)) * 2 * 1;
		data->player->y -= sin(degree_radian(data->player->ang, 0)) * 2 * 1;
	}
	rander_2d_map(data, data->image);
}

void ray_casting(t_map *data)
{
	data->player->rot_ang = M_PI / 2;
	data->player->p_speed = 4;
	data->player->turn_dir = 0;
	data->player->ang = 90;
	data->player->d_x = data->player->x + cos(degree_radian(data->player->ang, 0)) * 1 * 40;
	data->player->d_y = data->player->y + sin(degree_radian(data->player->ang, 0)) * 1 * 40;
	data->mlx = mlx_init(data->big_len * SQUER, data->lines_number * SQUER, "Cub3D", false);
	data->image = mlx_new_image(data->mlx, data->big_len * SQUER, data->lines_number * SQUER);
	mlx_image_to_window(data->mlx, data->image, 0, 0);
	rander_2d_map(data, data->image);
	mlx_loop_hook(data->mlx,ft_handek_actions, data);
	mlx_loop(data->mlx);
}

/*

111111111111111
1111100011000011111
111100001111111111111
1110000000100000000001
11000000100001111111111
1001011111000011
11000010000111111111111111111
11100000011110000000000000001
111100000000000000000N0000001
11111000111110000000000000001
111111111111111111111111111111


*/