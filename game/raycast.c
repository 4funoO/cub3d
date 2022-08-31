/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/020/20 120:01:44 by doreshev          #+#    #+#             */
/*   Updated: 2022/020/24 17:20:02 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_vertical_ray(t_data *a, t_ray *ray)
{
	double	tan_ra;

	tan_ra = tan(degree_to_radian(ray->ra));
	ray->dof = 0;
	if (cos(degree_to_radian(ray->ra)) > 0.0001)
	{
		ray->side = 5;
		ray->rx = (((int)ray->px >> 6) << 6) + 64;
		ray->ry = (ray->px - ray->rx) * tan_ra + ray->py;
		ray->xo = 64;
		ray->yo = -64 * tan_ra;
	}
	else if (cos(degree_to_radian(ray->ra)) < -0.001)
	{
		ray->side = 4;
		ray->rx = (((int)ray->px >> 6) << 6) - 0.001;
		ray->ry = (ray->px - ray->rx) * tan_ra + ray->py;
		ray->xo = -64;
		ray->yo = 64 * tan_ra;
	}
	else
	{
		ray->dof = a->map_width;
		ray->rx = ray->px;
		ray->ry = ray->py;
	}
}

void	ft_vertical_ray_sub(t_data *a, t_ray *ray)
{
	int		mx;
	int		my;
	char	c;

	while (ray->dof < a->map_width)
	{
		mx = (int)ray->rx >> 6;
		my = (int)ray->ry >> 6;
		c = get_map_symbol(mx, my, a);
		if (c == '1' || c == 'D')
		{
			a->dist = ft_distance(ray);
			a->side = ray->side;
			if (c == 'D')
				a->side = 6;
			ray->dof = a->map_width;
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof += 1;
		}
	}
	ray->vx = ray->rx;
	ray->vy = ray->ry;
}

void	ft_horisontal_ray(t_data *a, t_ray *ray)
{
	double	atan_ra;

	atan_ra = 1.0 / tan(degree_to_radian(ray->ra));
	ray->dof = 0;
	if (sin(degree_to_radian(ray->ra)) > 0.001)
	{
		ray->sideh = 2;
		ray->ry = (((int)ray->py >> 6) << 6) - 0.001;
		ray->rx = (ray->py - ray->ry) * atan_ra + ray->px;
		ray->yo = -64;
		ray->xo = 64 * atan_ra;
	}
	else if (sin(degree_to_radian(ray->ra)) < -0.001)
	{
		ray->sideh = 3;
		ray->ry = (((int)ray->py >> 6) << 6) + 64;
		ray->rx = (ray->py - ray->ry) * atan_ra + ray->px;
		ray->yo = 64;
		ray->xo = -64 * atan_ra;
	}
	else
	{
		ray->dof = a->map_height;
		ray->rx = ray->px;
		ray->ry = ray->py;
	}
}

void	ft_horisontal_ray_sub(t_data *a, t_ray *ray)
{
	int		mx;
	int		my;
	double	disth;
	char	c;

	while (ray->dof < a->map_height)
	{
		mx = (int)ray->rx >> 6;
		my = (int)ray->ry >> 6;
		c = get_map_symbol(mx, my, a);
		if (c == '1' || c == 'D')
		{
			disth = ft_distance(ray);
			if (disth < a->dist)
			{
				a->side = ray->sideh;
				if (c == 'D')
					a->side = 6;
				a->dist = disth;
			}
			else
			{
				ray->rx = ray->vx;
				ray->ry = ray->vy;
			}
			ray->dof = a->map_height;
		}
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof += 1;
		}
	}
}

void	ft_ray_cast(t_data *a, t_ray *ray)
{
	int		i;

	ray->ra = fix_angle(a->pa + 30);
	i = 0;
	ray->px = a->px * 64;
	ray->py = a->py * 64;
	while (i < WIDTH)
	{
		a->dist = 1000000;
		ft_vertical_ray(a, ray);
		ft_vertical_ray_sub(a, ray);
		ft_horisontal_ray(a, ray);
		ft_horisontal_ray_sub(a, ray);
		a->dist = a->dist * cos(degree_to_radian(fix_angle(a->pa - ray->ra)));
		if (a->side > 3 && a->side != 6)
			a->ray = (int)(ray->vy) % 64;
		else
			a->ray = (int)(ray->rx) % 64;
		draw_line(a, i);
		draw_sprite(a, i);
		ray->ra = fix_angle(ray->ra - ANGLE);
		i++;
	}
}
