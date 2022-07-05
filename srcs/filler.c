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

	data = NULL;
	data = (t_board *)malloc(sizeof(t_board));
	pos2 = NULL;
	pos2 = (t_pos *)malloc(sizeof(t_pos));
	if (!data)
		return (0);
	init_struct(data);
	player_piece(data);
	grid_size(data);
	while (1)
	{
		make_grid(data);
		make_piece(data);
		ft_printf("%d ", data->player_x);
		ft_printf("%d\n", data->player_y);
		solving_grid(data, pos2);
		// return_token();
		// print_grid(data);
		print_solving_grid(data);
		ft_printf("12/15 = %d\n", data->solving_grid[12][15] - '0');
		print_piece(data);
		struc_print(data);
		skip_line();
	}
	free_grid(data);
	free_piece(data);
	free(data);
	free(pos2);
	// system("leaks ycucchi.filler >> leaks.out");
	return (0);
}
