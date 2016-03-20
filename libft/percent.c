/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:54:33 by bndao             #+#    #+#             */
/*   Updated: 2016/03/12 17:58:42 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char					return_char(char *fmt, char c)
{
	int				i;

	i = 0;
	if (!fmt)
		return (0);
	while (fmt[i])
	{
		if (fmt[i] == c)
			return (c);
		i++;
	}
	return (0);
}

char					find_o_zero(char *fmt)
{
	int				i;

	i = 0;
	if (!fmt)
		return (0);
	while (fmt[i] && !ft_isdigit(fmt[i]))
		i++;
	if (fmt[i] == 48)
		return (48);
	return (0);
}

int						percent_nbr(const char *fmt)
{
	size_t			i;
	int				p;

	i = 0;
	p = 0;
	if (!fmt)
		return (-1);
	while (fmt[i])
	{
		if (fmt[i] == '%')
			p++;
		i++;
	}
	return (p);
}

int						find_width(char *str)
{
	int				i;
	int				start;

	i = 0;
	start = 0;
	if (!str)
		return (0);
	if (str[i] == '.')
		return (0);
	while (str[i] && (!(ft_isdigit(str[i])) || str[i] == '0') && str[i] != '.')
		i++;
	if (i > (int)ft_strlen(str))
		return (0);
	start = i;
	while (ft_isdigit(str[i]))
		i++;
	return (ft_atoi(ft_strsub(str, start, i)));
}

int						find_prec(char *str)
{
	int				i;
	int				start;

	i = 0;
	start = 0;
	if (!str)
		return (0);
	if (str[i++] == '.')
	{
		start = i;
		while (ft_isdigit(str[i]))
			i++;
		return (ft_atoi(ft_strsub(str, start, i)));
	}
	while (str[i] && str[i] != '.')
		i++;
	if (i > (int)ft_strlen(str))
		return (0);
	start = i + 1;
	while (ft_isdigit(str[++i]))
		;
	return (ft_atoi(ft_strsub(str, start, i)));
}
