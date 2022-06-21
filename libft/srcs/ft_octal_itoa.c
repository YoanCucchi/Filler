/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:01:29 by ycucchi           #+#    #+#             */
/*   Updated: 2022/05/09 13:01:31 by ycucchi          ###   ########.fr       */
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
		n = n / 8;
		count++;
	}
	return (count);
}

static void	ft_fill_str(int count, int offset, unsigned long long n, char *str)
{
	while (count > offset)
	{
		str[count - 1] = n % 8 + '0';
		n = n / 8;
		count--;
	}
}

char	*ft_octal_itoa(unsigned long long n)
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
