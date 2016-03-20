/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 01:00:17 by bndao             #+#    #+#             */
/*   Updated: 2016/03/14 20:05:32 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				get_wide_prec(int prec, wchar_t wide)
{
	int			i;
	int			l;

	i = 0;
	l = 0;
	if (wide < 128)
		l = 1;
	else if (wide < 2048)
		l = 2;
	else if (wide < 65536)
		l = 3;
	else if (wide < 1114112)
		l = 4;
	while (prec % l != 0)
		prec--;
	return (prec);
}

int					prec_str_wide(t_data *t, int len, char *str, t_conv *c)
{
	int			i;
	int			l;

	i = len;
	l = 0;
	if ((!len && t->width) || (!t->prec && return_char(c->b_t_conv, '.')))
		return (0);
	if (!t->prec && !return_char(c->b_t_conv, '.'))
	{
			ft_putstr(str);
			return (ft_strlen(str));
	}
	if (t->prec > (int)ft_strlen(str))
	{
		ft_putstr(str);
		return ((int)ft_strlen(str));
	}
	while (i--)
		ft_putchar(str[l++]);
	return (len);
}

int					prec_str(t_data *t, char *str, t_conv *c)
{
	int			i;
	int			l;

	i = 0;
	l = 0;
	if (!ft_strlen(str) && t->width)
		return (0);
	if (t->prec || return_char(c->b_t_conv, '.'))
	{
		i = t->prec;
		if (i > (int)ft_strlen(str))
		{
			ft_putstr(str);
			return ((int)ft_strlen(str));
		}
		while (i--)
			ft_putchar(str[l++]);
		return (t->prec);
	}
	ft_putstr(str);
	return (ft_strlen(str));
}

int					len_str(t_data *t, char *str, t_conv *c)
{
	if ((!t->prec && return_char(c->b_t_conv, '.')) ||
			((int)ft_strlen(str) > t->prec && return_char(c->b_t_conv, '.')))
		return (t->prec);
	return ((int)ft_strlen(str));
}
