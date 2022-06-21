/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:31:34 by ycucchi           #+#    #+#             */
/*   Updated: 2022/05/12 16:31:35 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_print_unsigned_nbr(t_parameter *p, va_list ap)
{
	unsigned int	n;
	char			*nbr;

	n = va_arg(ap, int);
	nbr = ft_itoa(n);
	p->len = ft_strlen(nbr);
	ft_len_zero_handling_nbr(p, n);
	if (!p->precision && n == 0 && p->dot)
	{
		if (p->minus)
			minus_flag(p, n);
		free(nbr);
		return (0);
	}
	else if (n == 0 && p->precision <= 0)
		p->return_value += ft_print_char('0');
	else
		p->return_value += write(1, nbr, p->len);
	p->len = ft_strlen(nbr);
	if (p->minus)
		minus_flag(p, n);
	free(nbr);
	return (0);
}

int	ft_print_ulong_nbr(t_parameter *p, va_list ap)
{
	char			*nbr;
	unsigned long	n;

	n = va_arg(ap, long);
	nbr = ft_unsigned_long_itoa(n);
	p->len = ft_strlen(nbr);
	ft_len_zero_handling_nbr(p, n);
	if (!p->precision && n == 0 && p->dot)
	{
		if (p->minus)
			minus_flag(p, n);
		free(nbr);
		return (0);
	}
	else if (n == 0 && p->precision <= 0)
		p->return_value += ft_print_char('0');
	else
		p->return_value += write(1, nbr, p->len);
	p->len = ft_strlen(nbr);
	if (p->minus)
		minus_flag(p, n);
	free(nbr);
	return (0);
}

int	ft_print_ushort_nbr(t_parameter *p, va_list ap)
{
	char			*nbr;
	unsigned short	n;

	n = va_arg(ap, int);
	nbr = ft_itoa(n);
	p->len = ft_strlen(nbr);
	ft_len_zero_handling_nbr(p, n);
	if (!p->precision && n == 0 && p->dot)
	{
		if (p->minus)
			minus_flag(p, n);
		free(nbr);
		return (0);
	}
	else if (n == 0 && p->precision <= 0)
		p->return_value += ft_print_char('0');
	else
		p->return_value += write(1, nbr, p->len);
	p->len = ft_strlen(nbr);
	if (p->minus)
		minus_flag(p, n);
	free(nbr);
	return (0);
}

int	ft_print_uchar_nbr(t_parameter *p, va_list ap)
{
	char			*nbr;
	unsigned char	n;

	n = va_arg(ap, int);
	nbr = ft_itoa(n);
	p->len = ft_strlen(nbr);
	if (!p->precision && n == 0 && p->dot)
	{
		ft_len_zero_handling_nbr(p, n);
		if (p->minus)
			minus_flag(p, n);
		free(nbr);
		return (0);
	}
	ft_len_zero_handling_nbr(p, n);
	p->return_value += write(1, nbr, p->len);
	p->len = ft_strlen(nbr);
	if (p->minus)
		minus_flag(p, n);
	free(nbr);
	return (0);
}
