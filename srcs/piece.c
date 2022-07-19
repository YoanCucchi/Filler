/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:47:45 by ycucchi           #+#    #+#             */
/*   Updated: 2022/06/30 17:47:47 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/filler.h"

void	read_piece(t_board *data)
{
	int		len;
	int		ret;
	char	*tmp;
	char	*line;

	line = NULL;
	len = 0;
	ret = get_next_line(0, &line);
	tmp = line;
	// dprintf(2, "line to check read piece = %s\n", line);
	while(!ft_isdigit(*line))
		line++;
	// ft_printf("line to afeterererr = %s\n", line);
	data->piece_x = ft_atoi(line);
	len = ft_nbrlen(data->piece_x, 10) + 1;
	while (len--)
		line++;
	while(!ft_isdigit(*line))
		line++;
	data->piece_y = ft_atoi(line);
	// dprintf(2, "data->piece_x = %d\n", data->piece_x);
	// dprintf(2, "data->piece_y = %d\n", data->piece_y);
	free(tmp);
}

int	make_piece(t_board *data)
{
	int		ret;
	char	*line;

	line =  NULL;
	data->line_helper = 0;
	data->piece = (char **)malloc(sizeof(char*) * (data->piece_x + 1));
	if (!data->piece)
	{
		ft_printf("Malloc error\n");
		return (0);
	}
	while (data->piece_x > data->line_helper)
	{
		ret = get_next_line(0, &line);
		data->piece_helper = ft_strnew(data->piece_y);
		while (*line && *line != '.' && *line != '*')
			line++;
		data->piece_helper = ft_strcpy(data->piece_helper, line);
		data->piece[data->line_helper] = data->piece_helper;
		data->line_helper++;
		ft_strdel(&line);
	}
	data->piece[data->line_helper] = NULL;
	return (1);
}

void	put_piece(t_board *data, t_solved *sol)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	sum;
	int	test;

	i = 0;
	test = 0;
	sol->sum = 0;
	while (data->solving_grid[i] != NULL) // check line / line
	{
		// ft_printf("first while\n");
		j = 0;
		while (data->solving_grid[i][j] != '\0') // check column / column
		{
			// ft_printf("second while\n");
			test = is_placable(data, i, j);
			// ft_printf("====> is placable = [%d]<====\n", test);
			if (test == 1)
			{
				// check piece
				sum = 0;
				k = 0;
				while (data->piece[k] != NULL)
				{
					// ft_printf("third while\n");
					l = 0;
					while (data->piece[k][l] != '\0' && \
					i + k <= data->grid_x && j + l <= data->grid_y)
					{
						// ft_printf("4th while\n");
						// ft_printf("====>[%c]<=====\n", data->solving_grid[i][j]);
						if (data->piece[k][l] == '*')
						{
							// ft_printf("data->piece[k][l] = [%c]\n", data->piece[k][l]);
							// ft_printf("solving grid = [%c]\n", data->solving_grid[i + k][j + l]);
							if ((data->solving_grid[i + k][j + l] != 'X' || data->solving_grid[i + k][j + l] != 'x'))
								sum += data->solving_grid[i + k][j + l] - '0';
						}
						l++;
					}
					k++;
				}
				// ft_printf("sum in put piece = %d\n", sum);
				// if (sum = sol->sum) 2 solutions possible faut chosir
				// need to finish X to the right to block the opponent
				if ((j < sol->y || sol->sum == 0) && data->turn < 20 && j > 0)
				{
					sol->x = i;
					sol->y = j;
					sol->sum = sum;
				}
				else if ((j < sol->y && i < sol->x) && data->turn < 20)
				{
					sol->x = i;
					sol->y = j;
					sol->sum = sum;
				}
				else if ((sum - 5 <= sol->sum && sum - 5 > 0 && i <= sol->x && j <= sol->y && data->turn < 30))
				{
					sol->x = i;
					sol->y = j;
					sol->sum = sum;
				}
				else if ((sum < sol->sum || sol->sum == 0) && data->turn >= 20)
				{
					sol->x = i;
					sol->y = j;
					sol->sum = sum;
				}
			}
			j++;
		}
		i++;
	}
	// ft_printf("sol sum = [%d]\n", sol->sum);
}

void	piece_offset(t_board *data, t_solved *sol)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < data->piece_y && data->piece[i][j] != '\0')
	{
		if (data->piece[i][j] != '*')
			data->piece_offset++;
		j++;
	}
	// ft_printf("data offset = %d\n", data->piece_offset);
	put_piece(data, sol);
}

int	is_placable(t_board *data, int i, int j)
{
	// DO I NEED TO CHECK TO TRIM THE . IF NO * after ==> looks like i don't need
	int	k;
	int	l;
	int	x_count;

	k = -1;
	l = -1;
	x_count = 0;
	// ft_printf("i = [%d]\n", i);
	// ft_printf("j = [%d]\n", j);
	// ça reste dans la map
	while (++k < data->piece_x) // ligne++
	{
		if (i + data->piece_x > data->grid_x)
			return (0);
		l = -1;
		// ft_printf("k = [%d]\n", k);
		while (++l < data->piece_y) // column++
		{
			if (j + data->piece_y > data->grid_y)
				return (0);
			if (i + k > data->grid_x || j + l > data->grid_y)
				return (0);
			if (data->solving_grid[i + k][j + l] == 'O' || \
			data->solving_grid[i + k][j + l] == 'o') // piece collision
				return (0);
			if ((data->solving_grid[i + k][j + l] == 'X' || data->solving_grid[i + k][j + l] == 'x') && data->piece[k][l] == '*')
			{
				// ft_printf("data solving grid value : [%c]\n", data->solving_grid[i + k][j + l]);
				// ft_printf("i = [%d]\n", i);
				// ft_printf("j = [%d]\n", j);
				// ft_printf("k = [%d]\n", k);
				// ft_printf("l = [%d]\n", l);
				x_count++;
			}
			// ft_printf("l = [%d]\n", l);
		}
	}
	if (x_count != 1) // too much X or not enough
		return (0);
	return (1);
}