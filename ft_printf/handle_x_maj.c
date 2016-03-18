/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 03:46:46 by bndao             #+#    #+#             */
/*   Updated: 2016/03/12 19:18:42 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int			putsharp(void)
{
	ft_putstr("0X");
	return (2);
}

static void			get_it_done_maj(uintmax_t d, t_data *t, t_conv *c)
{
	if (!(d == 0 && !t->prec && return_char(c->b_t_conv, '.')))
		ft_putstr(ft_uitoa_base(d, 16, 'A'));
	else
		ft_putchar(' ');
}

int					handle_x_maj(va_list conv, t_data *t, t_conv *c)
{
	uintmax_t	d;
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
		ret += handle_width(ft_strlen(ft_uitoa_base(d, 16, 'A')) + sharp, t, c);
	if (t->o_diez && d != 0)
		ret += putsharp();
	if (!t->o_minus && t->width && t->o_zero)
		ret += handle_width(ft_strlen(ft_uitoa_base(d, 16, 'A')) + sharp, t, c);
	if (t->prec)
		ret += handle_o_point_u(ft_strlen(ft_uitoa_base(d, 16, 'A')), t);
	get_it_done_maj(d, t, c);
	ret += ft_strlen(ft_uitoa_base(d, 16, 'A'));
	if (t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_uitoa_base(d, 16, 'A')) + sharp, t, c);
	return (ret);
}
