#include ".././includes/filler.h"

static void	token_coord(t_board *p, char *line, int y)
{
	while (line[y])
	{
		if (line[y] == 'O' && p->player_piece == 'O')
		{
			p->x = p->line_helper;
			p->y = y;
		}
		else if (line[y] == 'X' && p->player_piece == 'X')
		{
			p->x = p->line_helper;
			p->y = y;
		}
		y++;
	}
}

static void	make_line(int ret, int fd, char *line, t_board *p)
{
	int	y;

	y = 0;
	while (line[0] != '0')
		ret = get_next_line(fd, &line);
	// ft_printf("line to check grid_helper = %s\n", line);
	p->grid_helper = ft_strnew(p->grid_y);
	while (*line && *line != '.' && *line != 'X' &&
		*line != 'x' && *line != 'O' && *line != 'o')
		line++;
	p->grid_helper = ft_strcpy(p->grid_helper, line);
	y++;
	// ft_printf("p->grid_helper = %s\n", p->grid_helper);
	// ft_printf("line to check grid_helper = %s\n", line);
	token_coord(p, line, y);
}

void	map_size(int ret, int fd, char *line, t_board *p)
{
	int	len;

	len = 0;
	ret = get_next_line(fd, &line);
	// ft_printf("line to check map size = %s\n", line);
	while(!ft_isdigit(*line))
		line++;
	p->grid_x = ft_atoi(line);
	len = ft_nbrlen(p->grid_x, 10) + 1;
	while (len--)
		line++;
	while(!ft_isdigit(*line))
		line++;
	p->grid_y = ft_atoi(line);
}

void	make_map(int ret, int fd, char *line, t_board *p)
{
	p->line_helper = 0;
	p->grid = (char **)malloc(sizeof(char*) * (p->grid_x + 1));
	while (ret > 0 && p->grid_x > p->line_helper)
	{
		make_line(ret, fd, line, p);
		p->grid[p->line_helper] = p->grid_helper;
		p->line_helper++;
	}
	p->grid[p->line_helper] = NULL;
	// token_coord(p);
}
