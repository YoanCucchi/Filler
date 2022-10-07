/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:47:38 by ycucchi           #+#    #+#             */
/*   Updated: 2022/06/30 17:47:41 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	token_coord(t_board *data, char *line, int y)
{
	while ((line + 4)[y++])
	{
		if ((line + 4)[y] == 'O' && data->player_piece == 'O')
		{
			data->player_x = data->line_helper;
			data->player_y = y;
		}
		else if ((line + 4)[y] == 'O' && data->player_piece == 'X')
		{
			data->ennemy_x = data->line_helper;
			data->ennemy_y = y;
		}
		else if ((line + 4)[y] == 'X' && data->player_piece == 'X')
		{
			data->player_x = data->line_helper;
			data->player_y = y;
		}
		else if ((line + 4)[y] == 'X' && data->player_piece == 'O')
		{
			data->ennemy_x = data->line_helper;
			data->ennemy_y = y;
		}
	}
}

int	grid_size(t_board *data)
{
	int		ret;
	char	*line;
	int		len;

	line = NULL;
	len = 0;
	ret = get_next_line(0, &line);
	if (ret < 0)
		return (ft_strdel(&line), 0);
	if (ft_strncmp(line, "Plateau ", 8) || !ft_isdigit(*(line + 8)))
		return (ft_strdel(&line), 0);
	data->grid_x = ft_atoi(line + 8);
	len = ft_nbrlen(data->grid_x, 10) + 1;
	if (!ft_isdigit(*(line + 8 + len)))
		return (ft_strdel(&line), 0);
	data->grid_y = ft_atoi(line + 8 + len);
	if (line[ft_strlen(line) - 1] != ':')
		return (ft_strdel(&line), 0);
	if (data->grid_x < 1 || data->grid_y < 1)
		return (ft_strdel(&line), 0);
	ft_strdel(&line);
	return (1);
}

int	make_grid(t_board *data)
{
	char	*line;
	int		y;

	line = NULL;
	data->line_helper = 0;
	while (data->line_helper < data->grid_x)
	{
		y = 0;
		if (get_next_line(0, &line) < 0)
			return (ft_strdel(&line), 0);
		data->grid_helper = ft_strnew(data->grid_y);
		data->grid_helper = \
		ft_memcpy(data->grid_helper, (const char *)(line + 4), data->grid_y);
		if (data->turn == 1 && (data->player_x == 0 || data->ennemy_x == 0) && \
		(data->player_y == 0 || data->ennemy_y == 0))
			token_coord(data, line, y);
		data->grid[data->line_helper] = data->grid_helper;
		data->line_helper++;
		ft_strdel(&line);
	}
	data->grid[data->line_helper] = NULL;
	if (data->ennemy_x < data->player_x && data->ennemy_y < data->player_y && \
	data->turn == 1)
		data->im_bottom_right = 1;
	return (1);
}
