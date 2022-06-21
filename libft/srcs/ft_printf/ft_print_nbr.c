/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:38:06 by ycucchi           #+#    #+#             */
/*   Updated: 2022/04/15 15:38:06 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_print_nbr(t_parameter *p, va_list ap)
{
	int		n;
	char	*nbr;

	n = va_arg(ap, int);
	nbr = ft_itoa(n);
	nbr_setting(nbr, n, p);
	if (n == 0 && p->dot)
	{
		if (p->minus)
			minus_flag(p, n);
		free(nbr);
		return (0);
	}
	else if (nbr[0] == '-')
		p->return_value += write(1, nbr + 1, p->len);
	else
		p->return_value += write(1, nbr, p->len);
	p->len = ft_strlen(nbr);
	if (p->minus)
		minus_flag(p, n);
	free(nbr);
	return (0);
}

int	ft_print_short_nbr(t_parameter *p, va_list ap)
{
	char	*nbr;
	short	n;

	n = va_arg(ap, int);
	nbr = ft_itoa(n);
	nbr_setting(nbr, n, p);
	if (n == 0 && p->dot)
	{
		if (p->minus)
			minus_flag(p, n);
		free(nbr);
		return (0);
	}
	else if (nbr[0] == '-')
		p->return_value += write(1, nbr + 1, p->len);
	else
		p->return_value += write(1, nbr, p->len);
	p->len = ft_strlen(nbr);
	if (p->minus)
		minus_flag(p, n);
	free(nbr);
	return (0);
}

int	ft_print_long_nbr(t_parameter *p, va_list ap)
{
	char	*nbr;
	long	n;

	n = va_arg(ap, long);
	nbr = ft_long_itoa(n);
	nbr_setting(nbr, n, p);
	if (n == 0 && p->dot)
	{
		if (p->minus)
			minus_flag(p, n);
		free(nbr);
		return (0);
	}
	else if (nbr[0] == '-')
		p->return_value += write(1, nbr + 1, p->len);
	else
		p->return_value += write(1, nbr, p->len);
	p->len = ft_strlen(nbr);
	if (p->minus)
		minus_flag(p, n);
	free(nbr);
	return (0);
}

int	ft_print_long_long_nbr(t_parameter *p, va_list ap)
{
	char				*nbr;
	unsigned long long	n;

	n = va_arg(ap, long long);
	nbr = ft_long_itoa(n);
	nbr_setting(nbr, n, p);
	if (n == 0 && p->dot)
	{
		if (p->minus)
			minus_flag(p, n);
		free(nbr);
		return (0);
	}
	else if (nbr[0] == '-')
		p->return_value += write(1, nbr + 1, p->len);
	else
		p->return_value += write(1, nbr, p->len);
	p->len = ft_strlen(nbr);
	if (p->minus)
		minus_flag(p, n);
	free(nbr);
	return (0);
}

int	ft_print_char_nbr(t_parameter *p, va_list ap)
{
	char		*nbr;
	signed char	n;

	n = va_arg(ap, int);
	nbr = ft_long_itoa(n);
	nbr_setting(nbr, n, p);
	if (n == 0 && p->dot)
	{
		if (p->minus)
			minus_flag(p, n);
		free(nbr);
		return (0);
	}
	else if (nbr[0] == '-')
		p->return_value += write(1, nbr + 1, p->len);
	else
		p->return_value += write(1, nbr, p->len);
	p->len = ft_strlen(nbr);
	if (p->minus)
		minus_flag(p, n);
	free(nbr);
	return (0);
}
