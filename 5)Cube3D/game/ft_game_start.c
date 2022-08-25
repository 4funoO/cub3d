/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:28:26 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/25 13:25:02 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_map_render(t_data *a)
{
	if (a->img)
		mlx_destroy_image(a->mlx, a->img);
	a->img = mlx_new_image(a->mlx, WIDTH, HEIGHT);
	a->addr[1] = mlx_get_data_addr(a->img, &a->bits_per_pixel[1],
			&a->line_length[1], &a->endian[1]);
	ft_ray_cast(a);
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
}

int	ft_game_start(t_data *a)
{
	int	x;

	ft_map_render(a);
	ft_minimap_render(a->map, a);
	x = a->mouse_x;
	mlx_mouse_get_pos(a->win, &a->mouse_x, &a->mouse_y);
	if (a->mouse_x > x)
		d_key(a);
	else if (a->mouse_x < x)
		a_key(a);
	if (a->mouse_x > WIDTH || a->mouse_x < 0)
		mlx_mouse_move(a->win, 400, 400);
	return (0);
}
