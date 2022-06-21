/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:17:17 by ycucchi           #+#    #+#             */
/*   Updated: 2022/01/07 15:17:19 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_strduprev(char *s1)
{
	char	*dup;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	dup = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	len--;
	while (len >= 0)
	{
		dup[i] = s1[len];
		len--;
		i++;
	}
	dup[i] = '\0';
	free(s1);
	return (dup);
}

static int	ft_len(unsigned int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char	*arr;
	int		count;
	int		i;

	i = 0;
	count = ft_len(n);
	arr = (char *)malloc(sizeof(char) * (count + 1));
	if (arr == NULL)
		return (NULL);
	arr[i] = n % 10 + '0';
	i++;
	while (n / 10 > 0)
	{
		n = n / 10;
		arr[i] = (n % 10 + '0');
		i++;
	}
	return (ft_strduprev(arr));
}
