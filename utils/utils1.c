/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:50:56 by ozahdi            #+#    #+#             */
/*   Updated: 2024/11/25 11:55:53 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_double_size(char **map)
{
	int		i;

	if (!map || !*map)
		return (0);
	i = 0;
	while (map && map[i])
		i++;
	return (i);
}
int	ft_grand_line(char **map)
{
	int		i;
	int		len;
	int		tmp;

	i = 0;
	len = 0;
	while (map && *map)
	{
		tmp = ft_strlen(*map);
		if (tmp > len)
			len = tmp;
		map++;
	}
	return (len);
}
