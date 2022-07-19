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

static void	print_piece(t_board *data)
{
	int	i;

	i = -1;
	ft_printf("------------------------------------------------------------\n");
	while (data->piece[++i])
		ft_printf("%s\n", data->piece[i]);
	ft_printf("------------------------------------------------------------\n");
}

static void	print_grid(t_board *data)
{
	int	i;

	i = -1;
	ft_printf("------------------------------------------------------------\n");
	while (data->grid[++i])
		ft_printf("%s\n", data->grid[i]);
	ft_printf("------------------------------------------------------------\n");
}

static void	dprint_grid(t_board *data)
{
	int	i;

	i = -1;

	dprintf(2, "\n------------------------------------------------------------\n");
	while (data->grid[++i])
		dprintf(2, "[%s]\n", data->grid[i]);
	dprintf(2, "------------------------------------------------------------\n");
}

static void	print_solving_grid(t_board *data)
{
	int	i;

	i = -1;
	ft_printf("------------------------------------------------------------\n");
	while (data->solving_grid[++i])
		ft_printf("%s\n", data->solving_grid[i]);
	ft_printf("------------------------------------------------------------\n");
}

static void	struc_print(t_board *data)
{
	ft_printf("------------------------------------------------------------\n");
	ft_printf("data->player_x = %d\n", data->player_x);
	ft_printf("data->player_y = %d\n", data->player_y);
	ft_printf("------------------------------------------------------------\n");
	ft_printf("data->ennemy_x = %d\n", data->ennemy_x);
	ft_printf("data->ennemy_y = %d\n", data->ennemy_y);
	ft_printf("------------------------------------------------------------\n");
	ft_printf("data->grid_x = %d\n", data->grid_x);
	ft_printf("data->grid_y = %d\n", data->grid_y);
	ft_printf("------------------------------------------------------------\n");
	ft_printf("data->piece_x = %d\n", data->piece_x);
	ft_printf("data->piece_y = %d\n", data->piece_y);
	ft_printf("------------------------------------------------------------\n");
	ft_printf("data->player_piece = %c\n", data->player_piece);
	ft_printf("data->ennemy_piece = %c\n", data->ennemy_piece);
	ft_printf("------------------------------------------------------------\n");
}

static void	player_piece(t_board *data)
{
	int		ret;
	char	*line;
	int		player;

	player = 0;
	line = NULL;
	ret = get_next_line(0, &line);
	if (ret < 1)
	{
		ft_printf("ret neg\n");
		exit(EXIT_FAILURE);
	}
	player = ft_atoi(line + 10);
	if (ft_strncmp(line, "$$$ exec p", 10 || !(player == 1 || player == 2)))
		ft_printf("error player\n");
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
		ft_printf("error player\n");
	ft_strdel(&line);
}

static void	clean_all(t_board *data, t_pos *pos2, t_solved *sol)
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
	// exit (0);
}

void	skip_line(t_board *data)
{
	int		ret;
	char	*line;

	line = NULL;
	ret = get_next_line(0, &line);
	if (ret < 1)
		exit(EXIT_FAILURE);
	ft_strdel(&line);
}

void	skip_line_print(void)
{
	int		ret;
	char	*line;

	line = NULL;
	ret = get_next_line(0, &line);
	if (ret < 1)
	{
		ft_printf("ret error\n");
		exit(EXIT_FAILURE);
	}
	ft_printf("lineskippedwas: %s\n", line);
	ft_strdel(&line);
}

static int	filler_loop(t_board *data, t_pos *pos2, t_solved *sol)
{
	// if problem return 0 and free what was assigned before and inside loop
	skip_line(data);
	make_grid(data);
	read_piece(data);
	make_piece(data); // malloc chaque tour
	solving_grid(data, pos2);
	// print_grid(data);
	// print_solving_grid(data);
	// print_piece(data);
	// struc_print(data);
	put_piece(data, sol);
	ft_printf("%d ", sol->x);
	ft_printf("%d\n", sol->y);
	if (data->piece)
		free_piece(data);
	data->turn++;
	skip_line(data); // skip line plateau x y
	return (1);
}

int main(void)
{
	t_board	*data;
	t_pos	*pos2;
	t_solved *sol;

	data = NULL;
	pos2 = NULL;
	sol = NULL;
	data = (t_board *)malloc(sizeof(t_board));
	pos2 = (t_pos *)malloc(sizeof(t_pos));
	sol = (t_solved *)malloc(sizeof(t_solved));
	if (!data || !pos2 || !sol)
		clean_all(data, pos2, sol);
	init_struct(data, pos2, sol);
	player_piece(data);
	grid_size(data);
	data->grid = (char **)malloc(sizeof(char*) * (data->grid_x + 1));
	data->solving_grid = (char **)malloc(sizeof(char*) * (data->grid_x + 1));
	if (!data->grid || !data->solving_grid)
		clean_all(data, pos2, sol);
// need to fix when no pos are possible it will returns the previous one (should be 0)
	while(1)
		filler_loop(data, pos2, sol);
	clean_all(data, pos2, sol);
	// system("leaks ycucchi.filler > leaks.out");
	return (0);
}
