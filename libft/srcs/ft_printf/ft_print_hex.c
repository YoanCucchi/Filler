/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:37:59 by ycucchi           #+#    #+#             */
/*   Updated: 2022/04/15 15:38:01 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_print_hex(t_parameter *p, va_list ap)
{
	unsigned int	n;

	n = va_arg(ap, int);
	p->len = ft_nbrlen(n, 16);
	ft_len_zero_handling_hex(p, n);
	if (n == 0 && !p->dot)
		p->return_value += ft_print_char('0');
	else if (n != 0)
		p->return_value += ft_recursive_hex(p, n, n);
	p->len = ft_nbrlen(n, 16);
	if (p->minus)
		minus_flag(p, n);
	if (p->width > p->precision && p->zero)
		while (p->highest_value-- > b_of_2(p->precision, p->len))
			p->return_value += ft_print_char('0');
	return (0);
}

int	ft_print_p(t_parameter *p, va_list ap)
{
	unsigned long	n;

	n = va_arg(ap, long);
	p->len = ft_nbrlen(n, 16);
	if (p->width > p->len + 2 && n != 0 && !p->precision && !p->minus)
		p->return_value += ft_print_char(' ');
	ft_len_zero_handling_p(p, n);
	if (n == 0 && !p->dot)
		p->return_value += ft_print_char('0');
	else if (n != 0)
		p->return_value += ft_recursive_hex(p, n, n);
	p->len = ft_nbrlen(n, 16);
	if (p->minus)
		minus_flag(p, n);
	if (p->width > p->precision && p->zero)
		while (p->highest_value-- > b_of_2(p->precision, p->len))
			p->return_value += ft_print_char('0');
	return (0);
}
