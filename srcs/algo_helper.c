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

#include "filler.h"

void	sol_store_spe(t_board *data, t_solved *sol, int i, int j)
{
	sol->x = i;
	sol->y = j;
	sol->sum = data->sum;
	sol->special_case = 1;
}

void	sol_store(t_board *data, t_solved *sol, int i, int j)
{
	sol->x = i;
	sol->y = j;
	sol->sum = data->sum;
}

void	reset_some_params(t_board *data, t_solved *sol)
{
	data->placable = 0;
	data->not_placable = 0;
	sol->sum = 0;
	sol->special_case = 0;
}

int	in_the_middle(t_board *data)
{
	int	i;
	int	j;
	int	k;
	int	l;

	k = data->grid_x / 2 + 1;
	l = data->grid_y / 2 + 1;
	i = -1;
	while (++i <= k)
	{
		j = -1;
		while (++j <= l)
		{
			if (i == 0 && j == 0 && (data->grid[i][j] == data->player_piece || \
			data->grid[i][j] == ft_tolower(data->player_piece)))
			{
				data->closed = 1;
				return (0);
			}
			if (i < k && j < l && (data->grid[i][j] == data->player_piece || \
			data->grid[i][j] == ft_tolower(data->player_piece)))
				return (1);
		}
	}
	return (0);
}

int	bot_right_clean(t_board *data)
{
	int	i;

	i = data->grid_x - 1;
	while (i >= 1)
	{
		if (data->grid[i][data->grid_y - 1] == data->player_piece || \
		data->grid[i][data->grid_y - 1] == ft_tolower(data->player_piece))
		{
			data->bot_closed = 1;
			return (1);
		}
		if (data->grid[i][data->grid_y - 1] == data->ennemy_piece || \
		data->grid[i][data->grid_y - 1] == ft_tolower(data->ennemy_piece))
		{
			if (data->grid[i - 1][data->grid_y - 1] == data->player_piece || \
			data->grid[i - 1][data->grid_y - 1] == \
			ft_tolower(data->player_piece))
			{
				data->bot_closed = 1;
				return (1);
			}
		}
		i--;
	}
	return (0);
}
