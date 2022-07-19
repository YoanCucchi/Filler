/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 00:58:13 by ycucchi           #+#    #+#             */
/*   Updated: 2022/07/20 00:58:15 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long	ft_pow(int nbr, int power)
{
	long	result;

	if (power < 0)
		return (-1);
	result = 1;
	while (power--)
		result *= nbr;
	return (result);
}
