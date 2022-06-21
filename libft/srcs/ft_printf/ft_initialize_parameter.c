/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_parameter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:13:48 by ycucchi           #+#    #+#             */
/*   Updated: 2022/04/15 15:13:52 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_parameter	*memalloc_struct(t_parameter *p)
{
	p = (t_parameter *)malloc(sizeof(t_parameter));
	if (!p)
		exit(EXIT_FAILURE);
	ft_init_params(p);
	return (p);
}

void	ft_init_params(t_parameter *p)
{
	p->sharp = 0;
	p->zero = 0;
	p->minus = 0;
	p->plus = 0;
	p->space = 0;
	p->dot = 0;
	p->width = 0;
	p->precision = 0;
	p->specifier = 0;
	p->return_value = 0;
	p->highest_value = 0;
	p->checked = 0;
	p->wildcard_check = 0;
	p->minus_check = 0;
	p->zeros_print = 0;
	p->len = 0;
	p->format = NULL;
	p->length = NULL;
}

void	ft_reset_params(t_parameter *p)
{
	p->sharp = 0;
	p->zero = 0;
	p->minus = 0;
	p->plus = 0;
	p->dot = 0;
	p->space = 0;
	p->width = 0;
	p->precision = 0;
	p->specifier = 0;
	p->highest_value = 0;
	p->checked = 0;
	p->wildcard_check = 0;
	p->minus_check = 0;
	p->zeros_print = 0;
	p->len = 0;
	p->format = NULL;
	p->length = NULL;
}
