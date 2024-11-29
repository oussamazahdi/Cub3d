/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:39:11 by sslaoui           #+#    #+#             */
/*   Updated: 2024/11/29 12:52:24 by ozahdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libc.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "get_next_line/get_next_line.h"

# define SQUER 32

typedef struct s_graph
{
	mlx_t		*mlx;
	mlx_image_t	*image;
}	t_graph;

typedef struct s_player
{
	int			redius;
	int			si_pl;
	int			pl_x;
	int			ang;
	int			pl_y;
	int			d_x;
	int			d_y;
	double		rot_angel;
	int			speed;
	int			turn_dir;
	int			hitbox;
}	t_player;

typedef struct s_data
{
	t_graph		*mlx;
	char			*NO;
	char			*EA;
	char			*SO;
	char			*WE;
	char			**map;
	t_player		*player;
	int			R;
	int			G;
	int			B;
	int			a;
	int 			F_rgb;
	int 			C_rgb;
	int			height;
	int			weight;
} t_data;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
} t_list;

						// UTILS
int		ft_atoi(const char *str);
void		ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
char		**ft_split(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strshr(char *s, char c);
int		ft_double_size(char **map);
int		ft_grand_line(char **map);

void ray_casting(t_data *data, t_graph *mlx);

#endif