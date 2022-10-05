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

#include ".././includes/filler.h"

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

int	clean_all(t_board *data, t_pos *pos2, t_solved *sol, char *str)
{
	dprintf(2, "start of clean all\n");
	if (!data)
		return (0);
	if (data->piece)
	{
		free_piece(data);
		dprintf(2, "1");
	}
	if (data->grid)
	{
		free_grid(data);
		dprintf(2, "2");
	}
	if (data->solving_grid)
	{
		free_solving_grid(data);
		dprintf(2, "3");
	}
	if (pos2)
	{
		free(pos2);
		dprintf(2, "4");
	}
	if (sol)
	{
		free(sol);
		dprintf(2, "5");
	}
	if (data)
	{
		free(data);
		dprintf(2, "6");
	}
	if (ft_strcmp(str, ""))
		ft_putendl_fd(str, 2);
	dprintf(2, "end of clean all\n");
	return (0);
}
