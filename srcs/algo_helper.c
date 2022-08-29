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
