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

void	read_piece(t_board *data, t_pos *pos2, t_solved *sol)
{
	int		len;
	int		ret;
	char	*tmp;
	char	*line;

	line = NULL;
	len = 0;
	ret = get_next_line(0, &line);
	tmp = line;
	while (!ft_isdigit(*line))
		line++;
	data->piece_x = ft_atoi(line);
	len = ft_nbrlen(data->piece_x, 10) + 1;
	while (len--)
		line++;
	while (!ft_isdigit(*line))
		line++;
	data->piece_y = ft_atoi(line);
	if (data->piece_x == 0 || data->piece_y == 0)
		clean_all(data, pos2, sol, "Grid size error\n");
	free(tmp);
	data->piece = (char **)malloc(sizeof(char *) * (data->piece_x + 1));
	if (!data->piece)
		clean_all(data, pos2, sol, "Malloc error\n");
}

int	make_piece(t_board *data)
{
	int		ret;
	char	*line;

	line = NULL;
	data->line_helper = 0;
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

void	do_algo(t_board *data, t_solved *sol, int i, int j)
{
	if ((j < sol->y || sol->sum == 0) && data->turn < 20 && j > 0)
	{
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
	}
	else if ((j < sol->y && i < sol->x) && data->turn < 20)
	{
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
	}
	else if ((data->sum - 5 <= sol->sum && data->sum - 5 > 0 && i <= sol->x && j <= sol->y && data->turn < 30))
	{
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
	}
	else if ((data->sum < sol->sum || sol->sum == 0) && data->turn >= 20)
	{
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
	}
}

void	do_algo2(t_board *data, t_solved *sol, int i, int j)
{

}

void	do_sum(t_board *data, int i, int j)
{
	int	k;
	int	l;

	data->sum = 0;
	k = 0;
	while (data->piece[k] != NULL)
	{
		l = 0;
		while (data->piece[k][l] != '\0' && \
		i + k <= data->grid_x && j + l <= data->grid_y)
		{
			if (data->piece[k][l] == '*')
			{
				if ((data->solving_grid[i + k][j + l] != data->player_piece || data->solving_grid[i + k][j + l] != ft_tolower(data->player_piece)))
					data->sum += data->solving_grid[i + k][j + l] - '0';
			}
			l++;
		}
		k++;
	}
}

void	put_piece(t_board *data, t_solved *sol)
{
	int	i;
	int	j;

	i = -1;
	data->placable = 0;
	data->not_placable = 0;
	sol->sum = 0;
	while (data->solving_grid[++i] != NULL)
	{
		j = -1;
		while (data->solving_grid[i][++j] != '\0')
		{
			data->placable = is_placable(data, i, j);
			if (data->placable == 1)
			{
				data->not_placable = 1;
				do_sum(data, i, j);
				do_algo(data, sol, i, j);
			}
		}
	}
}

int	is_placable(t_board *data, int i, int j)
{
	int	k;
	int	l;
	int	x_count;

	k = -1;
	l = -1;
	x_count = 0;
	while (++k < data->piece_x)
	{
		if (i + data->piece_x > data->grid_x)
			return (0);
		l = -1;
		while (++l < data->piece_y)
		{
			if (j + data->piece_y > data->grid_y)
				return (0);
			if (i + k > data->grid_x || j + l > data->grid_y)
				return (0);
			if (data->solving_grid[i + k][j + l] == data->ennemy_piece || \
			data->solving_grid[i + k][j + l] == ft_tolower(data->ennemy_piece))
				return (0);
			if ((data->solving_grid[i + k][j + l] == data->player_piece || data->solving_grid[i + k][j + l] == ft_tolower(data->player_piece)) && data->piece[k][l] == '*')
				x_count++;
		}
	}
	if (x_count != 1)
		return (0);
	return (1);
}
