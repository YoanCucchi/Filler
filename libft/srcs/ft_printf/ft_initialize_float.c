/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_float.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:27:12 by ycucchi           #+#    #+#             */
/*   Updated: 2022/05/30 17:27:16 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_float	*memalloc_float(t_float *f)
{
	f = (t_float *)malloc(sizeof(t_float));
	if (!f)
		exit(EXIT_FAILURE);
	ft_init_float(f);
	return (f);
}

void	ft_init_float(t_float *f)
{
	f->decimal = 0;
	f->trunc = 0;
	f->amount = 0;
	f->sign = 0;
	f->is_negative = 0;
	f->zero_to_add = 0;
}
