#include ".././includes/filler.h"

t_pos	check_left(t_board *data, t_pos pos2, int i, int j)
{
	if (i >= 0 && j > 0 && data->grid_x >= i && data->grid_y >= j \
	&& data->grid[i][j - 1] == 'O')
	{
		ft_printf("inside left\n");
		pos2.x = i;
		pos2.y = j - 1;
		return(pos2);
	}
}

t_pos	check_top(t_board *data, t_pos pos2, int i, int j)
{
	// check top
	if (i > 0 && j >= 0 && data->grid_x >= i && data->grid_y >= j && \
	data->grid[i - 1][1] == 'O')
	{
		ft_printf("inside top\n");
		pos2.x = i - 1;
		pos2.y = j;
		return(pos2);
	}
}
t_pos	check_right(t_board *data, t_pos pos2, int i, int j)
{
	// check right
	if (i >= 0 && j >= 0 && data->grid_x >= i && data->grid_y > j && \
	data->grid[i][j + 1] == 'O')
	{
		ft_printf("inside right\n");
		pos2.x = i;
		pos2.y = j + 1;
		return(pos2);
	}
}
t_pos	check_bottom(t_board *data, t_pos pos2, int i, int j)
{
	// check bottom
	if (i >= 0 && j >= 0 && data->grid_x > i && data->grid_y >= j && \
	data->grid[i + 1][j] == 'O')
	{
		ft_printf("inside bottom\n");
		pos2.x = i + 1;
		pos2.y = j;
		return(pos2);
	}
}