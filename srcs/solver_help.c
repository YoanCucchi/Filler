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

int	check_left(t_pos *pos2, t_pos pos1, int n)
{
	int	i;
	int	j;

	i = pos1.x;
	j = pos1.y;
	pos2->x = i;
	pos2->y = j - n;
	return (ft_absolute_distance(pos1, pos2));
}

int	check_top(t_pos *pos2, t_pos pos1, int n)
{
	int	i;
	int	j;

	i = pos1.x;
	j = pos1.y;
	pos2->x = i - n;
	pos2->y = j;
	return (ft_absolute_distance(pos1, pos2));
}

int	check_right(t_pos *pos2, t_pos pos1, int n)
{
	int	i;
	int	j;

	i = pos1.x;
	j = pos1.y;
	pos2->x = i;
	pos2->y = j + n;
	return (ft_absolute_distance(pos1, pos2));
}

int	check_bottom(t_pos *pos2, t_pos pos1, int n)
{
	int	i;
	int	j;

	i = pos1.x;
	j = pos1.y;
	pos2->x = i + n;
	pos2->y = j;
	return (ft_absolute_distance(pos1, pos2));
}
