#include ".././includes/filler.h"

static void	token_coord(t_board *p, char *line)
{
	int	y;

	y = 0;
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

static char	*make_line(int ret, char *line, t_board *p)
{
	int	y;

	y = 0;
	// ft_printf("line to check grid_helper = %s\n", line);
	p->grid_helper = ft_strnew(p->grid_y);
	while (*line && *line != '.' && *line != 'X' &&
		*line != 'x' && *line != 'O' && *line != 'o')
		line++;
	p->grid_helper = ft_strcpy(p->grid_helper, line);
	y++;
	if (p->x == 0 && p->y == 0)
		token_coord(p, line);
	return (p->grid_helper);
}

void	map_size(t_board *p)
{
	int		ret;
	int		len;
	char	*tmp;
	char	*line;

	line = NULL;
	len = 0;
	tmp = line;
	ret = get_next_line(0, &line);
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
	free(tmp);
}

int	make_map(t_board *p)
{
	int		ret;
	char	*line;

	line = NULL;
	p->line_helper = 0;
	skip_line();
	p->grid = (char **)malloc(sizeof(char*) * (p->grid_x + 1));
	while (p->grid_x > p->line_helper)
	{
		// ft_printf("p->grix_x = %d\n", p->grid_x);
		// ft_printf("line helper = %d\n", p->line_helper);
		ret = get_next_line(0, &line);
		p->grid[p->line_helper] = make_line(ret, line, p);
		// ft_printf("test : %s\n", p->grid[p->line_helper]);
		p->line_helper++;
		free(line);
	}
	p->grid[p->line_helper] = NULL;
	return(1);
}
