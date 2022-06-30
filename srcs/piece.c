#include ".././includes/filler.h"

void	read_piece(t_board *p)
{
	int		len;
	int		ret;
	char	*tmp;
	char	*line;

	line = NULL;
	len = 0;
	tmp = line;
	ret = get_next_line(0, &line);
	// ft_printf("line to check read piece = %s\n", line);
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
	free(tmp);
}

static void	piece_helper(int ret, char *line, t_board *p)
{
	int	y;

	y = 0;
	p->piece_helper = ft_strnew(p->piece_y);
	while (*line && *line != '.' && *line != '*')
		line++;
	p->piece_helper = ft_strcpy(p->piece_helper, line);
	y++;
}

int	make_piece(t_board *p)
{
	int		ret;
	char	*line;

	line =  NULL;
	p->line_helper = 0;
	read_piece(p);
	p->piece = (char **)malloc(sizeof(char*) * (p->piece_x + 1));
	while (p->piece_x > p->line_helper)
	{
		ret = get_next_line(0, &line);
		piece_helper(ret, line, p);
		p->piece[p->line_helper] = p->piece_helper;
		p->line_helper++;
		// free(line);
	}
	p->piece[p->line_helper] = NULL;
	return(1);
}