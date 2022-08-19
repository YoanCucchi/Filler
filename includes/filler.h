/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:32:36 by ycucchi           #+#    #+#             */
/*   Updated: 2022/06/21 14:32:37 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

/*
** Headers
*/

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"

/*
** Structure
*/

typedef struct s_board
{
	int		turn;
	int		player_x;
	int		player_y;
	int		ennemy_x;
	int		ennemy_y;
	int		line_helper;
	int		grid_x;
	int		grid_y;
	int		piece_x;
	int		piece_y;
	int		player_piece;
	int		ennemy_piece;
	int		sum;
	int		placable;
	int		not_placable;
	int		dist;
	int		im_bottom_right;
	char	**grid;
	char	*grid_helper;
	char	**piece;
	char	*piece_helper;
	char	**solving_grid;
	char	*solving_grid_helper;
}			t_board;

typedef struct s_pos
{
	int	x;
	int	y;
}			t_pos;

typedef struct s_solved
{
	int	x;
	int	y;
	int	sum;
	int	special_case;
}			t_solved;

/*
** Prototypes
*/

/*
** filler.c
*/

void	skip_line(void);

/*
** grid.c
*/

void	grid_size(t_board *data, t_pos *pos2, t_solved *sol);
void	make_grid(t_board *data);

/*
** piece.c
*/

void	read_piece(t_board *data, t_pos *pos2, t_solved *sol);
int		make_piece(t_board *data);
void	piece_offset(t_board *data, t_solved *sol);
void	put_piece(t_board *data, t_solved *sol);
int		is_placable(t_board *data, int i, int j);

/*
** struct.c
*/

void	init_struct(t_board *data, t_pos *pos2, t_solved *sol);
void	free_struct(t_board *data);

/*
** solver.c
*/

long	ft_absolute_distance(t_pos pos1, t_pos *pos2);
void	solving_grid(t_board *data, t_pos *pos2, t_pos pos1);

/*
** solver_help.c
*/

int		check_left(t_pos *pos2, t_pos pos1, int n);
int		check_top(t_pos *pos2, t_pos pos1, int n);
int		check_right(t_pos *pos2, t_pos pos1, int n);
int		check_bottom(t_pos *pos2, t_pos pos1, int n);

void	clean_all(t_board *data, t_pos *pos2, t_solved *sol, char *str);
void	do_sum(t_board *data, int i, int j);
void	do_algo(t_board *data, t_solved *sol, int i, int j);
void	do_algo_closest(t_board *data, t_solved *sol, int i, int j);
void	do_algo_top_left(t_board *data, t_solved *sol, int i, int j);

int		anyone_up(t_board *data, int i, int j);
int		anyone_left(t_board *data, int i, int j);
int		anyone_right(t_board *data, int i, int j);
int		anyone_bottom(t_board *data, int i, int j);

void	do_algo_top_right(t_board *data, t_solved *sol, int i, int j);
void	do_algo_expand(t_board *data, t_solved *sol, int i, int j);
int		closest(t_pos pos1, t_pos *pos2, t_board *data, int i);

#endif
