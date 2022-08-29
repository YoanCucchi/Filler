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
** Structures
*/

typedef struct s_board
{
	int		k;
	int		l;
	int		x_count;
	int		sum;
	int		placable;
	int		not_placable;
	int		dist;
	int		closed;
	int		bot_closed;
	int		im_bottom_right;
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
	char	**grid;
	char	*grid_helper;
	char	**piece;
	char	*piece_helper;
	char	**solving_grid;
	char	*solving_help;
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
** algo_helper.c
*/

void	sol_store_spe(t_board *data, t_solved *sol, int i, int j);
void	sol_store(t_board *data, t_solved *sol, int i, int j);
void	reset_some_params(t_board *data, t_solved *sol);
int		in_the_middle(t_board *data);
int		bot_right_clean(t_board *data);

/*
** algo.c
*/

void	do_algo_closest(t_board *data, t_solved *sol, int i, int j);
void	do_algo_bot_right_small(t_board *data, t_solved *sol, int i, int j);
void	do_algo_bot_right_medium(t_board *data, t_solved *sol, int i, int j);
void	do_algo_bot_right_huge(t_board *data, t_solved *sol, int i, int j);

/*
** clean.c
*/

void	clean_all(t_board *data, t_pos *pos2, t_solved *sol, char *str);
void	free_solving_grid(t_board *data);
void	free_grid(t_board *data);
void	free_piece(t_board *data);

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
void	put_piece(t_board *data, t_solved *sol);
int		is_placable(t_board *data, int i, int j);
int		is_placable_helper(t_board *data, int i, int j);

/*
** solver.c
*/

long	ft_absolute_distance(t_pos pos1, t_pos *pos2);
int		closest(t_pos pos1, t_pos *pos2, t_board *data, int i);
int		check_diagonal(t_board *data, int i, int j, int n);
void	solving_grid(t_board *data, t_pos *pos2, t_pos pos1);
void	dist_exception_ox(t_board *data, int j);

/*
** solver_help.c
*/

int		check_left(t_pos *pos2, t_pos pos1, int n);
int		check_top(t_pos *pos2, t_pos pos1, int n);
int		check_right(t_pos *pos2, t_pos pos1, int n);
int		check_bottom(t_pos *pos2, t_pos pos1, int n);
void	do_sum(t_board *data, int i, int j);

/*
** struct.c
*/

void	init_struct(t_board *data, t_pos *pos2, t_solved *sol);
void	init_struct_utils(t_board *data);

#endif
