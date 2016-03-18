/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:54:26 by bndao             #+#    #+#             */
/*   Updated: 2016/03/12 18:47:35 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	n_w_s(t_data *t, t_conv *c)
{
	if (c->s || c->sm || c->cm || (c->s && t->l) || (c->c && t->l))
		return (0);
	return (1);
}

int					handle_width(int len, t_data *t, t_conv *c)
{
	int			i;
	char		ch;

	ch = ' ';
	if (t->o_zero && !t->o_minus &&
			(c->o || c->x || c->c || false_type(c) ||
			c->sm || c->xm || c->s || c->p || c->u))
		ch = '0';
	i = t->width - len;
	if (t->prec > len && len != 0 && !c->s && !c->sm && !c->cm)
		i = t->width - t->prec;
	if (i < 0)
		return (0);
	if (i == 0 && t->width > len)
	{
		len = 0;
		i = t->width;
	}
	while (i)
	{
		ft_putchar(ch);
		i--;
	}
	return (t->prec > len && n_w_s(t, c) ? t->width - t->prec : t->width - len);
}

int					handle_width_u(int len, t_data *t, uintmax_t d, t_conv *c)
{
	int			i;
	char		ch;
	int			ret;

	ch = ' ';
	if (t->o_zero && !t->o_minus)
		ch = '0';
	ret = 0;
	ret += t->width - len;
	if (t->prec > len)
		ret = t->width - (len - (len - t->prec));
	i = ret;
	if (i < 0 || (t->width > t->prec && return_char(c->b_t_conv, '.') &&
				d == 0))
		return (0);
	while (i--)
		ft_putchar(ch);
	return (ret);
}

int					handle_o_point(int len_conv, t_data *t, intmax_t d)
{
	int			i;
	int			ok;

	ok = 0;
	if (d < 0)
		ok = 1;
	i = t->prec - len_conv - ok;
	if (i <= 0)
		return (0);
	while (i)
	{
		ft_putchar('0');
		i--;
	}
	return (t->prec - len_conv - ok);
}

int					handle_o_point_u(int len_conv, t_data *t)
{
	int			i;

	i = t->prec - len_conv;
	if (i <= 0)
		return (0);
	while (i)
	{
		ft_putchar('0');
		i--;
	}
	return (t->prec - len_conv);
}
