/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 15:02:47 by sslaoui           #+#    #+#             */
/*   Updated: 2025/01/15 15:08:40 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_rgb(char **ptr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ptr[i])
	{
		while (ptr[i][j])
		{
			if (ptr[i][j] != '\n' && (ptr[i][j] < '0' || ptr[i][j] > '9'))
				return (1);
			j++;
		}
		if (ptr[i][j - 1] == '\n')
			j--;
		if (j > 3)
			return (1);
		j = 0;
		i++;
	}
	return (0);
}

int	rgb_parse(char *str, t_data *utils)
{
	char	**ptr;
	int		a;

	a = 255;
	if ((*str == 'C' || *str == 'F') && (*(str + 1) == ' '))
		str += 2;
	else
		return (1);
	if (*str == ',')
		return (1);
	ptr = ft_split(str, ',');
	if (!ptr || !ptr[0] || !ptr[1] || !ptr[2] || ptr[3])
		return (1);
	if (check_rgb(ptr) == 1)
		return (1);
	utils->R = ft_atoi(ptr[0]);
	utils->G = ft_atoi(ptr[1]);
	utils->B = ft_atoi(ptr[2]);
	if (utils->R > 255 || utils->G > 255 || utils->B > 255)
		return (1);
	if (*(str - 2) == 'C')
		utils->C_rgb = (utils->R << 24) | (utils->G << 16) | (utils->B << 8) | (a);
	if (*(str - 2) == 'F')
		utils->F_rgb = (utils->R << 24) | (utils->G << 16) | (utils->B << 8) | (a);
	return (0);
}
