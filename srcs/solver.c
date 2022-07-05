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

static long				ft_pow(int nbr, int power)
{
	long	result;

	if (power < 0)
		return (-1);
	result = 1;
	while (power--)
		result *= nbr;
	return (result);
}

static unsigned long	ft_sqrt(long nbr)
{
	unsigned long	result;

	if (nbr <= 0)
		return (0);
	result = 1;
	while (result * result < (unsigned long)nbr)
		result++;
	return (result);
}

unsigned long			ft_absolute_distance(t_pos pos1, t_pos pos2)
{
	return (ft_sqrt(ft_pow(pos1.x - pos2.x, 2) + ft_pow(pos1.y - pos2.y, 2)));
}

static int	is_inside_map(int i, int j, t_board *data)
{
	ft_printf("i inside map = %d\n", i);
	ft_printf("j inside map = %d\n", j);
	ft_printf("data->grid_x = %d\n", data->grid_x);
	ft_printf("data->grid_y = %d\n", data->grid_y);
	if (i > data->grid_x || i > 0 || j < 0 || j > data->grid_y)
		return (0);
	return (1);
}

static t_pos	closest(t_pos pos1, t_pos pos2, t_board *data)
{
	int	i;
	int	j;
	int	n;

	i = pos1.x;
	j = pos1.y;
	ft_printf("i inside closest = %d\n", i);
	ft_printf("j inside closest = %d\n", j);
	n = 1;
	ft_printf("data grid = %c\n", data->grid[i][j]);
	// pos1 == where am i checking
	while (i + n < data->grid_x && j + n < data->grid_y)
	{
		ft_printf("n = %d\n", n);
		if (i >= 0 && j - n >= 0 && data->grid[i][j - n] == 'O')
		{
			// check left
			ft_printf("inside left\n");
			ft_printf("data->grid left = %c\n", data->grid[i][j - n]);
			if (data->grid[i][j - n] == 'O')
			{
				pos2.x = i;
				pos2.y = j - n;
				return(pos2);
			}
		}
		// check top
		if (i - n >= 0 && j >= 0 && data->grid[i - n][1] == 'O')
		{
			ft_printf("inside top\n");
			ft_printf("data->grid top = %c\n", data->grid[i - n][j]);
			if (data->grid[i - n][j] == 'O')
			{
				pos2.x = i - n;
				pos2.y = j;
				return(pos2);
			}
		}
		// check right
		if (i >= 0 && j >= 0 && data->grid[i][j + n] == 'O')
		{
			ft_printf("inside right\n");
			ft_printf("data->grid right = %c\n", data->grid[i][j + n]);
			if (data->grid[i][j + n] == 'O')
			{
				pos2.x = i;
				pos2.y = j + n;
				return(pos2);
			}
		}
		// check bottom
		if (i >= 0 && j >= 0 && data->grid[i + n][j] == 'O')
		{
			ft_printf("inside bottom\n");
			ft_printf("data->grid bottom = %c\n", data->grid[i + n][j]);
			if (data->grid[i + n][j] == 'O')
			{
				pos2.x = i + n;
				pos2.y = j;
				return(pos2);
			}
		}
		n++;
	}
	ft_printf("data test = %c\n", data->grid[0][0]);
	ft_printf("test\n");
	return(pos2);
}

void	solving_grid(t_board *data)
{
	int	dist;
	t_pos	pos1 = {0,0};
	t_pos	pos2 = {0,0};
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
	dist = 0;
	data->solving_grid = (char **)malloc(sizeof(char*) * (data->grid_x + 1));
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
				ft_printf("pos1.x = %d\n", pos1.x);
				ft_printf("pos1.y = %d\n", pos1.y);
				pos2 = closest(pos1, pos2, data);
				ft_printf("pos2.x = %d\n", pos2.x);
				ft_printf("pos2.y = %d\n", pos2.y);
				dist = ft_absolute_distance(pos1, pos2);
				ft_printf("dist = %d\n", dist);
				data->solving_grid_helper[j] = dist + '0'; // convert to char
			}
			j++;
		}
		data->solving_grid[i] = data->solving_grid_helper;
		ft_printf("data->solving grid i = %s\n", data->solving_grid[i]);
		ft_printf("i = %d\n", i);
		i++;
	}
	data->solving_grid[i] = NULL;
	// ft_printf("value = %d\n", data->solving_grid[5][5] - '0'); // return the value
}
