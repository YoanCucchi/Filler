/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_helper_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:11:00 by ycucchi           #+#    #+#             */
/*   Updated: 2022/06/09 12:11:01 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	setting_float(t_parameter *p, t_float *f, long double n)
{
	if ((1 / n) < 0)
		f->is_negative = 1;
	if (f->is_negative && (p->precision < 6 || !p->precision))
		p->width--;
	if (!p->precision && !p->dot)
		p->precision = 6;
	if (!p->precision && p->dot)
		p->width++;
	if (p->precision > 18)
		p->precision = 18;
}

int	handling_sign(t_parameter *p, t_float *f)
{
	if (p->space && (!f->is_negative))
		p->return_value += ft_print_char(' ');
	if (f->is_negative && p->zero)
		p->return_value += ft_print_char('-');
	else if (p->plus && p->zero)
		p->return_value += ft_print_char('+');
	return (0);
}

int	ft_len_zero_handling_float(t_parameter *p, t_float *f)
{
	int	total;

	total = 0;
	if (f->is_negative)
		total = p->precision + ft_nbrlen(f->trunc, 10) + 1;
	else
		total = p->precision + p->plus + p->space + ft_nbrlen(f->trunc, 10) + 1;
	while (p->width-- > total)
	{
		if (!p->zero)
			p->return_value += ft_print_char(' ');
		else
			p->return_value += ft_print_char('0');
	}
	return (0);
}

int	handling_sign_after_zero(t_parameter *p, t_float *f)
{
	if (f->is_negative && !p->zero)
		p->return_value += ft_print_char('-');
	else if (p->plus && !p->zero)
		p->return_value += ft_print_char('+');
	return (0);
}

int	ft_minus_flag(t_parameter *p, t_float *f)
{
	while ((p->width-- - ft_nbrlen(f->trunc, 10) - 1 - p->precision) > 0)
	{
		if (!p->zero)
			p->return_value += ft_print_char(' ');
		else
			p->return_value += ft_print_char('0');
	}
	return (0);
}
