/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:00:45 by ycucchi           #+#    #+#             */
/*   Updated: 2022/05/03 12:00:46 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_parse_l(t_parameter *p, va_list ap)
{
	if (p->specifier == 'd' || p->specifier == 'i')
		p->return_value += ft_print_long_nbr(p, ap);
	else if (p->specifier == 'o')
		p->return_value += ft_print_long_o(p, ap);
	else if (p->specifier == 'u')
		p->return_value += ft_print_ulong_nbr(p, ap);
	else if (p->specifier == 'x' || p->specifier == 'X')
		p->return_value += ft_print_long_hex(p, ap);
	else if (p->specifier == 'f')
		p->return_value += ft_print_float(p, ap);
	return (0);
}

static int	ft_parse_ll(t_parameter *p, va_list ap)
{
	if (p->specifier == 'd' || p->specifier == 'i')
		p->return_value += ft_print_long_long_nbr(p, ap);
	else if (p->specifier == 'o')
		p->return_value += ft_print_llong_o(p, ap);
	else if (p->specifier == 'u')
		p->return_value += ft_print_ulong_nbr(p, ap);
	else if (p->specifier == 'x' || p->specifier == 'X')
		p->return_value += ft_print_long_long_hex(p, ap);
	return (0);
}

static int	ft_parse_h(t_parameter *p, va_list ap)
{
	if (p->specifier == 'd' || p->specifier == 'i')
		p->return_value += ft_print_short_nbr(p, ap);
	else if (p->specifier == 'o')
		p->return_value += ft_print_short_o(p, ap);
	else if (p->specifier == 'u')
		p->return_value += ft_print_ushort_nbr(p, ap);
	else if (p->specifier == 'x' || p->specifier == 'X')
		p->return_value += ft_print_short_hex(p, ap);
	return (0);
}

static int	ft_parse_hh(t_parameter *p, va_list ap)
{
	if (p->specifier == 'd' || p->specifier == 'i')
		p->return_value += ft_print_char_nbr(p, ap);
	else if (p->specifier == 'o')
		p->return_value += ft_print_char_octal(p, ap);
	else if (p->specifier == 'u')
		p->return_value += ft_print_uchar_nbr(p, ap);
	else if (p->specifier == 'x' || p->specifier == 'X')
		p->return_value += ft_print_char_hex(p, ap);
	return (0);
}

int	ft_length_flags(t_parameter *p, va_list ap)
{
	if (!ft_strcmp("l", p->length))
		p->return_value += ft_parse_l(p, ap);
	else if (!ft_strcmp("ll", p->length))
		p->return_value += ft_parse_ll(p, ap);
	else if (!ft_strcmp("h", p->length))
		p->return_value += ft_parse_h(p, ap);
	else if (!ft_strcmp("hh", p->length))
		p->return_value += ft_parse_hh(p, ap);
	else if (!ft_strcmp("L", p->length) && p->specifier == 'f')
		p->return_value += ft_print_l_float(p, ap);
	free(p->length);
	return (0);
}
