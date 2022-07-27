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
	if ((j < sol->y || sol->sum == 0) && data->turn < 10 && j > 0)
	{
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
	}
	else if ((j < sol->y && i < sol->x) && data->turn < 10)
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
	else if ((data->sum < sol->sum || sol->sum == 0) && data->turn >= 10)
	{
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
	}
}

void	do_algo2(t_board *data, t_solved *sol, int i, int j)
{
	// check si ya un truc a gauche, si rien, go up
	// check si ya un truc au dessus si oui go left
	// check si ya un truc au dessus et a gauche go bottom
	// check si ya un truc au dessus et a droit go 
	// je fais quoi si sol sum = data sum
	// if (data->turn < 15 && (j < sol->y || sol->sum == 0))
	// {
	// 	dprintf(2, "turn = %d\n", data->turn);
	// 	dprintf(2, "10 premier tours ==> go gauche\n");
	// 	dprintf(2, "sol sum = %d\n", sol->sum);
	// 	// y'a rien a gauche mais y'a un truc au dessus on go le plus a gauche
	// 	sol->x = i;
	// 	sol->y = j;
	// 	sol->sum = data->sum;
	// 	dprintf(2, "i = %d\n", i);
	// 	dprintf(2, "j = %d\n", j);
	// 	dprintf(2, "sol->x = %d\n", sol->x);
	// 	dprintf(2, "sol->y = %d\n", sol->y);
	// }
	// else if (!anyone_left(data, sol, i, j) && anyone_up(data, sol, i, j) \
	//  && data->turn < 20 && j < sol->y && (data->sum < sol->sum + 10 || sol->sum == 0))
	// {
	// 	dprintf(2, "!gauche mais dessus ==> go gauche\n");
	// 	// y'a rien a gauche mais y'a un truc au dessus on go le plus a gauche
	// 	sol->x = i;
	// 	sol->y = j;
	// 	sol->sum = data->sum;
	// }
	// else if (anyone_left(data, sol, i, j) && !anyone_up(data, sol, i, j) && \
	// data->turn < 25 && i < sol->y && data->sum < sol->sum + 1)
	// {
	// 	dprintf(2, "y'a gauche mais !dessus ==> go up\n");
	// 	// y'a un truc a gauche mais y'a rien au dessus on go le plus haut
	// 	sol->x = i;
	// 	sol->y = j;
	// 	sol->sum = data->sum;
	// }
	if ((data->sum < sol->sum || sol->sum == 0)) // closest possible
	{
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
	}
	// dprintf(2, "i = %d\n", i);
	// dprintf(2, "j = %d\n", j);
	// dprintf(2, "sol->x = %d\n", sol->x);
	// dprintf(2, "sol->y = %d\n", sol->y);
}

void	do_algo3(t_board *data, t_solved *sol, int i, int j)
{
	// il faudrait voir comme faire pour trouver le plus proche
	// mais aussi le plus haut gauche possible
	// j < sol->y ==> plus a gauche
	// i < sol->x ==> plus en haut
	// plus en haut a gauche = ???
	// if (j < sol->y && i < sol->x)
	if ((j < sol->y || sol->sum == 0) && data->turn < 15 && !anyone_up(data, sol, i, j))
	{
		dprintf(2, "turn = %d\n", data->turn);
		dprintf(2, "10 premier tours ==> go gauche\n");
		dprintf(2, "sol sum = %d\n", sol->sum);
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
		dprintf(2, "i = %d\n", i);
		dprintf(2, "j = %d\n", j);
		dprintf(2, "sol->x = %d\n", sol->x);
		dprintf(2, "sol->y = %d\n", sol->y);
	}
	else if (((j < sol->y && i < sol->x) || sol->sum == 0) && data->turn < 25)
	{
		dprintf(2, "turn = %d\n", data->turn);
		dprintf(2, "25 premier tours ==> go haut gauche \n");
		dprintf(2, "sol sum = %d\n", sol->sum);
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
		dprintf(2, "i = %d\n", i);
		dprintf(2, "j = %d\n", j);
		dprintf(2, "sol->x = %d\n", sol->x);
		dprintf(2, "sol->y = %d\n", sol->y);
	}
		else if ((data->sum < sol->sum || sol->sum == 0) && data->turn >= 25)
	{
		dprintf(2, "turn = %d\n", data->turn);
		dprintf(2, "le reste du temps  ==> au plus proche\n");
		dprintf(2, "sol sum = %d\n", sol->sum);
		sol->x = i;
		sol->y = j;
		sol->sum = data->sum;
		dprintf(2, "i = %d\n", i);
		dprintf(2, "j = %d\n", j);
		dprintf(2, "sol->x = %d\n", sol->x);
		dprintf(2, "sol->y = %d\n", sol->y);
	}
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
				if (data->grid_x > 40 || im_top_left(data))
					do_algo2(data, sol, i, j);
				else
					do_algo3(data, sol, i, j);
			}
		}
	}
	dprintf(2, "final sol->x = %d\n", sol->x);
	dprintf(2, "final sol->y = %d\n", sol->y);
	dprintf(2, "final turn = %d\n", data->turn);
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

int	im_top_left(t_board *data)
{
	if (data->turn > 1)
		return (1);
	if (data->player_x > data->ennemy_x)
		return (1);
	else
		return (0);
}
