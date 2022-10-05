/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:15:18 by ycucchi           #+#    #+#             */
/*   Updated: 2022/04/15 16:15:20 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_parse_flags(char *str, t_parameter *p)
{
	while (ft_strchr(FLAGS, *str) && *str != '.')
	{
		if (*str == '#')
			p->sharp = 1;
		if (*str == '0')
			p->zero = 1;
		if (*str == '-')
			p->minus = 1;
		if (*str == '+')
			p->plus = 1;
		if (*str == ' ')
			p->space = 1;
		str++;
		p->format++;
	}
}

static void	ft_parse_width(char *str, va_list ap, t_parameter *p)
{
	while (!ft_strchr(SPECIFIERS, *str) && !ft_strchr(LENGTH, *str))
	{
		if (*str == '.')
			return ;
		if ((ft_strchr(WIDTH, *str) || *str == '*') && !p->wildcard_check)
		{
			if (*str == '*')
			{
				p->width = va_arg(ap, int);
				if (p->width < 0)
				{
					p->width = p->width * (-1);
					p->minus = 1;
				}
				str++;
			}
			if (ft_isdigit(*str))
				p->width = ft_atoi(str);
			else
				str--;
			p->wildcard_check = 1;
		}
		str++;
		p->format++;
	}
}

static void	ft_parse_precision(char *str, va_list ap, t_parameter *p)
{
	if (*str != '.')
		return ;
	p->dot = 1;
	str++;
	p->format++;
	while (!ft_strchr(SPECIFIERS, *str) && !ft_strchr(LENGTH, *str))
	{
		if ((ft_isdigit(*str) || *str == '*') && !p->wildcard_check)
		{
			if (*str == '*')
			{
				p->precision = va_arg(ap, int);
				if (p->precision < 0)
				{
					p->precision = 0;
					p->dot = 0;
				}
			}
			else
				p->precision = ft_atoi(str);
			p->wildcard_check = 1;
		}
		str++;
		p->format++;
	}
}

static int	ft_parse_length(char *str, t_parameter *p)
{
	int		i;
	char	*tmp;
	void	*clear_mem;

	tmp = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!tmp)
		return (EXIT_FAILURE);
	clear_mem = ft_memset(tmp, 0, ft_strlen(str));
	if (!clear_mem)
		return (0);
	i = 0;
	while (!ft_strchr(SPECIFIERS, str[i]))
	{
		if (ft_strchr(LENGTH, str[i]))
		{
			tmp[i] = str[i];
			i = is_it_double_specifier(str, tmp, i, p);
		}
		p->format++;
		i++;
	}
	p->length = ft_strdup(tmp);
	free(tmp);
	return (0);
}

int	ft_parse(char *str, va_list ap, t_parameter *p)
{
	p->format = str;
	ft_parse_flags(p->format, p);
	ft_parse_width(p->format, ap, p);
	p->wildcard_check = 0;
	ft_parse_precision(p->format, ap, p);
	ft_parse_length(p->format, p);
	if (ft_strcmp("ll", p->length) && ft_strcmp("l", p->length) && \
		ft_strcmp("h", p->length) && ft_strcmp("hh", p->length) && \
		ft_strcmp("L", p->length))
	{
		free(p->length);
		p->length = NULL;
	}
	p->specifier = *p->format;
	conversion_type(p, ap);
	return (0);
}
