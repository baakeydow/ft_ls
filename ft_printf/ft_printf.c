/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:54:17 by bndao             #+#    #+#             */
/*   Updated: 2016/03/14 14:58:11 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

struct s_va_arg	tab[TAB_SIZE] = {{&handle_s, 's'},
	{&handle_s_maj, 'S'}, {&handle_p, 'p'}, {&handle_d, 'd'},
	{&handle_d_maj, 'D'}, {&handle_i, 'i'}, {&handle_o, 'o'},
	{&handle_o_maj, 'O'}, {&handle_u, 'u'}, {&handle_u_maj, 'U'},
	{&handle_x, 'x'}, {&handle_x_maj, 'X'}, {&handle_c, 'c'},
	{&handle_c_maj, 'C'}};

int				handle(va_list f, t_va_arg tab[TAB_SIZE], t_data *t, t_conv *c)
{
	int			i;

	i = 0;
	if (*(t->cpy) == '%')
		return (handle_glued(t));
	if (false_type(c))
		return (handle_false_type(c, t));
	while (i < TAB_SIZE)
	{
		if (tab[i].c == return_char(c->b_t_conv, tab[i].c))
			return (tab[i].f(f, t, c));
		i++;
	}
	return (0);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		conv;
	t_data		*t;
	t_conv		*c;
	int			ret;

	ret = 0;
	if (percent_nbr(format) == 0 || percent_nbr(format) == -1)
		return (handle_no_p_cent(format));
	va_start(conv, format);
	while (*format)
	{
		ret += printchar((const char **)&format);
		if (*format++ == '%')
		{
			t = init(format);
			c = init_conv(format);
			ret += handle(conv, tab, t, c);
			format = after_t_conv(format, c, t);
			c = wipe_conv();
			t = wipe_data();
		}
	}
	va_end(conv);
	return (ret);
}
