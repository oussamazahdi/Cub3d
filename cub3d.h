/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahdi <ozahdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 20:39:11 by sslaoui           #+#    #+#             */
/*   Updated: 2025/01/06 19:02:20 by ozahdi           ###   ########.fr       */
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

# define HEIGHT 720
# define WEIGHT 1280
# define SQUER 10
# define TAIL 64
# define FOV_ANG 60
# define RAY_NBR 1280

typedef struct s_texture
{
	uint32_t **walltexture;
}	t_texture;
typedef struct s_facing
{
	int			facing_down;
	int			facing_up;
	int			facing_right;
	int			facing_left;
}	t_facing;

typedef struct s_rays
{
	bool				horz_wallhit;
	bool				vert_wallhit;
	bool				wasHitVert;
	float			ray_ang;
	float			distance;
	float				xstep;
	float				ystep;
	float				xintercept;
	float				yintercept;
	float				horz_wallhitx;
	float				horz_wallhity;
	float				vert_wallhitx;
	float				vert_wallhity;
	float				destinationX;
	float				destinationY;
	t_facing			*facing;
}	t_rays;

typedef struct s_graph
{
	mlx_t		*mlx;
	mlx_image_t	*project;
	mlx_image_t	*image;
}	t_graph;

typedef struct s_player
{
	double			pl_x;
	double			pl_y;
	double			d_x;
	double			d_y;
	int			redius;
	int			turn_dir;
	int			walk_dir;
	float		rot_angel;
	int			speed;
	double		rot_speed;
	int			hitbox;
	int			si_pl;
}	t_player;

typedef struct s_data
{
	bool			update;
	t_graph		*mlx;
	t_rays		*view;
	t_texture		texture;
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


void ray_casting(t_data *data, t_graph *mlx);
int ft_check_wall(t_data *data, double x, double y);
double degree_radian(double degree, int type);
double normalaize_angle(double angle);
void ft_release_keys(t_data *data);
void bresenham(int y0, int x0, int y1, int x1, t_data *exec);
void ft_put_player(t_data *data, mlx_image_t *image);
void ft_put_map(t_data *data);
void ft_handek_actions(void *param);
void CastAllRays(t_data *data, t_player *player);
int wallcheckers(t_data *data, int x, int y);
void	Randring3D(t_data *data, t_player *player);

#endif