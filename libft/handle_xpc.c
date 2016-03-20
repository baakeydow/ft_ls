/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_xpc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 21:34:31 by bndao             #+#    #+#             */
/*   Updated: 2016/03/15 21:34:56 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int			putsharp(void)
{
	ft_putstr("0x");
	return (2);
}

static void			get_it_done(long int d, t_data *t, t_conv *c)
{
	if (!(d == 0 && !t->prec && return_char(c->b_t_conv, '.')))
		ft_putstr(ft_uitoa_base(d, 16, 'a'));
	else
		ft_putchar(' ');
}

int					handle_x(va_list conv, t_data *t, t_conv *c)
{
	long int	d;
	int			sharp;
	int			ret;

	ret = 0;
	sharp = 0;
	if (t->o_diez)
		sharp = 2;
	d = size_uox(conv, t, c);
	if (d == 0 && !t->prec && !t->width && return_char(c->b_t_conv, '.'))
		return (0);
	if (!t->o_minus && t->width && !t->o_zero)
		ret += handle_width(ft_strlen(ft_uitoa_base(d, 16, 'a')) + sharp, t, c);
	if (t->o_diez && d != 0)
		ret += putsharp();
	if (!t->o_minus && t->width && t->o_zero)
		ret += handle_width(ft_strlen(ft_uitoa_base(d, 16, 'a')) + sharp, t, c);
	if (t->prec)
		ret += handle_o_point_u(ft_strlen(ft_uitoa_base(d, 16, 'a')), t);
	get_it_done(d, t, c);
	ret += ft_strlen(ft_uitoa_base(d, 16, 'a'));
	if (t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_uitoa_base(d, 16, 'a')) + sharp, t, c);
	return (ret);
}

int					handle_p(va_list conv, t_data *t, t_conv *c)
{
	long int	d;
	int			ret;

	ret = 0;
	if (!(d = va_arg(conv, long int)) && d != 0)
		return (null_case());
	if (!t->o_minus && t->width && (t->prec || !t->o_zero))
		ret += handle_width(ft_strlen(ft_itoa_base(d, 16, 'a')) + 2, t, c);
	ft_putstr("0x");
	if (!t->o_minus && t->width && !t->prec && t->o_zero)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 16, 'a')) + 2, t, c);
	if (d == 0 && !t->prec && return_char(c->b_t_conv, '.'))
		return (2);
	if (t->prec)
		ret += handle_o_point(ft_strlen(ft_itoa_base(d, 16, 'a')), t, d);
	ft_putstr(ft_itoa_base(d, 16, 'a'));
	ret += 2 + ft_strlen(ft_itoa_base(d, 16, 'a'));
	if (t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_itoa_base(d, 16, 'a')) + 2, t, c);
	return (ret);
}

int					handle_c(va_list conv, t_data *t, t_conv *c)
{
	char		ch;
	int			ret;

	ret = 0;
	if (t->l)
		return (handle_c_maj(conv, t, c));
	ch = (char)va_arg(conv, int);
	if (!t->o_minus && t->width)
		ret += handle_width(1, t, c);
	write(1, &ch, 1);
	ret += 1;
	if (t->o_minus && t->width)
		ret += handle_width(1, t, c);
	return (ret);
}
