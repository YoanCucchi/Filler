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

int	closest(t_pos pos1, t_pos *pos2, t_board *data, int i)
{
	int	j;
	int	n;
	int	p;
	int	tmp;

	n = 0;
	tmp = 0;
	j = pos1.y;
	p = data->ennemy_piece;
	while (i + ++n < data->grid_x && j + n < data->grid_y)
	{
		if (i >= 0 && j - n >= 0 && \
		(data->grid[i][j - n] == p || data->grid[i][j - n] == ft_tolower(p)))
			return (check_left(pos2, pos1, n));
		if (i - n >= 0 && j >= 0 && \
		(data->grid[i - n][j] == p || data->grid[i - n][j] == ft_tolower(p)))
			return (check_top(pos2, pos1, n));
		if (i >= 0 && j >= 0 && \
		(data->grid[i][j + n] == p || data->grid[i][j + n] == ft_tolower(p)))
			return (check_right(pos2, pos1, n));
		if (i >= 0 && j >= 0 && \
		(data->grid[i + n][j] == p || data->grid[i + n][j] == ft_tolower(p)))
			return (check_bottom(pos2, pos1, n));
		if (n % 2 == 0)
		{
			tmp = n / 2;
			if (i - tmp >= 0 && j - tmp >= 0 && (data->grid[i - tmp][j - tmp] == p || data->grid[i - tmp][j - tmp] == ft_tolower(p)))
				return (n);
			if (i - tmp >= 0 && j + tmp >= 0 && (data->grid[i - tmp][j + tmp] == p || data->grid[i - tmp][j + tmp] == ft_tolower(p)))
				return (n);
			if (i + tmp >= 0 && j + tmp >= 0 && (data->grid[i + tmp][j + tmp] == p || data->grid[i + tmp][j + tmp] == ft_tolower(p)))
				return (n);
			if (i + tmp >= 0 && j - tmp >= 0 && (data->grid[i + tmp][j - tmp] == p || data->grid[i + tmp][j - tmp] == ft_tolower(p)))
				return (n);
		}
	}
	return (ft_absolute_distance(pos1, pos2));
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
				data->dist = closest(pos1, pos2, data, i);
				if (data->dist + '0' == 79 || data->dist + '0' == 111 \
				|| data->dist + '0' == 88 || data->dist + '0' == 120)
					data->solving_grid_helper[j] = data->dist + '1';
				else
					data->solving_grid_helper[j] = data->dist + '0';
			}
		}
		data->solving_grid[i] = data->solving_grid_helper;
	}
	data->solving_grid[i] = NULL;
}
