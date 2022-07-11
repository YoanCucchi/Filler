#include ".././includes/filler.h"

int	check_left(t_pos *pos2, t_pos pos1, int n)
{
	int	i;
	int	j;

	i = pos1.x;
	j = pos1.y;
	// ft_printf("inside left\n");
	pos2->x = i;
	pos2->y = j - n;
	return(ft_absolute_distance(pos1, pos2));
}

int	check_top(t_pos *pos2, t_pos pos1, int n)
{
	int	i;
	int	j;

	i = pos1.x;
	j = pos1.y;
	// ft_printf("inside top\n");
	pos2->x = i - n;
	pos2->y = j;
	return(ft_absolute_distance(pos1, pos2));
}
int	check_right(t_pos *pos2, t_pos pos1, int n)
{
	int	i;
	int	j;

	i = pos1.x;
	j = pos1.y;
	// ft_printf("inside right\n");
	pos2->x = i;
	pos2->y = j + n;
	return(ft_absolute_distance(pos1, pos2));
}

int	check_bottom(t_pos *pos2, t_pos pos1, int n)
{
	int	i;
	int	j;

	i = pos1.x;
	j = pos1.y;
	// ft_printf("inside bottom\n");
	pos2->x = i + n;
	pos2->y = j;
	return(ft_absolute_distance(pos1, pos2));
}
