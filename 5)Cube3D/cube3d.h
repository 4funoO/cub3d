/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:29:19 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/25 20:06:54 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# define HEIGHT   1000
# define WIDTH    1000
# define ANGLE    60.0 / WIDTH
# define VIEWDIST 50
# define SCALEX   64.0 / WIDTH
# define SCALEY   64.0 / HEIGHT

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef struct s_ray {
	int		dof;
	double	xo;
	double	yo;
	double	ra;
	double	hx;
	double	hy;
	double	vx;
	double	vy;
	double	px;
	double	py;
	double	rx;
	double	ry;
	int		side;
	int		sideh;
}				t_ray;

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	void	*no;
	void	*so;
	void	*ea;
	void	*we;
	void	*minimap;
	char	*addr[6];
	double	map_width;
	double	map_height;
	char	player;
	int		c[3];
	int		f[3];
	int		mouse_x;
	int		mouse_y;
	char	mouse;
	int		bits_per_pixel[6];
	int		line_length[6];
	int		endian[6];
	char	*line;
	double	px;
	double	py;
	double	pdx;
	double	pdy;
	double	pa;
	double	dist;
	int		side;
	int		rx;
	int		x;
	double	stepy;
	int		linelen;
	t_list	*map;
}				t_data;

void	ft_error(char *s, t_data *a);
void	ft_free(t_data *a);
int		ft_close(t_data *a);
void	ft_lstfree(t_list *map);

void	ft_map_process(t_data *a, char *argv);
void	ft_check_parameters(t_data *a, char *line, int fd);
void	ft_map_init(char *line, t_data *a, int fd);

int		ft_game_start(t_data *a);
void	ft_game(t_data *a);
int		ft_key_hook(int keycode, t_data *a);
void	ft_minimap_render(t_list *map, t_data *a);
void	ft_ray_cast(t_data *a);
void	draw_line(t_data *a, int i);
char	get_map_symbol(int	mx, int my, t_data *a);
double	ft_distance(t_ray *ray);
double	degree_to_radian(double a) ;
double	fix_angle(double a);
void	a_key(t_data *a);
void	d_key(t_data *a);

#endif