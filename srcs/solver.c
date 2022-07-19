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

long		ft_absolute_distance(t_pos pos1, t_pos *pos2)
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
		if (i >= 0 && j - n >= 0 && (data->grid[i][j - n] == 'O' || data->grid[i][j - n] == 'o'))
			return(check_left(pos2, pos1, n));
		if (i - n >= 0 && j >= 0 && (data->grid[i - n][j] == 'O' || data->grid[i - n][j] == 'o'))
			return(check_top(pos2, pos1, n));
		if (i >= 0 && j >= 0 && (data->grid[i][j + n] == 'O' || data->grid[i][j + n] == 'o'))
			return(check_right(pos2, pos1, n));
		if (i >= 0 && j >= 0 && (data->grid[i + n][j] == 'O' || data->grid[i + n][j] == 'o'))
			return(check_bottom(pos2, pos1, n));
		if (n % 2 == 0)
		{
			tmp = n / 2;
			// ft_printf("tmp = %d", tmp);
			// ft_printf("n = %d\n", n);
			if (i - tmp >= 0 && j - tmp >= 0 && (data->grid[i - tmp][j - tmp] == 'O' || data->grid[i - tmp][j - tmp] == 'o'))
				return(n);
			if (i - tmp >= 0 && j + tmp >= 0 && (data->grid[i - tmp][j + tmp] == 'O' || data->grid[i - tmp][j + tmp] == 'o'))
				return(n);
			if (i + tmp >= 0 && j + tmp >= 0 && (data->grid[i + tmp][j + tmp] == 'O' || data->grid[i + tmp][j + tmp] == 'o'))
				return(n);
			if (i + tmp >= 0 && j - tmp >= 0 && (data->grid[i + tmp][j - tmp] == 'O' || data->grid[i + tmp][j - tmp] == 'o'))
				return(n);
		}
		n++;
	}
	return(ft_absolute_distance(pos1, pos2));
}

void		solving_grid(t_board *data, t_pos *pos2)
{
	int	dist;
	t_pos	pos1 = {0,0};
	// ft_printf("pos1x = %d\n", pos1.x);
	// ft_printf("pos1y = %d\n", pos1.y);
	// ft_printf("pos2x = %d\n", pos2.x);
	// ft_printf("pos2y = %d\n", pos2.y);
	// test = ft_absolute_distance(pos1, pos2);
	// ft_printf("test = %d\n", test);
	int	i;
	int	j;

	i = 0;
	j = 0;
	pos2->x = data->ennemy_x;
	pos2->y = data->ennemy_y;
	dist = 0;
	while (data->grid[i]) // ligne par ligne ++
	{
		data->solving_grid_helper = ft_strnew(data->grid_y);
		data->solving_grid_helper = ft_strcpy(data->solving_grid_helper, data->grid[i]);
		j = 0;
		while(data->grid[i][j] != '\0') // column ++ a chaque ligne
		{
			if (data->solving_grid_helper[j] == '.')
			{
				pos1.x = i;
				pos1.y = j;
				// ft_printf("pos1.x = %d\n", pos1.x);
				// ft_printf("pos1.y = %d\n", pos1.y);
				dist = closest(pos1, pos2, data);
				// ft_printf("pos2.x = %d\n", pos2->x);
				// ft_printf("pos2.y = %d\n", pos2->y);
				// ft_printf("dist = %d\n", dist);
				data->solving_grid_helper[j] = dist + '0'; // convert to char
			}
			j++;
		}
		data->solving_grid[i] = data->solving_grid_helper;
		// ft_printf("data->solving grid i = %s\n", data->solving_grid[i]);
		// ft_printf("i = %d\n", i);
		i++;
	}
	data->solving_grid[i] = NULL;
	// ft_printf("value = %d\n", data->solving_grid[5][5] - '0'); // return the value
}
