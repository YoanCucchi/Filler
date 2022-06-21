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

static unsigned long long	ft_len(unsigned long long n)
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

static void	ft_fill_str(int count, int offset, unsigned long long n, char *str)
{
	while (count > offset)
	{
		str[count - 1] = n % 10 + '0';
		n = n / 10;
		count--;
	}
}

char	*ft_unsigned_long_itoa(unsigned long long n)
{
	char	*str;
	int		count;
	int		offset;

	offset = 0;
	count = ft_len(n);
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (str == NULL)
		return (NULL);
	ft_fill_str(count, offset, n, str);
	str[count] = '\0';
	return (str);
}
