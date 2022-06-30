#include ".././includes/filler.h"

static void	token_coord(t_board *data, char *line)
{
	int	y;

	y = 0;
	while (line[y])
	{
		if (line[y] == 'O' && data->player_piece == 'O')
		{
			data->x = data->line_helper;
			data->y = y;
		}
		else if (line[y] == 'X' && data->player_piece == 'X')
		{
			data->x = data->line_helper;
			data->y = y;
		}
		y++;
	}
}

static char	*make_line(int ret, char *line, t_board *data)
{
	int	y;

	y = 0;
	// ft_printf("line to check grid_helper = %s\n", line);
	data->grid_helper = ft_strnew(data->grid_y);
	while (*line && *line != '.' && *line != 'X' &&
		*line != 'x' && *line != 'O' && *line != 'o')
		line++;
	data->grid_helper = ft_strcpy(data->grid_helper, line);
	y++;
	if (data->x == 0 && data->y == 0)
		token_coord(data, line);
	return (data->grid_helper);
}

void	grid_size(t_board *data)
{
	int		ret;
	char	*line;
	char	*temp;
	int		len;

	line = NULL;
	len = 0;
	ret = get_next_line(0, &line);
	temp = line;
	// ft_printf("line to check map size = %s\n", line);
	while(!ft_isdigit(*line))
		line++;
	data->grid_x = ft_atoi(line);
	len = ft_nbrlen(data->grid_x, 10) + 1;
	while (len--)
		line++;
	while(!ft_isdigit(*line))
		line++;
	data->grid_y = ft_atoi(line);
	free(temp);
}

int	make_grid(t_board *data)
{
	int		ret;
	char	*line;

	line = NULL;
	data->line_helper = 0;
	skip_line();
	data->grid = (char **)malloc(sizeof(char*) * (data->grid_x + 1));
	while (data->grid_x > data->line_helper)
	{
		// ft_printf("data->grix_x = %d\n", data->grid_x);
		// ft_printf("line helper = %d\n", data->line_helper);
		ret = get_next_line(0, &line);
		data->grid[data->line_helper] = make_line(ret, line, data);
		// ft_printf("test : %s\n", data->grid[data->line_helper]);
		data->line_helper++;
		free(line);
	}
	data->grid[data->line_helper] = NULL;
	return(1);
}
