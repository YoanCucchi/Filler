/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 04:16:53 by ycucchi           #+#    #+#             */
/*   Updated: 2022/07/20 04:16:55 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	check_left(t_pos *pos2, t_pos pos1, int n)
{
	int	i;
	int	j;

	i = pos1.x;
	j = pos1.y;
	pos2->x = i;
	pos2->y = j - n;
	return (ft_absolute_distance(pos1, pos2));
}

int	check_top(t_pos *pos2, t_pos pos1, int n)
{
	int	i;
	int	j;

	i = pos1.x;
	j = pos1.y;
	pos2->x = i - n;
	pos2->y = j;
	return (ft_absolute_distance(pos1, pos2));
}

int	check_right(t_pos *pos2, t_pos pos1, int n)
{
	int	i;
	int	j;

	i = pos1.x;
	j = pos1.y;
	pos2->x = i;
	pos2->y = j + n;
	return (ft_absolute_distance(pos1, pos2));
}

int	check_bottom(t_pos *pos2, t_pos pos1, int n)
{
	int	i;
	int	j;

	i = pos1.x;
	j = pos1.y;
	pos2->x = i + n;
	pos2->y = j;
	return (ft_absolute_distance(pos1, pos2));
}

void	do_sum(t_board *data, int i, int j)
{
	int	k;
	int	l;

	data->sum = 0;
	data->not_placable = 1;
	k = 0;
	while (data->piece[k] != NULL)
	{
		l = 0;
		while (data->piece[k][l] != '\0' &&
			i + k <= data->grid_x && j + l <= data->grid_y)
		{
			if (data->piece[k][l] == '*')
			{
				if ((data->solving_grid[i + k][j + l] != data->player_piece || \
					data->solving_grid[i + k][j + l] != \
					ft_tolower(data->player_piece)))
					data->sum += data->solving_grid[i + k][j + l] - '0';
			}
			l++;
		}
		k++;
	}
}
