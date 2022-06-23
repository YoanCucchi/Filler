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

static void	print_map(t_board *p)
{
	int	i;

	i = -1;
	ft_printf("\n");
	ft_printf("------------------------------------------------------------\n");
	while (p->grid[++i])
		ft_printf("%s\n", p->grid[i]);
	ft_printf("------------------------------------------------------------\n");
	ft_printf("\n");
}

static void	struc_print(t_board *p)
{
	ft_printf("\n");
	ft_printf("------------------------------------------------------------\n");
	ft_printf("p->x = %d\n", p->x);
	ft_printf("p->y = %d\n", p->y);
	ft_printf("p->grid_x = %d\n", p->grid_x);
	ft_printf("p->grid_y = %d\n", p->grid_y);
	ft_printf("p->player_piece = %c\n", p->player_piece);
	ft_printf("------------------------------------------------------------\n");
	ft_printf("\n");
}

static void	player_piece(int ret, int fd, char *line, t_board *p)
{
	ret = get_next_line(fd, &line);
	// ft_printf("line to check player = %s\n", line);
	if (ret == 0)
		exit(0);
	if (ft_strstr(line, "$$$"))
	{
		if (ft_strstr(line, "p1"))
			p->player_piece = 'O';
		else if (ft_strstr(line, "p2"))
			p->player_piece = 'X';
	}
	line++;
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
	// ft_printf("line at the beginning= %s\n", line);
	if (ret == 0)
		exit(EXIT_SUCCESS);
	player_piece(ret, fd, line, p);
	map_size(ret, fd, line, p);
	make_map(ret, fd, line, p);
	print_map(p);
	struc_print(p);
	ft_putstr("12 14\n");
	// read_piece();
	// solver();
	// return_token();
	free(p);
	// system("leaks ycucchi.filler");
	return (0);
}
