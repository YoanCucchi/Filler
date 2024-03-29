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

#include "filler.h"

long	ft_absolute_distance(t_pos pos1, t_pos *pos2)
{
	return (ft_sqrt(ft_pow(pos1.x - pos2->x, 2) + ft_pow(pos1.y - pos2->y, 2)));
}

int	closest(t_pos pos1, t_pos *pos2, t_board *data, int i)
{
	int	j;
	int	n;
	int	p;

	n = 0;
	j = pos1.y;
	p = data->ennemy_piece;
	while (i + ++n < data->grid_x && j + n < data->grid_y)
	{
		if (i >= 0 && (data->grid[i][j - n] == data->ennemy_piece || \
		data->grid[i][j - n] == ft_tolower(data->ennemy_piece)) && j - n >= 0)
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
		if (n % 2 == 0 && check_diagonal(data, i, j, n) == 1)
			return (n);
	}
	return (ft_absolute_distance(pos1, pos2));
}

int	check_diagonal(t_board *data, int i, int j, int n)
{
	int	p;
	int	tmp;

	p = data->ennemy_piece;
	tmp = n / 2;
	if (i - tmp >= 0 && j - tmp >= 0 && (data->grid[i - tmp][j - tmp] == p || \
	data->grid[i - tmp][j - tmp] == ft_tolower(p)))
		return (1);
	if (i - tmp >= 0 && j + tmp >= 0 && (data->grid[i - tmp][j + tmp] == p || \
	data->grid[i - tmp][j + tmp] == ft_tolower(p)))
		return (1);
	if (i + tmp >= 0 && j + tmp >= 0 && (data->grid[i + tmp][j + tmp] == p || \
	data->grid[i + tmp][j + tmp] == ft_tolower(p)))
		return (1);
	if (i + tmp >= 0 && j - tmp >= 0 && (data->grid[i + tmp][j - tmp] == p || \
	data->grid[i + tmp][j - tmp] == ft_tolower(p)))
		return (1);
	return (0);
}

int	solving_grid(t_board *data, t_pos *pos2, t_pos pos1)
{
	int	i;
	int	j;

	i = -1;
	*pos2 = (t_pos){data->ennemy_x, data->ennemy_y};
	while (data->grid[++i])
	{
		data->solving_help = ft_strnew(data->grid_y);
		data->solving_help = ft_strcpy(data->solving_help, data->grid[i]);
		if (!data->solving_help)
			return (0);
		j = -1;
		while (data->grid[i][++j] != '\0')
		{
			if (data->solving_help[j] == '.')
			{
				pos1 = (t_pos){i, j};
				data->dist = closest(pos1, pos2, data, i);
				dist_exception_ox(data, j);
			}
		}
		data->solving_grid[i] = data->solving_help;
	}
	data->solving_grid[i] = NULL;
	return (1);
}

void	dist_exception_ox(t_board *data, int j)
{
	if (data->dist + '0' == 79 || data->dist + '0' == 111 \
	|| data->dist + '0' == 88 || data->dist + '0' == 120)
		data->solving_help[j] = data->dist + '1';
	else
		data->solving_help[j] = data->dist + '0';
}
