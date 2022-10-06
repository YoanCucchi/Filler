/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:32:22 by ycucchi           #+#    #+#             */
/*   Updated: 2022/09/06 11:40:24 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/filler.h"

static int	player_piece(t_board *data)
{
	int		ret;
	char	*line;

	line = NULL;
	ret = get_next_line(0, &line);
	if (ret < 0)
		return (ft_strdel(&line), 0);
	data->nb = ft_atoi(line + 10);
	if (ft_strncmp(line, "$$$ exec p", 10) || !(data->nb == 1 || data->nb == 2))
		return (ft_strdel(&line), 0);
	if (data->nb == 1)
	{
		data->player_piece = 'O';
		data->ennemy_piece = 'X';
	}
	else if (data->nb == 2)
	{
		data->player_piece = 'X';
		data->ennemy_piece = 'O';
	}
	if (ft_strncmp(line + 11, " : [./ycucchi.filler]", 21) || \
	line[ft_strlen(line) - 1] != ']')
		return (ft_strdel(&line), 0);
	ft_strdel(&line);
	return (1);
}

static int	skip_line(void)
{
	int		ret;
	char	*line;

	line = NULL;
	ret = get_next_line(0, &line);
	if (ret < 0)
		return (ft_strdel(&line), 0);
	ft_strdel(&line);
	return (1);
}

static int	filler_loop(t_board *data, t_pos *pos2, t_solved *sol)
{
	t_pos	pos1;

	pos1.x = 0;
	pos1.y = 0;
	if (!skip_line())
		return (0);
	if (!make_grid(data) || !read_piece(data) || !make_piece(data))
		return (0);
	if (!solving_grid(data, pos2, pos1))
		return (0);
	put_piece(data, sol);
	if (!data->not_placable)
	{
		sol->x = 0;
		sol->y = 0;
	}
	ft_printf("%d ", sol->x);
	ft_printf("%d\n", sol->y);
	data->turn++;
	if ((sol->x == 0 && sol->y == 0 && !data->not_placable) || !skip_line())
		return (0);
	free_piece(data);
	return (1);
}

static int	is_everything_ok(t_board *data, t_pos *pos2, t_solved *sol)
{
	if (!data || !pos2 || !sol)
		return (0);
	init_struct(data, pos2, sol);
	data->all_good = player_piece(data);
	if (!data->all_good)
		return (0);
	data->all_good = grid_size(data);
	if (!data->all_good)
		return (0);
	data->grid = (char **)malloc(sizeof(char *) * (data->grid_x + 1));
	data->solving_grid = (char **)malloc(sizeof(char *) * (data->grid_x + 1));
	if (!data->grid || !data->solving_grid)
		return (0);
	return (1);
}

int	main(void)
{
	t_board		*data;
	t_pos		*pos2;
	t_solved	*sol;

	data = NULL;
	pos2 = NULL;
	sol = NULL;
	data = (t_board *)malloc(sizeof(t_board));
	pos2 = (t_pos *)malloc(sizeof(t_pos));
	sol = (t_solved *)malloc(sizeof(t_solved));
	if (!is_everything_ok(data, pos2, sol))
		return (clean_all(data, pos2, sol));
	while (1)
	{
		data->all_good = filler_loop(data, pos2, sol);
		if (!data->all_good)
			break ;
	}
	clean_all(data, pos2, sol);
	system("leaks ycucchi.filler >> leaks.report");
	return (0);
}
