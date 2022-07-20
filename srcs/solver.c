/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:47:51 by ycucchi           #+#    #+#             */
/*   Updated: 2022/06/30 17:47:52 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/filler.h"

long	ft_absolute_distance(t_pos pos1, t_pos *pos2)
{
	return (ft_sqrt(ft_pow(pos1.x - pos2->x, 2) + ft_pow(pos1.y - pos2->y, 2)));
}

static void	check_corners(t_board *data, int i, int j, int n)
{
	int	tmp;
	int	s;
	int	p;

	p = data->ennemy_piece;
	s = ft_tolower(p);
	tmp = n / 2;
	if (i - tmp >= 0 && j - tmp >= 0 && \
	(data->grid[i - tmp][j - tmp] == p || data->grid[i - tmp][j - tmp] == s))
		data->dist = n;
	else if (i - tmp >= 0 && j + tmp >= 0 && \
	(data->grid[i - tmp][j + tmp] == p || data->grid[i - tmp][j + tmp] == s))
		data->dist = n;
	else if (i + tmp >= 0 && j + tmp >= 0 && \
	(data->grid[i + tmp][j + tmp] == p || data->grid[i + tmp][j + tmp] == s))
		data->dist = n;
	else if (i + tmp >= 0 && j - tmp >= 0 && \
	(data->grid[i + tmp][j - tmp] == p || data->grid[i + tmp][j - tmp] == s))
		data->dist = n;
}

static void	closest(t_pos pos1, t_pos *pos2, t_board *data, int i)
{
	int	j;
	int	n;
	int	p;

	n = 0;
	j = pos1.y;
	p = data->ennemy_piece;
	while (i + ++n < data->grid_x && j + n < data->grid_y)
	{
		if (i >= 0 && j - n >= 0 && \
		(data->grid[i][j - n] == p || data->grid[i][j - n] == ft_tolower(p)))
			check_left(data, pos2, pos1, n);
		else if (i - n >= 0 && j >= 0 && \
		(data->grid[i - n][j] == p || data->grid[i - n][j] == ft_tolower(p)))
			check_top(data, pos2, pos1, n);
		else if (i >= 0 && j >= 0 && \
		(data->grid[i][j + n] == p || data->grid[i][j + n] == ft_tolower(p)))
			check_right(data, pos2, pos1, n);
		else if (i >= 0 && j >= 0 && \
		(data->grid[i + n][j] == p || data->grid[i + n][j] == ft_tolower(p)))
			check_bottom(data, pos2, pos1, n);
		if (n % 2 == 0 && data->dist == 0)
			check_corners(data, i, j, n);
	}
	data->dist = ft_absolute_distance(pos1, pos2);
}

void	solving_grid(t_board *data, t_pos *pos2, t_pos pos1)
{
	int		i;
	int		j;

	i = -1;
	pos2->x = data->ennemy_x;
	pos2->y = data->ennemy_y;
	while (data->grid[++i])
	{
		data->solving_grid_helper = ft_strnew(data->grid_y);
		data->solving_grid_helper = \
		ft_strcpy(data->solving_grid_helper, data->grid[i]);
		j = -1;
		while (data->grid[i][++j] != '\0')
		{
			if (data->solving_grid_helper[j] == '.')
			{
				pos1.x = i;
				pos1.y = j;
				closest(pos1, pos2, data, i);
				data->solving_grid_helper[j] = data->dist + '0';
			}
		}
		data->solving_grid[i] = data->solving_grid_helper;
	}
	data->solving_grid[i] = NULL;
}
