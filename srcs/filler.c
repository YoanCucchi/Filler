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

static int	player_piece(t_board *data, t_pos *pos2, t_solved *sol)
{
	int		ret;
	char	*line;
	int		player;

	player = 0;
	line = NULL;
	ret = get_next_line(0, &line);
	if (ret < 0)
		return (0);
	player = ft_atoi(line + 10);
	if (ft_strncmp(line, "$$$ exec p", 10) || !(player == 1 || player == 2))
		return (0);
	if (player == 1)
	{
		data->player_piece = 'O';
		data->ennemy_piece = 'X';
	}
	else if (player == 2)
	{
		data->player_piece = 'X';
		data->ennemy_piece = 'O';
	}
	if (ft_strncmp(line + 11, " : [./ycucchi.filler]", 21) || \
	line[ft_strlen(line) - 1] != ']')
		return (0);
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
		return (0);
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
	if (!make_grid(data) || !read_piece(data, pos2, sol) || !make_piece(data))
		return (0);
	solving_grid(data, pos2, pos1);
	put_piece(data, sol);
	if (!data->not_placable)
	{
		sol->x = 0;
		sol->y = 0;
	}
	ft_printf("%d ", sol->x);
	ft_printf("%d\n", sol->y);
	dprintf(2, "right after printing result\n");
	data->turn++;
	if ((sol->x == 0 && sol->y == 0 && !data->not_placable) || !skip_line())
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
	if (!data || !pos2 || !sol)
		return (clean_all(data, pos2, sol, "Struct malloc error\n"));
	init_struct(data, pos2, sol);
	if (!player_piece(data, pos2, sol))
		return (clean_all(data, pos2, sol, "Player error"));
	grid_size(data, pos2, sol);
	data->grid = (char **)malloc(sizeof(char *) * (data->grid_x + 1));
	data->solving_grid = (char **)malloc(sizeof(char *) * (data->grid_x + 1));
	if (!data->grid || !data->solving_grid)
		return (clean_all(data, pos2, sol, "Malloc error\n"));
	while (1)
	{
		data->all_good = filler_loop(data, pos2, sol);
		if (!data->all_good)
			break ;
	}
	dprintf(2, "just before end program (return clean all)\n");
	return (clean_all(data, pos2, sol, ""));
}
