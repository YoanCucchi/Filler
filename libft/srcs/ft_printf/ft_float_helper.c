/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycucchi <yoan066@yahoo.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:50:38 by ycucchi           #+#    #+#             */
/*   Updated: 2022/05/27 11:50:39 by ycucchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char	*adding_zero(char *nbr, char *s2, char *add_dot, t_float *f)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	tmp = malloc(sizeof(char) * (f->zero_to_add));
	if (!tmp)
		return (NULL);
	tmp = ft_strncpy(tmp, "000000000000000000000000000000000", f->zero_to_add);
	tmp2 = ft_strjoin(tmp, s2);
	nbr = ft_strjoin(add_dot, tmp2);
	free(tmp);
	free(tmp2);
	return (nbr);
}

static unsigned long long	set_amount(t_parameter *p, t_float *f)
{
	int	temp;

	temp = p->precision;
	f->amount = 10;
	while (--temp > 0)
		f->amount *= 10;
	return (f->amount);
}

char	*float_maker(t_parameter *p, t_float *f, char *nbr)
{
	char	*s1;
	char	*s2;
	char	*add_dot;

	f->zero_to_add = ft_nbrlen(f->amount, 10) - 1 - ft_nbrlen(f->decimal, 10);
	s1 = ft_unsigned_long_itoa(f->trunc);
	if (p->precision == 0 && p->dot && !p->sharp)
		return (s1);
	s2 = ft_unsigned_long_itoa(f->decimal);
	add_dot = ft_strjoin(s1, ".");
	if (f->zero_to_add && f->decimal != 0)
		nbr = adding_zero(nbr, s2, add_dot, f);
	else
		nbr = ft_strjoin(add_dot, s2);
	free(s1);
	free(s2);
	free(add_dot);
	return (nbr);
}

void	split_float(t_parameter *p, t_float *f, long double n)
{
	f->sign = 1;
	if (n < 0)
		f->sign = -1;
	n *= f->sign;
	f->amount = set_amount(p, f);
	f->trunc = (unsigned long long)n;
	if (n >= 1)
	{
		rounding_big(n, p, f);
		return ;
	}
	else if (n > 0)
	{
		rounding_small(n, p, f);
		return ;
	}
	else
	{
		f->decimal = 0;
		f->trunc = 0;
		return ;
	}
}
