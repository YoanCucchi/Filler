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

int	read_piece(t_board *data)
{
	int		len;
	int		ret;
	char	*tmp;
	char	*line;

	line = NULL;
	len = 0;
	ret = get_next_line(0, &line);
	if (ret < 0)
		return (ft_strdel(&line), 0);
	tmp = line;
	while (!ft_isdigit(*line))
		line++;
	data->piece_x = ft_atoi(line);
	len = ft_nbrlen(data->piece_x, 10) + 1;
	while (len-- || !ft_isdigit(*line))
		line++;
	data->piece_y = ft_atoi(line);
	if (data->piece_x == 0 || data->piece_y == 0)
		return (ft_strdel(&tmp), 0);
	ft_strdel(&tmp);
	data->piece = (char **)malloc(sizeof(char *) * (data->piece_x + 1));
	if (!data->piece)
		return (0);
	return (1);
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
		if (ret < 0)
			return (ft_strdel(&line), 0);
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

	i = -1;
	reset_some_params(data, sol);
	while (data->solving_grid[++i] != NULL)
	{
		j = -1;
		while (data->solving_grid[i][++j] != '\0')
		{
			data->placable = is_placable(data, i, j);
			if (data->placable == 1)
			{
				do_sum(data, i, j);
				if (!data->im_bottom_right)
					do_algo_closest(data, sol, i, j);
				else if (data->im_bottom_right && data->grid_x < 20)
					do_algo_bot_right_small(data, sol, i, j);
				else if (data->im_bottom_right && data->grid_x < 50)
					do_algo_bot_right_medium(data, sol, i, j);
				else if (data->grid_x > 50)
					do_algo_bot_right_medium(data, sol, i, j);
			}
		}
	}
}

int	is_placable(t_board *data, int i, int j)
{
	int	k;
	int	l;

	k = -1;
	data->x_count = 0;
	while (++k < data->piece_x)
	{
		data->k = k;
		if (i + data->piece_x > data->grid_x)
			return (0);
		l = -1;
		while (++l < data->piece_y)
		{
			data->l = l;
			if (!is_placable_helper(data, i, j))
				return (0);
		}
	}
	if (data->x_count != 1)
		return (0);
	return (1);
}

int	is_placable_helper(t_board *data, int i, int j)
{
	if ((data->solving_grid[i + data->k][j + data->l] == data->player_piece || \
	data->solving_grid[i + data->k][j + data->l] == \
	ft_tolower(data->player_piece)) && data->piece[data->k][data->l] == '*')
		data->x_count++;
	if (j + data->piece_y > data->grid_y)
		return (0);
	else if (i + data->k > data->grid_x || j + data->l > data->grid_y)
		return (0);
	else if (data->solving_grid[i + data->k][j + data->l] == \
	data->ennemy_piece || data->solving_grid[i + data->k][j + data->l] == \
	ft_tolower(data->ennemy_piece))
		return (0);
	else
		return (1);
}
