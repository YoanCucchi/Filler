/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:47:51 by ycucchi           #+#    #+#             */
/*   Updated: 2022/06/30 17:47:52 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/filler.h"

long	ft_absolute_distance(t_pos pos1, t_pos *pos2)
{
	return (ft_sqrt(ft_pow(pos1.x - pos2->x, 2) + ft_pow(pos1.y - pos2->y, 2)));
}

static int	closest(t_pos pos1, t_pos *pos2, t_board *data)
{
	int	i;
	int	j;
	int	n;
	int	tmp;

	n = 1;
	i = pos1.x;
	j = pos1.y;
	// ft_printf("data grid = %c\n", data->grid[i][j]);
	// pos1 == where am i checking
	while (i + n < data->grid_x && j + n < data->grid_y)
	{
		// ft_printf("n = %d\n", n);
		tmp = 0;
		if (i >= 0 && j - n >= 0 && (data->grid[i][j - n] == data->ennemy_piece || data->grid[i][j - n] == ft_tolower(data->ennemy_piece)))
			return (check_left(pos2, pos1, n));
		if (i - n >= 0 && j >= 0 && (data->grid[i - n][j] == data->ennemy_piece || data->grid[i - n][j] == ft_tolower(data->ennemy_piece)))
			return (check_top(pos2, pos1, n));
		if (i >= 0 && j >= 0 && (data->grid[i][j + n] == data->ennemy_piece || data->grid[i][j + n] == ft_tolower(data->ennemy_piece)))
			return (check_right(pos2, pos1, n));
		if (i >= 0 && j >= 0 && (data->grid[i + n][j] == data->ennemy_piece || data->grid[i + n][j] == ft_tolower(data->ennemy_piece)))
			return (check_bottom(pos2, pos1, n));
		if (n % 2 == 0)
		{
			tmp = n / 2;
			// ft_printf("tmp = %d", tmp);
			// ft_printf("n = %d\n", n);
			if (i - tmp >= 0 && j - tmp >= 0 && (data->grid[i - tmp][j - tmp] == data->ennemy_piece || data->grid[i - tmp][j - tmp] == ft_tolower(data->ennemy_piece)))
				return (n);
			if (i - tmp >= 0 && j + tmp >= 0 && (data->grid[i - tmp][j + tmp] == data->ennemy_piece || data->grid[i - tmp][j + tmp] == ft_tolower(data->ennemy_piece)))
				return (n);
			if (i + tmp >= 0 && j + tmp >= 0 && (data->grid[i + tmp][j + tmp] == data->ennemy_piece || data->grid[i + tmp][j + tmp] == ft_tolower(data->ennemy_piece)))
				return (n);
			if (i + tmp >= 0 && j - tmp >= 0 && (data->grid[i + tmp][j - tmp] == data->ennemy_piece || data->grid[i + tmp][j - tmp] == ft_tolower(data->ennemy_piece)))
				return (n);
		}
		n++;
	}
	return (ft_absolute_distance(pos1, pos2));
}

void	solving_grid(t_board *data, t_pos *pos2)
{
	int		dist;
	t_pos	pos1;
	int		i;
	int		j;

	i = 0;
	j = 0;
	pos1.x = 0;
	pos1.y= 0;
	pos2->x = data->ennemy_x;
	pos2->y = data->ennemy_y;
	dist = 0;
	while (data->grid[i]) // ligne par ligne ++
	{
		data->solving_grid_helper = ft_strnew(data->grid_y);
		data->solving_grid_helper = ft_strcpy(data->solving_grid_helper, data->grid[i]);
		j = 0;
		while (data->grid[i][j] != '\0') // column ++ a chaque ligne
		{
			if (data->solving_grid_helper[j] == '.')
			{
				pos1.x = i;
				pos1.y = j;
				dist = closest(pos1, pos2, data);
				data->solving_grid_helper[j] = dist + '0'; // convert to char
			}
			j++;
		}
		data->solving_grid[i] = data->solving_grid_helper;
		i++;
	}
	data->solving_grid[i] = NULL;
}
