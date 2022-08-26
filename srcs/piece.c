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

void read_piece(t_board *data, t_pos *pos2, t_solved *sol)
{
	int len;
	int ret;
	char *tmp;
	char *line;

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

int make_piece(t_board *data)
{
	int ret;
	char *line;

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

void do_sum(t_board *data, int i, int j)
{
	int k;
	int l;

	data->sum = 0;
	k = 0;
	while (data->piece[k] != NULL)
	{
		l = 0;
		while (data->piece[k][l] != '\0' &&
			   i + k <= data->grid_x && j + l <= data->grid_y)
		{
			if (data->piece[k][l] == '*')
			{
				if ((data->solving_grid[i + k][j + l] != data->player_piece ||
					 data->solving_grid[i + k][j + l] !=
						 ft_tolower(data->player_piece)))
					data->sum += data->solving_grid[i + k][j + l] - '0';
			}
			l++;
		}
		k++;
	}
}

void put_piece(t_board *data, t_solved *sol)
{
	int i;
	int j;

	i = -1;
	data->placable = 0;
	data->not_placable = 0;
	sol->sum = 0;
	sol->special_case = 0;
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
				// p 2 = X p1 = O
				dprintf(2, "piece placable at i = [%d] ", i);
				dprintf(2, "and j = [%d] ", j);
				dprintf(2, "sum = [%d]\n", data->sum);
				if (!data->im_bottom_right) // top left easy win no strat
				{
					dprintf(2, "\n===>CLOSEST<===\n");
					do_algo_closest(data, sol, i, j);
				}
				else if (data->im_bottom_right && data->grid_x < 20) // bottom right recherche haut et gauche une fois le milieu atteint ?
				{
					dprintf(2, "\n===>SMALL<===\n");
					do_algo_bot_right_small(data, sol, i, j);
				}
				else if (data->im_bottom_right && data->grid_x < 50) // bottom right recherche haut et gauche une fois le milieu atteint ?
				{
					dprintf(2, "\n===>MEDIUM<===\n");
					do_algo_bot_right_medium(data, sol, i, j);
				}
				else if (data->grid_x > 50) // bottom right recherche haut et gauche une fois le milieu atteint ?
				{
					dprintf(2, "\n===>HUGE<===\n");
					do_algo_bot_right_huge(data, sol, i, j);
				}
			}
		}
	}
	dprintf(2, "final sol->x = %d\n", sol->x);
	dprintf(2, "final sol->y = %d\n", sol->y);
	dprintf(2, "final turn = %d\n", data->turn);
	dprintf(2, "-----------------------------------------------------------\n");
}

int is_placable(t_board *data, int i, int j)
{
	int k;
	int l;
	int x_count;

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
			if (data->solving_grid[i + k][j + l] == data->ennemy_piece ||
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

int in_the_middle(t_board *data)
{
	int	i;
	int	j;
	int	k;
	int	l;

	k = data->grid_x / 2 + 1;
	l = data->grid_y / 2 + 1;
	i = 0;
	j = 0;
	while(i <= k)
	{
		j = 0;
		while(j <= l)
		{
			if (i == 0 && j == 0 && (data->grid[i][j] == data->player_piece || \
			data->grid[i][j] == ft_tolower(data->player_piece)))
			{
				dprintf(2, "in middle return = 0\n");
				data->closed = 1;
				return (0);
			}
			if(i < k && j < l && (data->grid[i][j] == data->player_piece || \
			data->grid[i][j] == ft_tolower(data->player_piece)))
			{
				dprintf(2, "data->grid[i][j] = %c ", data->grid[i][j]);
				dprintf(2, "at [%d] ", i);
				dprintf(2, "at [%d]\n", j);
				dprintf(2, "in middle return = 1");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	bot_right_clean(t_board *data)
{
	// return 0 if someth
	int	i;

	i = data->grid_x - 1;
	while(i >= 1)
	{
		dprintf(2, "i in bot right clean = %d\n", i);
		// si ma piece ok /// si ennemy check au dessus : si ma piece OK
		if (data->grid[i][data->grid_y - 1] == data->player_piece || \
		data->grid[i][data->grid_y - 1] == ft_tolower(data->player_piece))
		{
			dprintf(2, "fefeofjeofbot right clean = 1\n");
			data->bot_closed = 1;
			return (1); // si personne au dessus
		}
		if (data->grid[i][data->grid_y - 1] == data->ennemy_piece || \
		data->grid[i][data->grid_y - 1] == ft_tolower(data->ennemy_piece))
		{
			if (data->grid[i - 1][data->grid_y - 1] == data->player_piece || \
			data->grid[i - 1][data->grid_y - 1] == ft_tolower(data->player_piece))
			{
				dprintf(2, "bot right clean = 1\n");
				data->bot_closed = 1;
				return (1); // si personne au dessus
			}
		}
		i--;
	}
	return (0);
}
