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
	int	y;

	y = 0;
	// ft_printf("line to check grid_helper = %s\n", line);
	data->grid_helper = ft_strnew(data->grid_y);
	while (*line && *line != '.' && *line != 'X' &&
		*line != 'x' && *line != 'O' && *line != 'o')
		line++;
	data->grid_helper = ft_strcpy(data->grid_helper, line);
	y++;
	if (data->player_x == 0 && data->player_y == 0)
		token_coord(data, line);
	return (data->grid_helper);
}

void	grid_size(t_board *data)
{
	int		ret;
	char	*line;
	char	*temp;
	int		len;

	line = NULL;
	len = 0;
	ret = get_next_line(0, &line);
	temp = line;
	// ft_printf("line to check map size = %s\n", line);
	while(!ft_isdigit(*line))
		line++;
	data->grid_x = ft_atoi(line);
	len = ft_nbrlen(data->grid_x, 10) + 1;
	while (len--)
		line++;
	while(!ft_isdigit(*line))
		line++;
	data->grid_y = ft_atoi(line);
	// free(temp);
}

int	make_grid(t_board *data)
{
	int		ret;
	char	*line;

	line = NULL;
	data->line_helper = 0;
	skip_line();
	data->grid = (char **)malloc(sizeof(char*) * (data->grid_x + 1));
	if (!data->grid)
		return (0);
	while (data->grid_x > data->line_helper)
	{
		// ft_printf("data->grix_x = %d\n", data->grid_x);
		// ft_printf("line helper = %d\n", data->line_helper);
		ret = get_next_line(0, &line);
		data->grid[data->line_helper] = make_line(ret, line, data);
		// ft_printf("test : %s\n", data->grid[data->line_helper]);
		data->line_helper++;
		free(line);
	}
	data->grid[data->line_helper] = NULL;
	return(1);
}
