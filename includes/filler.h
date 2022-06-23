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
	int		x;
	int		y;
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
** map.c
*/

void	map_size(int ret, int fd, char *line, t_board *p);
void	make_map(int ret, int fd, char *line, t_board *p);

/*
** piece.c
*/

void	read_piece(int ret, int fd, char *line, t_board *p);
void	make_piece(int ret, int fd, char *line, t_board *p);

#endif
