/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:45:23 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/26 13:10:37 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int	ft_map_line_check(char *line, t_data *a)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
		{
			if (a->player != '\0')
				ft_error("More than one player!\n", a);
			a->player = line[i];
			a->px = i + 0.5;
			a->py = a->map_height + 0.5;
			line[i] = '0';
		}
		else if (line[i] != ' ' && line[i] != '1' && line[i] != '0')
			ft_error("Invalid Map!\n", a);
		i++;
	}
	return (i);
}

void	ft_map_init(char *line, t_data *a, int fd)
{
	int		i;

	while (line)
	{
		i = 0;
		while (line[i] && line[i] == ' ')
			i++;
		if (!line[i] || line[i] == '\n')
		{
			free(line);
			a->line = NULL;
			break ;
		}
		i = ft_map_line_check(line, a);
		if (i > a->map_width)
			a->map_width = i;
		ft_lstadd_back(&a->map, ft_lstnew(ft_strtrim(line, "\n")));
		free(line);
		a->line = NULL;
		line = get_next_line(fd);
		a->map_height++;
	}
	ft_map_check(a->map, a);
}

void	ft_map_process(t_data *a, char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("No such file or directory!\n", a);
	a->line = get_next_line(fd);
	if (!a->line)
		ft_error("Invalid map!\n", a);
	while (a->line)
	{
		ft_check_parameters(a, a->line, fd);
		if (!a->line)
			break ;
		free(a->line);
		a->line = get_next_line(fd);
	}
	close(fd);
	if (a->map == NULL)
		ft_error("Map pattern not found in file!\n", a);
}
