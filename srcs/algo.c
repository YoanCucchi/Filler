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
	{
		dprintf(2, "closest\n");
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
		dprintf(2, "i = %d\n", i);
		dprintf(2, "j = %d\n", j);
		dprintf(2, "sol->x = %d\n", sol->x);
		dprintf(2, "sol->y = %d\n", sol->y);
	}
}

void	do_algo_bot_right_small(t_board *data, t_solved *sol, int i, int j)
{
	if (data->turn <= 25 && (i <= sol->x || sol->sum == 0))
	{
		dprintf(2, "go up 25 first turns\n");
		sol_store_spe(data, sol, i, j);
	}
	else if (in_the_middle(data) && (i < sol->x || j < sol->y) && \
	data->turn < 55 && data->turn > 25)
	{
		dprintf(2, "go top left 25->55 turns\n");
		sol_store_spe(data, sol, i, j);
	}
	else if (data->closed && j >= sol->y && !data->bot_closed)
	{
		bot_right_clean(data);
		dprintf(2, "close bot right\n");
		sol_store_spe(data, sol, i, j);
	}
	else if ((data->sum < sol->sum || sol->sum == 0) && \
	(!sol->special_case || data->bot_closed == 1))
	{
		dprintf(2, "closest\n");
		sol_store(data, sol, i, j);
	}
}

void	do_algo_bot_right_medium(t_board *data, t_solved *sol, int i, int j)
{
	if (data->turn <= 5 && (i < sol->x || sol->sum == 0))
		sol_store_spe(data, sol, i, j);
	else if (data->turn > 5 && data->turn <= 15 && data->piece_x > data->piece_y && (i < sol->x || sol->sum == 0))
		sol_store_spe(data, sol, i, j);
	else if (data->turn > 5 && data->turn <= 15 && data->piece_x <= data->piece_y && (j <= sol->y || sol->sum == 0))
		sol_store_spe(data, sol, i, j);
	else if (data->turn % 2 == 1 && \
	((i >= sol->x && j < sol->y) || sol->sum == 0) && data->turn < 55 && data->turn > 5)
		sol_store_spe(data, sol, i, j);
	else if (data->turn % 2 == 0 && ((i <= sol->x && j > sol->y) || sol->sum == 0) && data->turn < 55 && data->turn > 5)
		sol_store_spe(data, sol, i, j);
	else if ((data->sum < sol->sum || sol->sum == 0) && \
	(!sol->special_case || data->bot_closed == 1))
		sol_store(data, sol, i, j);
}

void	do_algo_bot_right_huge(t_board *data, t_solved *sol, int i, int j)
{
	// marche pas mal mais il faut bloquer le coté bas droite pour win plus souv
	if (data->turn <= 10 && (j < sol->y || sol->sum == 0))
	{
		dprintf(2, "test1\n");
		sol_store_spe(data, sol, i, j);
	}
	else if (data->turn > 5 && data->turn <= 20 && data->piece_x > data->piece_y && (i < sol->x || sol->sum == 0))
	{
		dprintf(2, "test2\n");
		sol_store_spe(data, sol, i, j);
	}
	else if (data->turn > 5 && data->turn <= 20 && data->piece_x <= data->piece_y && (j <= sol->y || sol->sum == 0))
	{
		dprintf(2, "test3\n");
		sol_store_spe(data, sol, i, j);
	}
	else if (data->turn % 2 == 1 && \
	((i >= sol->x && j < sol->y) || sol->sum == 0) && data->turn < 100 && data->turn > 10)
	{
		dprintf(2, "test4\n");
		sol_store_spe(data, sol, i, j);
	}
	else if (data->turn % 2 == 0 && ((i <= sol->x && j > sol->y) || sol->sum == 0) && data->turn < 55 && data->turn > 10)
	{
		dprintf(2, "test5\n");
		sol_store_spe(data, sol, i, j);
	}
	else if ((data->sum < sol->sum || sol->sum == 0) && !sol->special_case)
	{
		dprintf(2, "test6\n");
		sol_store(data, sol, i, j);
	}
}
