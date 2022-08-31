/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:21:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/31 13:21:58 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	my_mlx_pixel_put_mini(t_data *a, int x, int y, int color)
{
	char	*dst;

	dst = a->addr[1] + ((y * a->line_length[0])
			+ x * (a->bits_per_pixel[0] / 8));
	*(unsigned int *)dst = color;
}
