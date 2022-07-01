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

void	init_struct(t_board *p)
{
	p->player_x = 0;
	p->player_y = 0;
	p->ennemy_x = 0;
	p->ennemy_y = 0;
	p->line_helper = 0;
	p->grid_x = 0;
	p->grid_y = 0;
	p->piece_x = 0;
	p->piece_y = 0;
	p->player_piece = 0;
	p->grid = NULL;
	p->grid_helper = NULL;
	p->piece = NULL;
	p->piece_helper = NULL;
}

void	free_struct(t_board *p)
{
	if (p->grid)
		free(p->grid);
	if (p->grid_helper)
		free(p->grid_helper);
	if (p->piece)
		free(p->piece);
	if (p->piece_helper)
		free(p->piece_helper);
}
