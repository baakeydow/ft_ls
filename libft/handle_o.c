/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 00:18:59 by bndao             #+#    #+#             */
/*   Updated: 2016/03/16 00:19:13 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int			strange_case(uintmax_t d, t_data *t, t_conv *c)
{
	if (!(d == 0 && !t->prec && return_char(c->b_t_conv, '.') &&
				!t->o_diez && !t->width))
	{
		if (d == 0 && !t->o_diez && t->width)
			ft_putchar(' ');
		else
			ft_putstr(ft_uitoa_base(d, 8, 'a'));
		return (1);
	}
	return (0);
}

static int			strange_case_maj(uintmax_t d, t_data *t, t_conv *c)
{
	if (!(d == 0 && !t->prec && return_char(c->b_t_conv, '.') &&
				!t->o_diez && !t->width))
	{
		if (d == 0 && !t->o_diez && t->width)
			ft_putchar(' ');
		else
			ft_putstr(ft_uitoa_base(d, 8, 'A'));
		return (1);
	}
	return (0);
}

int					handle_o(va_list conv, t_data *t, t_conv *c)
{
	uintmax_t	d;
	int			sharp;
	int			ret;

	ret = 0;
	sharp = 0;
	if (t->o_diez)
		sharp = 1;
	d = size_uox(conv, t, c);
	if (!t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_uitoa_base(d, 8, 'a')) + sharp, t, c);
	if (t->o_diez && d != 0)
	{
		ret += 1;
		ft_putchar('0');
	}
	if (t->prec)
		ret += handle_o_point_u(ft_strlen(ft_uitoa_base(d, 8, 'a')) + sharp, t);
	if (!(strange_case(d, t, c)))
		ret -= 1;
	ret += ft_strlen(ft_uitoa_base(d, 8, 'a'));
	if (t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_uitoa_base(d, 8, 'a')) + sharp, t, c);
	return (ret);
}

int					handle_o_maj(va_list conv, t_data *t, t_conv *c)
{
	uintmax_t	d;
	int			sharp;
	int			ret;

	ret = 0;
	sharp = 0;
	if (t->o_diez)
		sharp = 1;
	d = size_uox(conv, t, c);
	if (!t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_uitoa_base(d, 8, 'A')) + sharp, t, c);
	if (t->o_diez && d != 0)
	{
		ret += 1;
		ft_putchar('0');
	}
	if (!t->o_minus && t->prec)
		ret += handle_o_point_u(ft_strlen(ft_uitoa_base(d, 8, 'A')) + sharp, t);
	if (!(strange_case_maj(d, t, c)))
		ret -= 1;
	ret += ft_strlen(ft_uitoa_base(d, 8, 'A'));
	if (t->o_minus && t->width)
		ret += handle_width(ft_strlen(ft_uitoa_base(d, 8, 'A')) + sharp, t, c);
	return (ret);
}
