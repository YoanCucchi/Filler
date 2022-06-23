#include ".././includes/filler.h"

void	read_piece(int ret, int fd, char *line, t_board *p)
{
	int	len;

	len = 0;
	ret = get_next_line(fd, &line);
	// ft_printf("line to check map size = %s\n", line);
	while(!ft_isdigit(*line))
		line++;
	// ft_printf("line to afeterererr = %s\n", line);
	p->piece_x = ft_atoi(line);
	len = ft_nbrlen(p->piece_x, 10) + 1;
	while (len--)
		line++;
	while(!ft_isdigit(*line))
		line++;
	p->piece_y = ft_atoi(line);
}

static void	piece_helper(int ret, int fd, char *line, t_board *p)
{
	int	y;

	y = 0;
	ret = get_next_line(fd, &line);
	// ft_printf("line to check piece_helper = %s\n", line);
	p->piece_helper = ft_strnew(p->piece_y);
	while (*line && *line != '.' && *line != '*')
		line++;
	p->piece_helper = ft_strcpy(p->piece_helper, line);
	y++;
	// ft_printf("p->grid_helper = %s\n", p->grid_helper);
	// ft_printf("line to check grid_helper = %s\n", line);
}

void	make_piece(int ret, int fd, char *line, t_board *p)
{
	p->line_helper = 0;
	p->piece = (char **)malloc(sizeof(char*) * (p->piece_x + 1));
	while (ret > 0 && p->piece_x > p->line_helper)
	{
		piece_helper(ret, fd, line, p);
		p->piece[p->line_helper] = p->piece_helper;
		p->line_helper++;
	}
	p->piece[p->line_helper] = NULL;
}