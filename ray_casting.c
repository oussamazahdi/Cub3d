/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:28:54 by ozahdi            #+#    #+#             */
/*   Updated: 2024/11/27 12:22:16 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void ft_put_rays(t_map *data, mlx_image_t *image)
{
	int i = data->player->y;
	int j = data->player->x;
	int z = 0;
	//data->player->rot_ang += data->player->turn_dir * (2 * (M_PI / 180));
	while (i < data->player->y + 30 )
	{
		//mlx_put_pixel(image, j + (cos(M_PI / 2) * 1 * 2), i + (sin(M_PI / 2) * 1 * 2),0xD9F8A1);
		//mlx_put_pixel(image, j + (cos(180) * 0 * 2), i + (sin(180) * 0 * 2),0xD9F8A1);
		//mlx_put_pixel(image, j, i,0xD9F8A1);
		//printf("[%f]\n", j + cos(data->player->rot_ang) * z);
		mlx_put_pixel(image, j + cos(data->player->rot_ang) * z, i + sin(data->player->rot_ang) * z,0xD9F8A1);
		z++;
		i++;
	}
	data->player->turn_dir = 0;
}
void ft_put_player(t_map *data, mlx_image_t *image)
{
	int i = 0;
	int j = 0;
	data->player->redius = SQUER / 9;
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
	ft_put_rays(data, image);
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
		data->player->rot_ang += data->player->turn_dir * (2 * (M_PI / 180));
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		data->player->turn_dir = -1;
		data->player->rot_ang += data->player->turn_dir * (2 * (M_PI / 180));
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		data->player->x += 2;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		data->player->x -= 2;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		data->player->y -= 2;
	else if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		data->player->y += 2;
	rander_2d_map(data, data->image);
}




//void draw_line(mlx_image_t* image, int x0, int y0, int x1, int y1, uint32_t color) {
//    int dx = abs(x1 - x0);
//    int dy = abs(y1 - y0);
//    int sx = (x0 < x1) ? 1 : -1;
//    int sy = (y0 < y1) ? 1 : -1;
//    int err = dx - dy;

//    while (1) {
//        // Draw the current pixel
//        mlx_put_pixel(image, x0, y0, color);

//        // Check if we've reached the endpoint
//        if (x0 == x1 && y0 == y1)
//            break;

//        // Update the error term
//        int e2 = 2 * err;
//        if (e2 > -dy) {
//            err -= dy;
//            x0 += sx;
//        }
//        if (e2 < dx) {
//            err += dx;
//            y0 += sy;
//        }
//    }
//}

void ray_casting(t_map *data)
{
	data->player->rot_ang = M_PI / 2;
	data->player->p_speed = 4;
	data->player->turn_dir = 0;
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