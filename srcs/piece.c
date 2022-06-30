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

void	read_piece(t_board *data)
{
	int		len;
	int		ret;
	char	*tmp;
	char	*line;

	line = NULL;
	len = 0;
	ret = get_next_line(0, &line);
	tmp = line;
	// ft_printf("line to check read piece = %s\n", line);
	while(!ft_isdigit(*line))
		line++;
	// ft_printf("line to afeterererr = %s\n", line);
	data->piece_x = ft_atoi(line);
	len = ft_nbrlen(data->piece_x, 10) + 1;
	while (len--)
		line++;
	while(!ft_isdigit(*line))
		line++;
	data->piece_y = ft_atoi(line);
	free(tmp);
}

static void	piece_helper(int ret, char *line, t_board *data)
{
	int	y;

	y = 0;
	data->piece_helper = ft_strnew(data->piece_y);
	while (*line && *line != '.' && *line != '*')
		line++;
	data->piece_helper = ft_strcpy(data->piece_helper, line);
	y++;
}

int	make_piece(t_board *data)
{
	int		ret;
	char	*line;

	line =  NULL;
	data->line_helper = 0;
	read_piece(data);
	data->piece = (char **)malloc(sizeof(char*) * (data->piece_x + 1));
	while (data->piece_x > data->line_helper)
	{
		ret = get_next_line(0, &line);
		piece_helper(ret, line, data);
		data->piece[data->line_helper] = data->piece_helper;
		data->line_helper++;
		free(line);
	}
	data->piece[data->line_helper] = NULL;
	return(1);
}
