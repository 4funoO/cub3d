/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:42:37 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/25 20:04:30 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	my_mlx_pixel_put(t_data *a, int x, int y, int color)
{
	char	*dst;

	dst = a->addr[1] + ((y * a->line_length[1]) + x * (a->bits_per_pixel[1] / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

char	get_map_symbol(int mx, int my, t_data *a)
{
	t_list	*map;
	char	*s;

	if (mx < 0 || my < 0 || mx >= a->map_width || my >= a->map_height)
		return (' ');
	map = a->map;
	while (my > 0)
	{
		map = map->next;
		my--;
	}
	s = map->content;
	return (s[mx]);
}

void	put_texture_pixel(t_data *a, int x, int y, int k)
{
	char	*dst;
	int		i;
	int		j;

	if (a->linelen == 0)
		return ;
	i = a->rx;
	k = k + a->stepy;
	j = (k << 6) / a->linelen;
	dst = a->addr[a->side] + ((j * a->line_length[a->side])
		+ i * (a->bits_per_pixel[a->side] / 8));
	my_mlx_pixel_put(a, x, y, *(unsigned int *)dst);
}

void	draw_line(t_data *a, int i)
{
	int	lineh;
	int	y;
	int	lineoff;
	int	k;

	k = -1;
	lineh = (HEIGHT << 5) / a->dist;
	a->stepy = 0;
	a->linelen = lineh;
	if (lineh > HEIGHT)
	{
		a->stepy = ((lineh - HEIGHT) >> 1);
		lineh = HEIGHT;
	}
	lineoff = (HEIGHT - lineh) >>1;
	y = 0;
	while (y < HEIGHT)
	{
		if (y < lineoff)
			my_mlx_pixel_put(a, i, y, create_trgb(0, a->c[0], a->c[1], a->c[2]));
		else if (y > lineh + lineoff)
			my_mlx_pixel_put(a, i, y, create_trgb(0, a->f[0], a->f[1], a->f[2]));
		else
			put_texture_pixel(a, i, y, k++);
		y++;
	}
}
