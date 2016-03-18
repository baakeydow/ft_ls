/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:54:49 by bndao             #+#    #+#             */
/*   Updated: 2016/03/16 02:06:33 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int							handle_s(va_list conv, t_data *t, t_conv *c)
{
	char		*str;
	int			len;
	int			ret;

	ret = 0;
	if (t->l)
		return (handle_s_maj(conv, t, c));
	if (!(str = va_arg(conv, char *)))
		str = "(null)";
	len = len_str(t, str, c);
	if (!t->o_minus && t->width)
		ret += handle_width(len, t, c);
	ret += prec_str(t, str, c);
	if (t->o_minus && t->width)
		ret += handle_width(len, t, c);
	return (ret);
}

static int					prec_zero_width(intmax_t d, t_data *t, t_conv *c)
{
	int			ret;

	ret = 0;
	if (t->prec && d >= 0)
		ret += handle_o_point(ft_strlen(ft_itoa_ll(d)), t, d);
	ret += handle_o_zero_d(d, t, c);
	if (t->o_minus && t->width)
		ret += handle_width_d(ft_strlen(ft_itoa_ll(d)), t, d, c);
	if (t->o_plus && !t->o_zero && t->width)
		ret -= 1;
	return (ret);
}

int							handle_d(va_list conv, t_data *t, t_conv *c)
{
	intmax_t		d;
	int				n[4];

	n[0] = 0;
	n[1] = 0;
	n[2] = 0;
	n[3] = 0;
	if ((d = size_d(conv, t, c)) >= 0 && t->o_plus && (!t->width || t->o_zero))
	{
		ft_putchar('+');
		n[0] = 1;
		n[1] = 1;
		n[3] = 1;
	}
	n[0] += handle_o_space(d, t, c);
	((n[0] == 1 && !t->o_plus) || t->o_space) ? n[2] = 1 : 1;
	if (!t->o_minus && t->width)
		n[0] += handle_width_d(ft_strlen(ft_itoa_ll(d)) + n[1] + n[2], t, d, c);
	if (d >= 0 && t->o_plus && !t->o_space && !n[3])
	{
		ft_putchar('+');
		n[0] += 1;
	}
	n[0] += prec_zero_width(d, t, c);
	return (n[0]);
}

int							handle_u(va_list conv, t_data *t, t_conv *c)
{
	uintmax_t		d;
	int				ret;

	ret = 0;
	d = size_uox(conv, t, c);
	if (!t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa_ull(d)), t, c);
	if (!t->o_minus && t->prec)
		ret += handle_o_point_u(ft_strlen(ft_itoa_ull(d)), t);
	if (d == 0 && !t->prec && return_char(c->b_t_conv, '.'))
		return (0);
	ft_putnbr_u(d);
	ret += ft_strlen(ft_itoa_ull(d));
	if (t->o_minus && t->width)
		ret += handle_width_u(ft_strlen(ft_itoa_ull(d)), t, d, c);
	return (ret);
}
