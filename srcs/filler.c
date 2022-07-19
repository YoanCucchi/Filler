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
	fprintf(data->read_log, "%s\n", line);
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

void	skip_line(t_board *data)
{
	int		ret;
	char	*line;

	line = NULL;
	ret = get_next_line(0, &line);
	fprintf(data->read_log, "%s", line);
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

int main(void)
{
	t_board	*data;
	t_pos	*pos2;
	t_solved *sol;

	data = NULL;
	data = (t_board *)malloc(sizeof(t_board));
	pos2 = NULL;
	pos2 = (t_pos *)malloc(sizeof(t_pos));
	sol = NULL;
	sol = (t_solved *)malloc(sizeof(t_solved));
	if (!data || !pos2 || !sol)
	{
		ft_printf("malloc error\n");
		return (0);
	}
	// ft_bzero(data, sizeof (t_board));
	// ft_bzero(pos2, sizeof (t_pos));
	// ft_bzero(sol, sizeof (t_solved));
	// init_struct(data);
	data->read_log = fopen("log.txt", "a+");
	player_piece(data);
	grid_size(data);

// need to fix when no pos are possible it will returns the previous one (should be 0)
// need to take care of memory pb. also heatmap should be malloced only once
// 

	while (1)
	{
		skip_line(data);
	//	bzero grid every turn
		// usleep(100000);
		make_grid(data); // BUG !!!!!
		// dprint_grid(data);
		// ft_printf("got ya\n");
		// usleep(100000);
		read_piece(data);
		make_piece(data);
		solving_grid(data, pos2);
		// print_grid(data);
		// print_solving_grid(data);
		// print_piece(data);
		// struc_print(data);
		put_piece(data, sol);
		ft_putnbr(sol->x);
		ft_putchar(' ');
		ft_putnbr(sol->y);
		ft_putchar('\n');
		data->turn++;
		skip_line(data); // skip line plateau x y
	}
	free_grid(data);
	free_piece(data);
	free_solving_grid(data);	
	free(pos2);
	free(data);
	// system("leaks ycucchi.filler");
	return (0);
}
