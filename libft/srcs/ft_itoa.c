/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:43:48 by ycucchi           #+#    #+#             */
/*   Updated: 2021/11/22 19:03:42 by ycucchi          ###   ########.fr       */
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
	return (dup);
}

char	*ft_itoa(long long n)
{
	int			i;
	char		arr[24];
	long long	k;

	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	i = 0;
	k = n;
	ft_bzero(arr, 24);
	if (n < 0)
		k = k * -1;
	arr[i] = k % 10 + '0';
	i++;
	while (k / 10 > 0)
	{
		k = k / 10;
		arr[i] = (k % 10 + '0');
		i++;
	}
	if (n < 0)
		arr[i] = '-';
	return (ft_strduprev(arr));
}
