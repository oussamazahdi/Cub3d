/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:39:11 by sslaoui           #+#    #+#             */
/*   Updated: 2024/11/26 19:51:34 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include <libc.h>

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "MLX42/include/MLX42/MLX42.h"
#include "get_next_line/get_next_line.h"

#define SQUER 35

typedef struct s_player
{
	double	x;
	double	y;
	int		redius;
	int		turn_dir;
	int		walk_dir;
	double	rot_ang;
	double	p_speed;
	int		rot_speed;
	float	fov_rad;
}t_player;

typedef struct s_map
{
	mlx_t	*mlx;
	mlx_image_t* image;
	char	*NO;
	char	*EA;
	char	*SO;
	char	*WE;
	char	**map;
	int	lines_number;
	int	big_len;
	int	R;
	int	G;
	int	B;
	int	a;
	int F_rgb;
	int C_rgb;
	t_player	*player;
} t_map;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
} t_list;


						// UTILS
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_lstadd_back(t_list **lst, t_list *new);
char		**ft_split(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);
t_list	*ft_lstnew(void *content);
int		ft_atoi(const char *str);
int		ft_double_size(char **map);
int		ft_grand_line(char **map);
int		ft_strshr(char *s, char c);

						//PARSING
						//RAY_CASTING
void ray_casting(t_map *data);

#endif