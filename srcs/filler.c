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

static void	free_grid(t_board *p)
{
	int	i;

	i = 0;
	while (i < p->grid_x)
	{
		ft_strdel(&p->grid[i]);
		i++;
	}
	free(p->grid);
}

static void	free_piece(t_board *p)
{
	int	i;

	i = 0;
	while (i < p->piece_x)
	{
		ft_strdel(&p->piece[i]);
		i++;
	}
	free(p->piece);
}

static void	print_piece(t_board *p)
{
	int	i;

	i = -1;
	ft_printf("------------------------------------------------------------\n");
	while (p->piece[++i])
		ft_printf("%s\n", p->piece[i]);
	ft_printf("------------------------------------------------------------\n");
}

static void	print_grid(t_board *p)
{
	int	i;

	i = -1;
	ft_printf("------------------------------------------------------------\n");
	while (p->grid[++i])
		ft_printf("%s\n", p->grid[i]);
	ft_printf("------------------------------------------------------------\n");
}

static void	print_solving_grid(t_board *p)
{
	int	i;

	i = -1;
	ft_printf("------------------------------------------------------------\n");
	while (p->solving_grid[++i])
		ft_printf("%s\n", p->solving_grid[i]);
	ft_printf("------------------------------------------------------------\n");
}

static void	struc_print(t_board *p)
{
	ft_printf("------------------------------------------------------------\n");
	ft_printf("p->player_x = %d\n", p->player_x);
	ft_printf("p->player_y = %d\n", p->player_y);
	ft_printf("------------------------------------------------------------\n");
	ft_printf("p->ennemy_x = %d\n", p->ennemy_x);
	ft_printf("p->ennemy_y = %d\n", p->ennemy_y);
	ft_printf("------------------------------------------------------------\n");
	ft_printf("p->grid_x = %d\n", p->grid_x);
	ft_printf("p->grid_y = %d\n", p->grid_y);
	ft_printf("------------------------------------------------------------\n");
	ft_printf("p->piece_x = %d\n", p->piece_x);
	ft_printf("p->piece_y = %d\n", p->piece_y);
	ft_printf("------------------------------------------------------------\n");
	ft_printf("p->player_piece = %c\n", p->player_piece);
	ft_printf("p->ennemy_piece = %c\n", p->ennemy_piece);
	ft_printf("------------------------------------------------------------\n");
}

static void	player_piece(t_board *data)
{
	int		ret;
	char	*line;

	line = NULL;
	ret = get_next_line(0, &line);
	if (ret < 1)
		exit(EXIT_FAILURE);
	if (ft_strstr(line, "$$$"))
	{
		if (ft_strstr(line, "p1"))
		{
			data->player_piece = 'O';
			data->ennemy_piece = 'X';
		}
		else if (ft_strstr(line, "p2"))
		{
			data->player_piece = 'X';
			data->ennemy_piece = 'O';
		}
	}
	ft_strdel(&line);
}

void	skip_line(void)
{
	int		ret;
	char	*line;

	line = NULL;
	ret = get_next_line(0, &line);
	ft_printf("line skipped was : %s\n", line);
	if (ret < 1)
		exit(EXIT_FAILURE);
	ft_strdel(&line);
}

int main(void)
{
	t_board	*data;
	t_pos	*pos2;
	t_solved *sol;
// problem with pos2 or sol = null
	data = NULL;
	data = (t_board *)malloc(sizeof(t_board));
	pos2 = NULL;
	pos2 = (t_pos *)malloc(sizeof(t_pos));
	sol = NULL;
	sol = (t_solved *)malloc(sizeof(t_solved));
	if (!data)
		return (0);
	init_struct(data);
	player_piece(data);
	grid_size(data);
	while (1)
	{
		make_grid(data);
		make_piece(data);
		solving_grid(data, pos2);
		piece_offset(data, sol);
		// print_grid(data);
		print_solving_grid(data);
		// ft_printf("12/15 = %d\n", data->solving_grid[12][15] - '0');
		print_piece(data);
		struc_print(data);
		skip_line();
		data->turn++;
	}
	free_grid(data);
	free_piece(data);
	free(data);
	free(pos2);
	// system("leaks ycucchi.filler >> leaks.out");
	return (0);
}
