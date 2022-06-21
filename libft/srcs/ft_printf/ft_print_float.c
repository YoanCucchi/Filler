/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:33:48 by ycucchi           #+#    #+#             */
/*   Updated: 2022/05/25 13:33:49 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_print_float(t_parameter *p, va_list ap)
{
	double	n;
	char	*nbr;
	t_float	*f;

	f = NULL;
	nbr = NULL;
	f = memalloc_float(f);
	n = va_arg(ap, double);
	setting_float(p, f, n);
	split_float(p, f, n);
	nbr = float_maker(p, f, nbr);
	handling_sign(p, f);
	if (!p->minus)
		ft_len_zero_handling_float(p, f);
	handling_sign_after_zero(p, f);
	p->return_value += ft_putnstr(nbr, (p->precision + \
	ft_nbrlen(f->trunc, 10) + 1));
	if (!f->decimal)
		while (p->precision-- > 1)
			p->return_value += ft_print_char('0');
	if (p->minus)
		ft_minus_flag(p, f);
	free(nbr);
	free(f);
	return (0);
}

int	ft_print_l_float(t_parameter *p, va_list ap)
{
	long double	n;
	char		*nbr;
	t_float		*f;

	f = NULL;
	nbr = NULL;
	f = memalloc_float(f);
	n = va_arg(ap, long double);
	setting_float(p, f, n);
	split_float(p, f, n);
	nbr = float_maker(p, f, nbr);
	handling_sign(p, f);
	if (!p->minus)
		ft_len_zero_handling_float(p, f);
	handling_sign_after_zero(p, f);
	p->return_value += ft_putnstr(nbr, (p->precision + \
	ft_nbrlen(f->trunc, 10) + 1));
	if (!f->decimal)
		while (p->precision-- > 1)
			p->return_value += ft_print_char('0');
	if (p->minus)
		ft_minus_flag(p, f);
	free(nbr);
	free(f);
	return (0);
}
