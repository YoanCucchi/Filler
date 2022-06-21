/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:13:14 by ycucchi           #+#    #+#             */
/*   Updated: 2022/05/09 10:13:16 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_print_octal(t_parameter *p, va_list ap)
{
	unsigned int	n;
	char			*nbr;

	n = va_arg(ap, int);
	nbr = ft_octal_itoa(n);
	if (n == 0 && p->dot && !p->sharp)
		p->len = 0;
	else
		p->len = ft_strlen(nbr);
	p->highest_value = b_of_3(p->precision, p->width, p->len);
	ft_len_zero_handling_octal(p, n);
	if (n == 0 && (!p->dot || p->sharp))
		p->return_value += ft_print_char('0');
	else if (n != 0)
		p->return_value += ft_recursive_octal(p, n, n);
	p->len = ft_strlen(nbr);
	if (p->sharp && n == 0 && p->dot)
		p->highest_value--;
	if (p->minus)
		minus_flag(p, n);
	free(nbr);
	return (0);
}

int	ft_print_long_o(t_parameter *p, va_list ap)
{
	unsigned long	n;
	char			*nbr;

	n = va_arg(ap, long);
	nbr = ft_octal_itoa(n);
	if (n == 0 && p->dot && !p->sharp)
		p->len = 0;
	else
		p->len = ft_strlen(nbr);
	p->highest_value = b_of_3(p->precision, p->width, p->len);
	ft_len_zero_handling_octal(p, n);
	if (n == 0 && (!p->dot || p->sharp))
		p->return_value += ft_print_char('0');
	else if (n != 0)
		p->return_value += ft_recursive_octal(p, n, n);
	p->len = ft_strlen(nbr);
	if (p->sharp && n == 0 && p->dot)
		p->highest_value--;
	if (p->minus)
		minus_flag(p, n);
	free(nbr);
	return (0);
}

int	ft_print_llong_o(t_parameter *p, va_list ap)
{
	unsigned long long	n;
	char				*nbr;

	n = va_arg(ap, long long);
	nbr = ft_octal_itoa(n);
	if (n == 0 && p->dot && !p->sharp)
		p->len = 0;
	else
		p->len = ft_strlen(nbr);
	p->highest_value = b_of_3(p->precision, p->width, p->len);
	ft_len_zero_handling_octal(p, n);
	if (n == 0 && (!p->dot || p->sharp))
		p->return_value += ft_print_char('0');
	else if (n != 0)
		p->return_value += ft_recursive_octal(p, n, n);
	p->len = ft_strlen(nbr);
	if (p->sharp && n == 0 && p->dot)
		p->highest_value--;
	if (p->minus)
		minus_flag(p, n);
	free(nbr);
	return (0);
}

int	ft_print_short_o(t_parameter *p, va_list ap)
{
	unsigned short	n;
	char			*nbr;

	n = va_arg(ap, int);
	nbr = ft_octal_itoa(n);
	if (n == 0 && p->dot && !p->sharp)
		p->len = 0;
	else
		p->len = ft_strlen(nbr);
	p->highest_value = b_of_3(p->precision, p->width, p->len);
	ft_len_zero_handling_octal(p, n);
	if (n == 0 && (!p->dot || p->sharp))
		p->return_value += ft_print_char('0');
	else if (n != 0)
		p->return_value += ft_recursive_octal(p, n, n);
	p->len = ft_strlen(nbr);
	if (p->sharp && n == 0 && p->dot)
		p->highest_value--;
	if (p->minus)
		minus_flag(p, n);
	free(nbr);
	return (0);
}

int	ft_print_char_octal(t_parameter *p, va_list ap)
{
	unsigned char	n;
	char			*nbr;

	n = va_arg(ap, int);
	nbr = ft_octal_itoa(n);
	if (n == 0 && p->dot && !p->sharp)
		p->len = 0;
	else
		p->len = ft_strlen(nbr);
	p->highest_value = b_of_3(p->precision, p->width, p->len);
	ft_len_zero_handling_octal(p, n);
	if (n == 0 && (!p->dot || p->sharp))
		p->return_value += ft_print_char('0');
	else if (n != 0)
		p->return_value += ft_recursive_octal(p, n, n);
	p->len = ft_strlen(nbr);
	if (p->sharp && n == 0 && p->dot)
		p->highest_value--;
	if (p->minus)
		minus_flag(p, n);
	free(nbr);
	return (0);
}
