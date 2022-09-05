/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:04:59 by ycucchi           #+#    #+#             */
/*   Updated: 2022/08/11 11:05:01 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/filler.h"

void	do_algo_closest(t_board *data, t_solved *sol, int i, int j)
{
	if ((data->sum < sol->sum || sol->sum == 0))
		sol_store_spe(data, sol, i, j);
}

void	do_algo_bot_right_small(t_board *data, t_solved *sol, int i, int j)
{
	if (data->turn <= 25 && (i < sol->x || sol->sum == 0))
		sol_store_spe(data, sol, i, j);
	else if (in_the_middle(data) && data->turn < 45 && data->turn > 25 && \
	(i <= sol->x || j < sol->y || sol->sum == 0))
		sol_store_spe(data, sol, i, j);
	else if (data->closed && j >= sol->y && !data->bot_closed)
	{
		bot_right_clean(data);
		sol_store_spe(data, sol, i, j);
	}
	else if ((data->sum < sol->sum || sol->sum == 0) && \
	(!sol->special_case || data->bot_closed == 1))
		sol_store(data, sol, i, j);
}

void	do_algo_bot_right_medium(t_board *data, t_solved *sol, int i, int j)
{
	if (data->turn <= 5 && (i < sol->x || sol->sum == 0))
		sol_store_spe(data, sol, i, j);
	else if (data->turn > 5 && data->turn <= 15 && \
	data->piece_x > data->piece_y && (i < sol->x || sol->sum == 0))
		sol_store_spe(data, sol, i, j);
	else if (data->turn > 5 && data->turn <= 15 && \
	data->piece_x <= data->piece_y && (j <= sol->y || sol->sum == 0))
		sol_store_spe(data, sol, i, j);
	else if (data->turn % 2 == 1 && data->turn < 55 && data->turn > 5 && \
	((i >= sol->x && j < sol->y) || sol->sum == 0))
		sol_store_spe(data, sol, i, j);
	else if (data->turn % 2 == 0 && data->turn < 55 && data->turn > 5 && \
	((i <= sol->x && j > sol->y) || sol->sum == 0))
		sol_store_spe(data, sol, i, j);
	else if ((data->sum < sol->sum || sol->sum == 0) && \
	(!sol->special_case || data->bot_closed == 1))
		sol_store(data, sol, i, j);
}

void	do_algo_bot_right_huge(t_board *data, t_solved *sol, int i, int j)
{
	if (data->turn <= 10 && (j < sol->y || sol->sum == 0))
		sol_store_spe(data, sol, i, j);
	else if (data->turn <= 20 && data->piece_x > data->piece_y && \
	data->turn > 5 && (i < sol->x || sol->sum == 0) && data->turn > 5)
		sol_store_spe(data, sol, i, j);
	else if (data->turn <= 20 && data->piece_x <= data->piece_y && \
	(j <= sol->y || sol->sum == 0) && data->turn > 5)
		sol_store_spe(data, sol, i, j);
	else if (((i >= sol->x && j < sol->y) || sol->sum == 0) && \
	data->turn < 100 && data->turn > 10 && data->turn % 2 == 1)
		sol_store_spe(data, sol, i, j);
	else if ((i <= sol->x || sol->sum == 0) && \
	data->turn < 60 && data->turn > 10 && data->turn % 2 == 0)
		sol_store_spe(data, sol, i, j);
	else if ((j > sol->y || sol->sum == 0) && \
	data->turn >= 60 && data->turn < 100 && data->turn % 2 == 0)
		sol_store_spe(data, sol, i, j);
	else if ((data->sum < sol->sum || sol->sum == 0) && !sol->special_case)
		sol_store(data, sol, i, j);
}
