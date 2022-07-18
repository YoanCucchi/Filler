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

static char	*make_line(int ret, char *line, t_board *data)
{
	// dprintf(2, "line to check grid_helper = %s\n", line);
	// ft_printf("line to check grid_helper = %s\n", line);
	data->grid_helper = ft_strnew(data->grid_y);
	// while (*line && *line != '.' && *line != 'X' &&
	// 	*line != 'x' && *line != 'O' && *line != 'o')
	// 	line++;
	data->grid_helper = ft_memcpy(data->grid_helper, (const char *)(line + 4), data->grid_y);
	dprintf(2, "data grid_helper = [%s]\n", data->grid_helper);
	if (data->player_x == 0 && data->player_y == 0)
		token_coord(data, line);
	return (data->grid_helper);
}

void	grid_size(t_board *data)
{
	int		ret;
	char	*line;
	int		len;

	line = NULL;
	len = 0;
	ret = get_next_line(0, &line);
	fprintf(data->read_log, "%s\n", line);
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
		// ft_printf("data->grix_x = %d\n", data->grid_x);
		// ft_printf("line helper = %d\n", data->line_helper);
		dprintf(2, "1");
		ret = get_next_line(0, &line); // it stops there apparently
		// usleep(100000);
		fprintf(data->read_log, "%s\n", line);
		data->grid[data->line_helper] = make_line(ret, line, data);
		// usleep(100000);
		// dprintf(2, "right after new line added to the grid = %d", data->line_helper);
		// ft_printf("test : %s\n", data->grid[data->line_helper]);
		data->line_helper++;
		ft_strdel(&line);
	}
	data->grid[data->line_helper] = NULL;
	return(1);
}
