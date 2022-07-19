/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:33:57 by ycucchi           #+#    #+#             */
/*   Updated: 2022/01/25 17:30:41 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static int	read_all(char **array, const int fd)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*temp;

	ret = read(fd, buf, BUFF_SIZE);
	if (ret == -1)
		return (-1);
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (array[fd] != NULL)
		{
			temp = ft_strjoin(array[fd], buf);
			free(array[fd]);
			array[fd] = temp;
		}
		else
			array[fd] = ft_strdup(buf);
		if (ft_strchr(array[fd], '\n') != NULL)
			break ;
		ret = read(fd, buf, BUFF_SIZE);
	}
	return (ret);
}

static int	remove_new_line(char **line, char **array, const int fd)
{
	int		i;
	char	*temp;

	i = 0;
	while (array[fd][i] != '\0' && array[fd][i] != '\n')
		i++;
	if (array[fd][i] == '\n')
	{
		temp = ft_strdup(&array[fd][i + 1]);
		array[fd][i] = '\0';
		*line = ft_strdup(array[fd]);
		free(array[fd]);
		array[fd] = temp;
		if (array[fd][0] == '\0')
			ft_strdel(&array[fd]);
	}
	else
	{
		*line = ft_strdup(array[fd]);
		ft_strdel(&array[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*array[FD_SIZE + 1];

	if (fd == -1 || line == NULL || fd > FD_SIZE)
		return (-1);
	ret = read_all(array, fd);
	*line = NULL;
	if (ret < 0)
		return (-1);
	if (ret == 0 && array[fd] == NULL)
		return (0);
	return (remove_new_line(line, array, fd));
}
