/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conv2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 01:47:53 by bndao             #+#    #+#             */
/*   Updated: 2016/03/16 01:48:06 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int			put_minus(intmax_t d, t_data *t)
{
	if (d < 0 && t->o_zero && !t->o_minus && !t->prec)
	{
		ft_putchar('-');
		return (1);
	}
	return (0);
}

static int			no_width(int i, intmax_t d, t_data *t, t_conv *c)
{
	if (i < 0 || (t->width > t->prec && return_char(c->b_t_conv, '.') &&
				d <= 0 && t->o_zero))
		return (1);
	return (0);
}

static void			neg_num(intmax_t d, t_data *t)
{
	if (d < 0 && t->o_zero && !t->o_minus && !t->prec)
	{
		d = -d;
		ft_putnbr(d);
	}
}

int					handle_width_d(int len, t_data *t, intmax_t d, t_conv *c)
{
	int			f[3];
	char		ch;

	ch = ' ';
	if (t->o_zero && !t->o_minus && !t->prec)
		ch = '0';
	f[1] = 0;
	f[2] = 0;
	if (put_minus(d, t))
		f[1] = 1;
	if (d < 0 && t->prec && t->prec > len)
		f[1] = 1;
	f[2] += t->width - len;
	if (t->prec > len)
		f[2] = t->width - (len - (len - t->prec)) - f[1];
	f[0] = f[2];
	if (no_width(f[0], d, t, c))
		return (0);
	if (t->o_plus && !t->o_zero && f[0] != 0)
		f[0] = f[0] - 1;
	while ((f[0])--)
		ft_putchar(ch);
	neg_num(d, t);
	return (f[2]);
}

int					handle_o_space(intmax_t d, t_data *t, t_conv *c)
{
	int			ret;

	ret = 0;
	if ((d >= 0 && !t->o_plus && t->o_space && !c->u && !t->prec) ||
			(d == 0 && t->o_zero && t->width && t->prec))
	{
		ft_putchar(' ');
		ret = 1;
	}
	return (ret);
}
