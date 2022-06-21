/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:13:51 by ycucchi           #+#    #+#             */
/*   Updated: 2022/05/09 10:13:54 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	printing(const char *str, char *first, va_list ap, t_parameter *p)
{
	while (*str)
	{
		if (*str == '%')
		{
			ft_reset_params(p);
			first = (char *)str;
			if (*(++str))
				p->return_value += ft_parse((char *)str, ap, p);
			while (*str && !ft_strchr(SPECIFIERS, *str))
				str++;
			if (!(*str))
				str = first;
		}
		else
			p->return_value += ft_print_char(*str);
		if (*str)
			str++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	t_parameter	*p;
	char		*first;

	p = NULL;
	va_start(ap, str);
	p = memalloc_struct(p);
	first = NULL;
	printing(str, first, ap, p);
	va_end(ap);
	free(p);
	return (p->return_value);
}

int	conversion_type(t_parameter *p, va_list ap)
{
	if (p->length && (ft_strchr(LENGTH_DISPATCH, p->specifier)))
		p->return_value += ft_length_flags(p, ap);
	else if (p->length && (ft_strchr("f", p->specifier)))
		p->return_value += ft_length_flags(p, ap);
	else if (p->specifier == 'c')
		p->return_value += ft_print_c(p, ap);
	else if (p->specifier == 's')
		p->return_value += ft_print_str(p, ap);
	else if (p->specifier == 'x' || p->specifier == 'X')
		p->return_value += ft_print_hex(p, ap);
	else if (p->specifier == 'p')
		p->return_value += ft_print_p(p, ap);
	else if (p->specifier == 'd' || p->specifier == 'i')
		p->return_value += ft_print_nbr(p, ap);
	else if (p->specifier == 'u')
		p->return_value += ft_print_unsigned_nbr(p, ap);
	else if (p->specifier == 'o')
		p->return_value += ft_print_octal(p, ap);
	else if (p->specifier == 'f')
		p->return_value += ft_print_float(p, ap);
	else if (p->specifier == '%')
		p->return_value += ft_print_percent(p);
	return (p->return_value);
}
