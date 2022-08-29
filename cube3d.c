/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:29:09 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/29 13:33:49 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_check_format(char *s, char *s2)
{
	int	i;

	i = 0;
	while (ft_strlen(s) != 4 && s)
		s++;
	if (!s || *s == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_map_initialize(t_data *a)
{
	int	i;

	i = 0;
	a->no = NULL;
	a->ea = NULL;
	a->we = NULL;
	a->so = NULL;
	a->map_height = 0;
	a->map_width = 0;
	a->player = '\0';
	a->c[0] = -1;
	a->f[0] = -1;
	a->map = NULL;
	a->line = NULL;
	a->mlx = NULL;
	a->win = NULL;
	a->img = NULL;
	a->minimap = NULL;
	a->key = NULL;
	a->door = NULL;
	a->mouse = '\0';
	a->key_num = '0';
	a->sprite = '0';
	a->sprite_y = 1;
	a->sprite_z = 20;
	a->d_x = -1;
	a->d_y = -1;
	while (i < 8)
	{
		a->addr[i] = NULL;
		i++;
	}
}

int	main()//int argc, char **argv)
{
	t_data	a;
	int	argc = 2;
	char *argv[2];
	char *line = "map.cub";

	argv[1] = line;
	if (argc == 2)
	{
		ft_map_initialize(&a);
		if (!ft_check_format(argv[1], ".cub"))
			ft_error("Wrong map format!\n", &a);
		ft_map_process(&a, argv[1]);
		ft_game(&a);
	}
	else
		ft_putstr_fd("Error!\nInvalid input!\n", 2);
	return (EXIT_FAILURE);
}
