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


static void	player_piece(int ret, int fd, char *line, t_board *p)
{
	ret = get_next_line(fd, &line);
	if (ret == 0)
		exit(0);
	if (ft_strstr(line, "$$$"))
	{
		if (ft_strstr(line, "p1"))
			p->player_piece = 'O';
		else if (ft_strstr(line, "p2"))
			p->player_piece = 'X';
	}
	ft_printf("my piece is = %c\n", p->player_piece);
}	

int main(void)
{
	int	fd;
	char *line;
	int	ret;
	t_board	*p;
	line = NULL;
	fd = 0;

	p = (t_board *)malloc(sizeof(t_board));
	if (!p)
		exit(EXIT_FAILURE);
	ret = get_next_line(fd, &line);
	if (ret == 0)
		exit(EXIT_SUCCESS);
	// ft_printf("line = %s\n", line);
	player_piece(ret, fd, line, p);
	while (ret)
		ft_putstr("12 14\n");
	// read_map();
	// read_piece();
	// solver();
	// return_token();
	free(p);
	return (0);
}
