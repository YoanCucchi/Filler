/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:38:10 by ycucchi           #+#    #+#             */
/*   Updated: 2022/04/15 15:38:11 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_len_zero_handling_str(t_parameter *p, int lowest)
{
	p->highest_value = b_of_2(p->precision, p->width);
	if (p->precision > p->len)
		lowest = p->len;
	else
		lowest = p->precision;
	if (p->width >= p->precision && !p->minus)
	{
		while (p->highest_value-- > lowest)
		{
			if (!p->zero)
				p->return_value += ft_print_char(' ');
			else
				p->return_value += ft_print_char('0');
		}
	}
	else if (p->width > p->len && !p->minus)
	{
		while (p->width-- > lowest)
		{
			if (!p->zero)
				p->return_value += ft_print_char(' ');
			else
				p->return_value += ft_print_char('0');
		}
	}
}

int	ft_print_str(t_parameter *p, va_list ap)
{
	char	*string;
	int		lowest;

	lowest = 0;
	p->len = 0;
	string = va_arg(ap, char *);
	if (!string)
		string = "(null)";
	p->len = ft_strlen(string);
	if (!p->precision && !p->dot)
		p->precision = p->len;
	ft_len_zero_handling_str(p, lowest);
	p->return_value += ft_putnstr(string, p->precision);
	if (p->precision < p->len)
		while (p->width-- > p->precision && p->minus)
			p->return_value += ft_print_char(' ');
	else
		while (p->width-- > p->len && p->minus)
			p->return_value += ft_print_char(' ');
	return (0);
}

int	ft_print_c(t_parameter *p, va_list ap)
{
	char	c;
	int		lowest;

	lowest = 0;
	p->len = 0;
	c = va_arg(ap, int);
	if (c || c == 0)
		p->len = 1;
	if (!p->precision && !p->dot)
		p->precision = p->len;
	ft_len_zero_handling_str(p, lowest);
	p->return_value += ft_print_char(c);
	if (p->precision < p->len)
		while (p->width-- > p->precision && p->minus)
			p->return_value += ft_print_char(' ');
	else
		while (p->width-- > p->len && p->minus)
			p->return_value += ft_print_char(' ');
	return (0);
}

int	ft_print_percent(t_parameter *p)
{
	int		lowest;

	lowest = 0;
	p->len = 1;
	if (!p->precision && !p->dot)
		p->precision = p->len;
	ft_len_zero_handling_str(p, lowest);
	p->return_value += ft_print_char('%');
	if (p->precision < p->len)
		while (p->width-- > p->precision && p->minus)
			p->return_value += ft_print_char(' ');
	else
		while (p->width-- > p->len && p->minus)
			p->return_value += ft_print_char(' ');
	return (0);
}
