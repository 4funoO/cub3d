/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:43:18 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/25 15:22:17 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	w_key(t_data *a)
{
	if (get_map_symbol(a->px + a->pdx * 0.2, a->py + a->pdy * 0.2, a) == '0')
	{
		a->px += a->pdx * 0.2;
		a->py += a->pdy * 0.2;
	}
}

void	s_key(t_data *a)
{
	if (get_map_symbol(a->px - a->pdx * 0.2, a->py - a->pdy * 0.2, a) == '0')
	{
		a->px -= a->pdx * 0.2;
		a->py -= a->pdy * 0.2;
	}
}

void	e_key(t_data *a)
{
	if (get_map_symbol(a->px - a->pdx * 0.5, a->py - a->pdy * 0.5, a) == '0')
	{
		a->px -= a->pdx * 0.3;
		a->py -= a->pdy * 0.3;
	}
}

int	ft_key_hook(int keycode, t_data *a)
{
	if (keycode == 53)
		ft_close(a);
	else if (keycode == 12)
	{
		if (a->mouse == '\0')
		{
			a->mouse = '1';
			mlx_mouse_show();
			return (0);
		}
		a->mouse = '\0';
		mlx_mouse_hide();
	}
	else if (keycode == 13)
		w_key(a);
	else if (keycode == 1)
		s_key(a);
	else if (keycode == 2)
		d_key(a);
	else if (keycode == 0)
		a_key(a);
	else if (keycode == 14)
		e_key(a);
	return (0);
}
