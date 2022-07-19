/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:47:58 by ycucchi           #+#    #+#             */
/*   Updated: 2022/06/30 17:47:59 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/filler.h"

void	init_struct(t_board *data, t_pos *pos2, t_solved *sol)
{
	ft_bzero(data, sizeof (t_board));
	ft_bzero(pos2, sizeof (t_pos));
	ft_bzero(sol, sizeof (t_solved));
	data->turn = 0;
	data->player_x = 0;
	data->player_y = 0;
	data->ennemy_x = 0;
	data->ennemy_y = 0;
	data->line_helper = 0;
	data->grid_x = 0;
	data->grid_y = 0;
	data->piece_x = 0;
	data->piece_y = 0;
	data->piece_offset = 0;
	data->player_piece = 0;
	data->ennemy_piece = 0;
	data->grid = NULL;
	data->grid_helper = NULL;
	data->piece = NULL;
	data->piece_helper = NULL;
}

void	free_struct(t_board *data)
{
	if (data->grid)
		free(data->grid);
	if (data->grid_helper)
		free(data->grid_helper);
	if (data->piece)
		free(data->piece);
	if (data->piece_helper)
		free(data->piece_helper);
}
