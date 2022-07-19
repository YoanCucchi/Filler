/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:52:31 by ycucchi           #+#    #+#             */
/*   Updated: 2022/07/20 00:52:33 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long	ft_sqrt(long nbr)
{
	long	result;

	if (nbr <= 0)
		return (0);
	result = 1;
	while (result * result < (long)nbr)
		result++;
	return (result);
}
