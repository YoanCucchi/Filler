/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:32:22 by ycucchi           #+#    #+#             */
/*   Updated: 2022/06/21 14:32:25 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".././includes/filler.h"

static void	free_solving_grid(t_board *data)
{
	int	i;

	i = 0;
	while (i < data->grid_x)
	{
		ft_strdel(&data->solving_grid[i]);
		i++;
	}
	free(data->solving_grid);
	data->solving_grid = NULL;
}

static void	free_grid(t_board *data)
{
	int	i;

	i = 0;
	while (i < data->grid_x)
	{
		ft_strdel(&data->grid[i]);
		i++;
	}
	free(data->grid);
	data->grid = NULL;
}

static void	free_piece(t_board *data)
{
	int	i;

	i = 0;
	while (i < data->piece_x)
	{
		ft_strdel(&data->piece[i]);
		i++;
	}
	free(data->piece);
	data->piece = NULL;
}

static void	player_piece(t_board *data, t_pos *pos2, t_solved *sol)
{
	int		ret;
	char	*line;
	int		player;

	player = 0;
	line = NULL;
	ret = get_next_line(0, &line);
	player = ft_atoi(line + 10);
	if (ft_strncmp(line, "$$$ exec p", 10 || !(player == 1 || player == 2)))
		clean_all(data, pos2, sol, "Wrong player\n");
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
		clean_all(data, pos2, sol, "Wrong player\n");
	ft_strdel(&line);
}

void	clean_all(t_board *data, t_pos *pos2, t_solved *sol, char *str)
{
	if (!data)
		exit (0);
	if (data->piece)
		free_piece(data);
	if (data->grid)
		free_grid(data);
	if (data->solving_grid)
		free_solving_grid(data);
	if (pos2)
		free(pos2);
	if (sol)
		free(sol);
	if (data)
		free(data);
	if (ft_strcmp(str, ""))
	{
		ft_putendl_fd(str, 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void	skip_line(void)
{
	int		ret;
	char	*line;

	line = NULL;
	ret = get_next_line(0, &line);
	ft_strdel(&line);
}

static void	dprint_solving_grid(t_board *data)
{
	int	i;

	i = -1;
	dprintf(2, "------------------------------------------------------------\n");
	while (data->solving_grid[++i])
		dprintf(2, "%s\n", data->solving_grid[i]);
	dprintf(2, "------------------------------------------------------------\n");
}

static int	filler_loop(t_board *data, t_pos *pos2, t_solved *sol)
{
	t_pos	pos1;

	pos1.x = 0;
	pos1.y = 0;
	skip_line();
	make_grid(data);
	read_piece(data, pos2, sol);
	make_piece(data);
	solving_grid(data, pos2, pos1);
	dprint_solving_grid(data);
	put_piece(data, sol);
	if (!data->not_placable)
	{
		sol->x = 0;
		sol->y = 0;
	}
	ft_printf("%d ", sol->x);
	ft_printf("%d\n", sol->y);
	if (sol->x == 0 && sol->y == 0 && !data->not_placable)
		clean_all(data, pos2, sol, "");
	data->turn++;
	skip_line();
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
		clean_all(data, pos2, sol, "Struct malloc error\n");
	init_struct(data, pos2, sol);
	player_piece(data, pos2, sol);
	grid_size(data, pos2, sol);
	data->grid = (char **)malloc(sizeof(char *) * (data->grid_x + 1));
	data->solving_grid = (char **)malloc(sizeof(char *) * (data->grid_x + 1));
	if (!data->grid || !data->solving_grid)
		clean_all(data, pos2, sol, "Malloc error\n");
	while (1)
		filler_loop(data, pos2, sol);
	clean_all(data, pos2, sol, "");
	return (0);
}
