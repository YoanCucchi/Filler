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

static long long	ft_len(long long n)
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

static void	ft_fill_str(int count, int offset, long long n, char *str)
{
	while (count > offset)
	{
		str[count - 1] = n % 10 + '0';
		n = n / 10;
		count--;
	}
}

char	*ft_long_itoa(long long n)
{
	char	*str;
	int		count;
	int		offset;

	offset = 0;
	count = ft_len(n);
	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		offset = 1;
		n = -n;
	}
	ft_fill_str(count, offset, n, str);
	str[count] = '\0';
	return (str);
}
