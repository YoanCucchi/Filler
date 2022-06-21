/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:26:54 by ycucchi           #+#    #+#             */
/*   Updated: 2021/12/16 14:09:03 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_get_start(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == ',' || s[i] == '\n' || \
	s[i] == '\t'))
		i++;
	return (i);
}

static int	ft_get_end(const char *s)
{
	size_t	i;

	i = ft_strlen(s) - 1;
	while (i > 0 && (s[i] == ' ' || s[i] == ',' || \
	s[i] == '\n' || s[i] == '\t'))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (!s)
		return (NULL);
	start = ft_get_start(s);
	end = ft_get_end(s);
	if (start == ft_strlen(s))
		return ("\0");
	str = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!str)
		return (NULL);
	str = ft_strsub(s, start, end - start + 1);
	return (str);
}
