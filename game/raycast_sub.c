/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:57:54 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/24 19:43:50 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

double	degree_to_radian(double a) 
{ 
	return (a * M_PI / 180.0);
}

double	fix_angle(double a)
{
	if (a > 359)
		a -= 360;
	else if (a < 0)
		a += 360;
	return (a);
}

double	ft_distance(t_ray *ray)
{
	return (cos(degree_to_radian(ray->ra)) * (ray->rx - ray->px) 
		- sin(degree_to_radian(ray->ra)) * (ray->ry - ray->py));
}
