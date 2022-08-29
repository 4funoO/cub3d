/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:14:05 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/29 15:29:58 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	put_sprite_pixel(t_data *a, int x, int y, int k)
{
	char	*dst;
	int		i;
	int		j;


	if (a->sprite_y <= 0 || a->linelen == 0)
		return ;
	i = (int)a->sprite_x % 64;
	k = k + a->spr_step;
	j = (k << 6) / a->linelen;
	dst = a->addr[7] + ((j * a->line_length[7])
		+ i * (a->bits_per_pixel[7] / 8));
	my_mlx_pixel_put(a, x, y, *(unsigned int *)dst);
}

void	draw_sprite_line(t_data *a, int i)
{
	int	lineoff;
	int	lineh;
	int	y;
	int	k;

	lineh = (HEIGHT << 5) / a->sprite_y;
	a->linelen = lineh;
	if (lineh > HEIGHT >> 1)
	{
		a->spr_step = ((lineh - HEIGHT));
		lineh = HEIGHT;
	}
	lineoff = (HEIGHT - lineh) >> 2;
	k = -1;
	y = 0;
	while (y < HEIGHT)
	{
		if (y > lineoff && y < lineh + lineoff)
			put_sprite_pixel(a, i, y, k++);
		y++;
	}
}

void	draw_sprite(t_data *a, t_ray *ray, int i)
{
	t_sprite	spr;
	double		sn;
	double		cs;
	double		x;
	double		y;

	if (a->sprite == '0')
		return ;
	spr.x = a->sprite_x;
	spr.y = a->sprite_y;
	a->sprite_z = 10;
	cs = cos(degree_to_radian(ray->ra));
	sn = sin(degree_to_radian(ray->ra));
	x = a->sprite_x - ray->px;
	y = a->sprite_y - ray->py;
	a->sprite_x = y * cs + x * sn;
	a->sprite_y = x * cs - y * sn;
	a->spr_step = (HEIGHT) / a->sprite_y;
	if (a->spr_step < 0)
		a->spr_step = 0;
	else if (a->spr_step > WIDTH >> 3)
		a->spr_step = WIDTH >> 3;
	a->sprite_x = 512 * a->sprite_x / a->sprite_y;
	a->sprite_y = 512 * a->sprite_z / a->sprite_y;
	a->sprite_x += (WIDTH >> 4);
	a->sprite_y += (HEIGHT >> 4);
	// printf("pa: %f, x: %f, y: %f, px: %f, py: %f, ", a->pa, x, y, ray->px, ray->py);
	// printf("s_x: %f, s_y: %f, dist: %f\n", a->sprite_x, a->sprite_y, a->dist);
	if (a->sprite_x > 0 && a->sprite_x < (WIDTH >> 3) && a->sprite_y > 0 && a->sprite_y < a->dist)
		draw_sprite_line(a, i);
	a->sprite_x = spr.x;
	a->sprite_y = spr.y;
}
