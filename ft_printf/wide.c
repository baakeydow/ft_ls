/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 16:06:33 by bndao             #+#    #+#             */
/*   Updated: 2016/03/16 02:07:31 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int			s_maj_null(t_data *t, t_conv *c)
{
	char		*str;
	int			len;
	int			ret;

	ret = 0;
	str = "(null)";
	len = len_str(t, str, c);
	if (!t->o_minus && t->width)
		ret += handle_width(len, t, c);
	ret += prec_str(t, str, c);
	if (t->o_minus && t->width)
		ret += handle_width(len, t, c);
	return (ret);
}

int					handle_s_maj(va_list conv, t_data *t, t_conv *c)
{
	wchar_t		*str;
	int			len;
	int			ret;

	ret = 0;
	if (!(str = va_arg(conv, wchar_t *)))
		return (s_maj_null(t, c));
	if (!t->prec && !return_char(c->b_t_conv, '.'))
		len = ft_strlen(ft_widestr_2_reg(str));
	else
		len = get_wide_prec(t->prec, str[0]);
	if (!t->o_minus && t->width)
		ret += handle_width(len, t, c);
	ret += prec_str_wide(t, len, ft_widestr_2_reg(str), c);
	if (t->o_minus && t->width)
		ret += handle_width(len, t, c);
	return (ret);
}

int					handle_c_maj(va_list conv, t_data *t, t_conv *c)
{
	wint_t		ch;
	int				ret;
	int				len;

	ret = 0;
	ch = va_arg(conv, wint_t);
	if (!t->prec && !return_char(c->b_t_conv, '.'))
		len = ft_strlen(ft_widechar_2_reg(ch));
	else
		len = get_wide_prec(t->prec, ch);
	if (!t->o_minus && t->width)
		ret += handle_width(len, t, c);
	ret += ch == 0 ? 1 : prec_str_wide(t, len, ft_widechar_2_reg(ch), c);
	if (t->o_minus && t->width)
		ret += handle_width(len, t, c);
	return (ret);
}

char				*ft_widechar_2_reg(wchar_t wide)
{
	char	str[5];

	ft_bzero(str, 5);
	if (wide < 128)
		str[0] = (char)wide;
	else if (wide < 2048)
	{
		str[0] = (wide >> 6) + 192;
		str[1] = (wide & 63) + 128;
	}
	else if (wide < 65536)
	{
		str[0] = (wide >> 12) + 224;
		str[1] = ((wide >> 6) & 63) + 128;
		str[2] = (wide & 63) + 128;
	}
	else if (wide < 1114112)
	{
		str[0] = (wide >> 18) + 240;
		str[1] = ((wide >> 12) & 63) + 128;
		str[2] = ((wide >> 6) & 63) + 128;
		str[3] = (wide & 63) + 128;
	}
	return (ft_strdup(str));
}

char				*ft_widestr_2_reg(wchar_t *src)
{
	char	*str;
	char	*ante;
	char	*post;

	if (!(str = ft_strnew(0)))
		return (NULL);
	while (*src)
	{
		ante = str;
		if (!(post = ft_widechar_2_reg(*src)))
			return (NULL);
		if (!(str = ft_strjoin(ante, post)))
			return (NULL);
		src++;
		ft_strdel(&ante);
		ft_strdel(&post);
	}
	return (str);
}
