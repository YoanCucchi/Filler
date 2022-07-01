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
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

/*
** Structure
*/

typedef struct s_board
{
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
	char	**grid;
	char	*grid_helper;
	char	**piece;
	char	*piece_helper;
}			t_board;

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

void	grid_size(t_board *data);
int		make_grid(t_board *data);

/*
** piece.c
*/

void	read_piece(t_board *data);
int		make_piece(t_board *data);

/*
** struct.c
*/

void	init_struct(t_board *p);
void	free_struct(t_board *p);

#endif
