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

#include ".././includes/filler.h"

static void	token_coord(t_board *data, char *line)
{
	int	y;

	y = 0;
	dprintf(2, "HERE\n");
	while (line[y])
	{
		if (line[y] == 'O')
		{
			if (data->player_piece == 'O')
			{
				data->player_x = data->line_helper;
				data->player_y = y;
			}
			else if (data->player_piece == 'X')
			{
				data->ennemy_x = data->line_helper;
				data->ennemy_y = y;
			}
		}
		else if (line[y] == 'X')
		{
			if (data->player_piece == 'X')
			{
				data->player_x = data->line_helper;
				data->player_y = y;
			}
			else if (data->player_piece == 'O')
			{
				data->ennemy_x = data->line_helper;
				data->ennemy_y = y;
			}
		}
		y++;
	}
}

void	grid_size(t_board *data)
{
	int		ret;
	char	*line;
	int		len;

	line = NULL;
	len = 0;
	ret = get_next_line(0, &line);
	if (ret < 1)
	{
		ft_printf("ret neg\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(line, "Plateau ", 8) || !ft_isdigit(*(line + 8)))
		ft_printf("grid error\n");
	data->grid_x = ft_atoi(line + 8);
	len = ft_nbrlen(data->grid_x, 10) + 1;
	if (!ft_isdigit(*(line + 8 + len)))
		ft_printf("grid error\n");
	data->grid_y = ft_atoi(line + 8 + len);
	if (line[ft_strlen(line) - 1] != ':')
		ft_printf("grid error\n");
	if (data->grid_x < 1 || data->grid_y < 1)
		ft_printf("grid error\n");
	ft_strdel(&line);
}

int	make_grid(t_board *data)
{
	int		ret;
	char	*line;

	line = NULL;
	data->line_helper = 0;
	data->grid = (char **)malloc(sizeof(char*) * (data->grid_x + 1));
	if (!data->grid)
	{
		ft_printf("datagrid error\n");
		return (0);
	}
	while (data->line_helper < data->grid_x)
	{
		ret = get_next_line(0, &line);
		data->grid_helper = ft_strnew(data->grid_y);
		data->grid_helper = ft_memcpy(data->grid_helper, (const char *)(line + 4), data->grid_y);
		if (data->turn == 0 && data->player_x == 0 && data->player_y == 0)
			token_coord(data, line);
		data->grid[data->line_helper] = data->grid_helper;
		data->line_helper++;
		ft_strdel(&line);
	}
	data->grid[data->line_helper] = NULL;
	return(1);
}
