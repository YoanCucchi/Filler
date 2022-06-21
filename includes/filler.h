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
	int		grid_x;
	int		grid_y;
	int		player_piece;
	char	**grid;
}			t_board;

/*
** Prototypes
*/

#endif
