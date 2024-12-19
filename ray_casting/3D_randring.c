/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_randring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:24:29 by ozahdi            #+#    #+#             */
/*   Updated: 2024/12/18 12:45:46 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void PutLine(t_data *data, long Up, long Down, int x)
{
	long		i;

	i = Up - 1;
	while (++i < Down)
	{
		if (data->view[x].wasHitVert == true)	
			mlx_put_pixel(data->mlx->project, x, i, 0x84a98cFF);
		else if (data->view[x].wasHitVert == false)
			mlx_put_pixel(data->mlx->project, x, i, 0x52796fFF);
	}
}
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
				mlx_put_pixel(mlx->project, j, i, 0x2f3e46FF);
			else
				mlx_put_pixel(mlx->project, j, i, 0xcad2c5FF);
		}
		i++;
	}
}

void	Randring3D(t_data *data, t_player *player)
{
	double		wallheight;
	double		distanceprojection;
	long			Up;
	long			Down;
	int			i;

	ft_fill_project(data, data->mlx);
	i = -1;
	while (++i < RAY_NBR)
	{
		distanceprojection = (WEIGHT / 2) / tan(degree_radian(FOV_ANG, 0) / 2);
		wallheight = (SQUER / (data->view[i].distance * cos(data->view[i].ray_ang - player->rot_angel))) * distanceprojection;
		Up = (HEIGHT / 2) - (wallheight / 2);
		if (Up < 0)
			Up = 0;
		Down = ((HEIGHT / 2) - (wallheight / 2)) + wallheight;
		if (Down > HEIGHT)
			Down = HEIGHT;
		PutLine(data, Up, Down, i);
	}
}
