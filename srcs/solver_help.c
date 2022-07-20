/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 04:16:53 by ycucchi           #+#    #+#             */
/*   Updated: 2022/07/20 04:16:55 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/filler.h"

void	check_left(t_board *data, t_pos *pos2, t_pos pos1, int n)
{
	int	i;
	int	j;

	i = pos1.x;
	j = pos1.y;
	pos2->x = i;
	pos2->y = j - n;
	data->dist = ft_absolute_distance(pos1, pos2);
}

void	check_top(t_board *data, t_pos *pos2, t_pos pos1, int n)
{
	int	i;
	int	j;

	i = pos1.x;
	j = pos1.y;
	pos2->x = i - n;
	pos2->y = j;
	data->dist = ft_absolute_distance(pos1, pos2);
}

void	check_right(t_board *data, t_pos *pos2, t_pos pos1, int n)
{
	int	i;
	int	j;

	i = pos1.x;
	j = pos1.y;
	pos2->x = i;
	pos2->y = j + n;
	data->dist = ft_absolute_distance(pos1, pos2);
}

void	check_bottom(t_board *data, t_pos *pos2, t_pos pos1, int n)
{
	int	i;
	int	j;

	i = pos1.x;
	j = pos1.y;
	pos2->x = i + n;
	pos2->y = j;
	data->dist = ft_absolute_distance(pos1, pos2);
}
