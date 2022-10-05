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
	data->turn = 1;
}
