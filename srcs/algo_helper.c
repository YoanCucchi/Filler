/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:37:58 by ycucchi           #+#    #+#             */
/*   Updated: 2022/08/09 14:37:59 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/filler.h"

int	anyone_up(t_board *data, int i, int j)
{
	int	tmp;

	tmp = i;
	while (i-- <= tmp && i > 0)
	{
		if (data->solving_grid[i][j] == data->player_piece)
			return (0);
		if (data->solving_grid[i][j] == data->ennemy_piece)
		{
			// dprintf(2,"data->solving_grid[i][j] = %c\n", data->solving_grid[i][j]);
			return (1);
		}
	}
	// dprintf(2, "nothing up\n");
	return (0);
}

int	anyone_left(t_board *data, int i, int j)
{
	int	tmp;

	tmp = j;
	while (j-- <= tmp && j > 0)
	{
		if (data->solving_grid[i][j] == data->player_piece)
			return (0);
		if (data->solving_grid[i][j] == data->ennemy_piece)
		{
			// dprintf(2,"data->solving_grid[i][j] = %c\n", data->solving_grid[i][j]);
			return (1);
		}
	}
	return (0);
}

int	anyone_right(t_board *data, int i, int j)
{
	int	tmp;

	tmp = j;
	while (j++ <= tmp && j <= data->grid_y)
	{
		if (data->solving_grid[i][j] == data->player_piece)
			return (0);
		if (data->solving_grid[i][j] == data->ennemy_piece)
		{
			// dprintf(2,"data->solving_grid[i][j] = %c\n", data->solving_grid[i][j]);
			return (1);
		}

	}
	return (0);
}

int	anyone_bottom(t_board *data, int i, int j)
{
	int	tmp;

	tmp = i;
	while (i++ <= tmp && i <= data->grid_x)
	{
		if (data->solving_grid[i][j] == data->player_piece)
			return (0);
		if (data->solving_grid[i][j] == data->ennemy_piece)
		{
			// dprintf(2,"data->solving_grid[i][j] = %c\n", data->solving_grid[i][j]);
			return (1);
		}
	}
	// dprintf(2, "nothing up\n");
	return (0);
}
