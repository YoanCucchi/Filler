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

void	sol_store_spe(t_board *data, t_solved *sol, int i, int j)
{
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
		sol->special_case = 1;
		dprintf(2, "i = %d\n", i);
		dprintf(2, "j = %d\n", j);
		dprintf(2, "sol->x = %d\n", sol->x);
		dprintf(2, "sol->y = %d\n", sol->y);
		dprintf(2, "sol sum = %d\n", sol->sum);
}

void	sol_store(t_board *data, t_solved *sol, int i, int j)
{
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
		dprintf(2, "i = %d\n", i);
		dprintf(2, "j = %d\n", j);
		dprintf(2, "sol->x = %d\n", sol->x);
		dprintf(2, "sol->y = %d\n", sol->y);
		dprintf(2, "sol sum = %d\n", sol->sum);
}

void reset_some_params(t_board *data, t_solved *sol)
{
	data->placable = 0;
	data->not_placable = 0;
	sol->sum = 0;
	sol->special_case = 0;
}