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
	// ft_printf("line to check read piece = %s\n", line);
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
	// ft_printf("data->piece_x = %d\n", data->piece_x);
	// ft_printf("data->piece_y = %d\n", data->piece_y);
	free(tmp);
}

static void	piece_helper(int ret, char *line, t_board *data)
{
	int	y;

	y = 0;
	data->piece_helper = ft_strnew(data->piece_y);
	while (*line && *line != '.' && *line != '*')
		line++;
	data->piece_helper = ft_strcpy(data->piece_helper, line);
	y++;
}

int	make_piece(t_board *data)
{
	int		ret;
	char	*line;

	line =  NULL;
	data->line_helper = 0;
	read_piece(data);
	data->piece = (char **)malloc(sizeof(char*) * (data->piece_x + 1));
	while (data->piece_x > data->line_helper)
	{
		ret = get_next_line(0, &line);
		piece_helper(ret, line, data);
		data->piece[data->line_helper] = data->piece_helper;
		data->line_helper++;
		free(line);
	}
	data->piece[data->line_helper] = NULL;
	return(1);
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
	j = 0;
	k = 0;
	l = 0;
	sum = 0;
	test = 0;
	sol->sum = 0;
	while (data->solving_grid[i] != NULL) // check line / line
	{
		ft_printf("first while\n");
		j = 0;
		while (data->solving_grid[i][j] != '\0') // check column / column
		{
			ft_printf("second while\n");
			test = is_placable(data, i, j);
			ft_printf("====> is placable = [%d]<====\n", test);
			if (test == 1)
			{
				// check piece
				while (data->piece[k] != NULL)
				{
					ft_printf("third while\n");
					l = 0;
					while (data->piece[k][l] != '\0' && \
					i + k <= data->grid_x && j + l <= data->grid_y)
					{
						ft_printf("4th while\n");
						ft_printf("====>[%c]<=====\n", data->solving_grid[i][j]);
						if (data->piece[k][l] == '*')
						{
							ft_printf("data->piece[k][l] = [%c]\n", data->piece[k][l]);
							ft_printf("solving grid = [%c]\n", data->solving_grid[i + k][j + l]);
							if (data->solving_grid[i + k][j + l] != 'X')
								sum += data->solving_grid[i + k][j + l] - '0';
						}
						l++;
					}
					k++;
				}
				if (sum < sol->sum || sol->sum == 0)
				{
					sol->x = i;
					sol->y = j;
					sol->sum = sum;
				}
				i++;
			}
			j++;
		}
		i++;
	}
	ft_printf("sol sum = [%d]\n", sol->sum);
	ft_printf("sol x = [%d]\n", sol->x);
	ft_printf("sol y = [%d]\n", sol->y);
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
	ft_printf("data offset = %d\n", data->piece_offset);
	put_piece(data, sol);
}

int	is_placable(t_board *data, int i, int j)
{
	// DO I NEED TO CHECK TO TRIM THE . IF NO * after
	int	k;
	int	l;
	int	x_count;

	k = -1;
	l = -1;
	x_count = 0;
	ft_printf("i = [%d]\n", i);
	ft_printf("j = [%d]\n", j);
	// ça reste dans la map
	while (++k < data->piece_x) // ligne++
	{
		if (i + data->piece_x > data->grid_x)
		{
			ft_printf("1\n");
			return (0);
		}
		l = -1;
		ft_printf("k = [%d]\n", k);
		while (++l < data->piece_y) // column++
		{
			if (j + data->piece_y > data->grid_y)
			{
				ft_printf("2\n");
				return (0);
			}
			if (i + k > data->grid_x || j + l > data->grid_y)
			{
				ft_printf("3\n");
				return (0);
			}
			if (data->solving_grid[i + k][j + l] == 'O') // piece collision
			{
				ft_printf("4\n");
				return (0);
			}
			if (data->solving_grid[i + k][j + l] == 'X' && data->piece[k][l] == '*')
			{
				ft_printf("data solving grid value : [%c]\n", data->solving_grid[i + k][j + l]);
				ft_printf("i = [%d]\n", i);
				ft_printf("j = [%d]\n", j);
				ft_printf("k = [%d]\n", k);
				ft_printf("l = [%d]\n", l);
				ft_printf("5\n");
				x_count++;
			}
			ft_printf("l = [%d]\n", l);
		}
	}
	if (x_count != 1) // too much X
	{
		ft_printf("6\n");
		return (0);
	}
	return (1);
}