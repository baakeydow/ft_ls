/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 01:51:59 by bndao             #+#    #+#             */
/*   Updated: 2016/03/16 02:08:40 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int			neg_and_prec(intmax_t d, t_data *t)
{
	int			ret;

	ret = 0;
	ft_putchar('-');
	ret = handle_o_point(ft_strlen(ft_itoa_ll(d)) - 2, t, d);
	ret += ft_strlen(ft_itoa_ll(d));
	ft_putnbr_ll(-d);
	return (ret);
}

int					handle_o_zero_d(intmax_t d, t_data *t, t_conv *c)
{
	int			ret;

	ret = 0;
	if (t->o_zero && d < 0 && !t->prec && !t->width &&
			return_char(c->b_t_conv, '.'))
		return (ft_strlen(ft_itoa_ll(d)));
	else if (d < 0 && t->prec)
		return (neg_and_prec(d, t));
	else if (d == 0 && !t->prec && return_char(c->b_t_conv, '.'))
	{
		if (t->width)
			ft_putchar(' ');
		return (t->width ? 1 : 0);
	}
	else if (t->o_zero && t->width && d < 0 && !t->o_minus)
		return (c->d ? ft_strlen((ft_itoa_ll(d))) :
				t->width - ft_strlen(ft_itoa_ll(d)) + 1);
	else
		ft_putnbr_ll(d);
	return (ft_strlen(ft_itoa_ll(d)));
}

int					find_z(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'z')
			return (1);
		i++;
	}
	return (0);
}

static char			*str_length(char **str, size_t *i, int *rem)
{
	*i = 0;
	*rem = 0;
	if (!((*str) = (char *)malloc(sizeof(char) * 20)))
		return (NULL);
	return (*str);
}

char				*ft_uitoa_base(uintmax_t nbr, int base, char c)
{
	int		d;
	size_t	i;
	char	*str_number;

	if (!(str_length(&str_number, &i, &d)))
		return (NULL);
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr)
	{
		d = nbr % base;
		str_number[i++] = (d > 9) ? (d - 10) + c : d + '0';
		nbr = nbr / base;
	}
	str_number[i] = '\0';
	return (ft_strrev(str_number));
}
