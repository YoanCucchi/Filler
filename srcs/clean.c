/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:15:34 by ycucchi           #+#    #+#             */
/*   Updated: 2022/08/29 14:15:35 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_solving_grid(t_board *data)
{
	int	i;

	i = 0;
	while (i < data->grid_x)
	{
		ft_strdel(&data->solving_grid[i]);
		i++;
	}
	free(data->solving_grid);
	data->solving_grid = NULL;
}

void	free_grid(t_board *data)
{
	int	i;

	i = 0;
	while (i < data->grid_x)
	{
		ft_strdel(&data->grid[i]);
		i++;
	}
	free(data->grid);
	data->grid = NULL;
}

void	free_piece(t_board *data)
{
	int	i;

	i = 0;
	while (i < data->piece_x)
	{
		ft_strdel(&data->piece[i]);
		i++;
	}
	free(data->piece);
	data->piece = NULL;
}

int	clean_all(t_board *data, t_pos *pos2, t_solved *sol)
{
	if (!data)
		return (0);
	if (data->piece)
		free_piece(data);
	if (data->grid)
		free_grid(data);
	if (data->solving_grid)
		free_solving_grid(data);
	if (pos2)
		free(pos2);
	if (sol)
		free(sol);
	if (data)
		free(data);
	return (0);
}
