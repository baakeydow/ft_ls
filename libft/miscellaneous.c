/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 19:55:55 by bndao             #+#    #+#             */
/*   Updated: 2016/03/12 17:58:31 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int						printchar(const char **cpy)
{
	if (**cpy == '%')
		return (0);
	ft_putchar(*cpy[0]);
	return (1);
}

int						handle_no_p_cent(const char *cpy)
{
	if (!cpy)
		return (-1);
	ft_putstr(cpy);
	return (ft_strlen(cpy));
}

int						is_b_t_conv(const char *fmt, int *i)
{
	if (fmt[*i] == 's' || fmt[*i] == 'S' || fmt[*i] == 'p' ||
			fmt[*i] == 'd' || fmt[*i] == 'D' || fmt[*i] == 'i' ||
			fmt[*i] == 'o' || fmt[*i] == 'O' || fmt[*i] == 'u' ||
			fmt[*i] == 'U' || fmt[*i] == 'x' || fmt[*i] == 'X' ||
			fmt[*i] == 'c' || fmt[*i] == 'C')
		return (0);
	return (1);
}

int						is_not_data(const char *fmt, int *i)
{
	if (fmt[*i] == '-' || fmt[*i] == '+' || fmt[*i] == '#' ||
			fmt[*i] == ' ' || ft_isdigit(fmt[*i]) || fmt[*i] == 'l' ||
			fmt[*i] == 'h' || fmt[*i] == 'j' || fmt[*i] == 'z' ||
			fmt[*i] == '.')
		return (0);
	return (1);
}

int						false_type(t_conv *c)
{
	if (!c->s && !c->sm && !c->p && !c->d && !c->dm && !c->i && !c->o &&
			!c->om && !c->u && !c->um && !c->x && !c->xm && !c->c && !c->cm)
		return (1);
	return (0);
}
