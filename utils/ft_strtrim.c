/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:09:07 by ozahdi            #+#    #+#             */
/*   Updated: 2025/01/17 22:30:22 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strtrim(char *s1, char *set)
{
	int	s;
	int	f;
	int	vlen;

	if (!s1 || !set)
		return (0);
	if (!(*s1))
		return (ft_strdup(""));
	s = 0;
	f = ft_strlen(s1);
	f--;
	while (ft_strchr(set, s1[s]) && s1[s])
		s++;
	while (ft_strchr(set, s1[f]) && s1[f])
		f--;
	vlen = f - s + 1;
	return (ft_substr(s1, s, vlen));
}
