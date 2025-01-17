/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:00:56 by sslaoui           #+#    #+#             */
/*   Updated: 2025/01/16 21:23:19 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_space(char *str)
{
	int	i;

	i = 0;
	while (i < 50)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = ' ';
}

void	utils_init(t_data *utils, char *av)
{
	utils->EA = NULL;
	utils->WE = NULL;
	utils->NO = NULL;
	utils->SO = NULL;
	utils->C_rgb = -1;
	utils->F_rgb = -1;
	utils->name = av;
	utils->player->pl_x = 0;
	utils->player->pl_y = 0;
}

void	player_detection(char **map, t_player *pl)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{	
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
			{
				pl->pl_x = j;
				pl->pl_y = i;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if ((int)pl->pl_x == 0 || (int)pl->pl_y == 0)
    {
        //we shoulde to free all ptr's before exiting the programme
        printf("Cub3d: Error: You should to add player!\n");
        exit(1);
    }
}

void	ft_strcpy(const char *src, char *dst)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

int	lines_lenght(t_list *lst, int *l_len)
{
	int	i;
	int	j;

	j = 0;
	*l_len = 0;
	while (lst)
	{
		i = 0;
		while (((char *)lst->content)[i])
			i++;
		if (i > j)
			j = i;
		lst = lst->next;
		(*l_len)++;
	}
	return (j);
}
