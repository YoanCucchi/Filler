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

static char	*make_line(int ret, int fd, char *line, t_board *p)
{
	int	y;

	y = 0;
	ft_printf("line to check grid_helper = %s\n", line);
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

void	map_size(int ret, int fd, char *line, t_board *p)
{
	char	*temp;
	int		len;

	len = 0;
	ret = get_next_line(fd, &line);
	temp = line;
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
	if (ret > 0)
		free(temp);
}

void	make_map(int ret, int fd, char *line, t_board *p)
{
	p->line_helper = 0;
	ret = get_next_line(fd, &line);
	free(line);
	p->grid = (char **)malloc(sizeof(char*) * (p->grid_x + 1));
	while (ret > 0 && p->grid_x > p->line_helper)
	{
		ret = get_next_line(fd, &line);
		p->grid[p->line_helper] = make_line(ret, fd, line, p);
		// ft_printf("test : %s\n", p->grid[p->line_helper]);
		p->line_helper++;
		free(line);
	}
	p->grid[p->line_helper] = NULL;
}
