/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 21:45:13 by bndao             #+#    #+#             */
/*   Updated: 2016/03/12 18:33:40 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

intmax_t				size_d(va_list conv, t_data *t, t_conv *c)
{
	intmax_t		nbr;

	nbr = 0;
	if ((!t->h && !t->hh && !t->l && !t->ll && !t->j && !t->z && !c->dm) ||
			(t->hh && c->dm))
		nbr = va_arg(conv, int);
	else if (t->h && c->dm)
		nbr = va_arg(conv, long int);
	else if (t->h)
		nbr = (short)va_arg(conv, int);
	else if (t->hh)
		nbr = (char)va_arg(conv, int);
	else if (t->l || c->dm)
		nbr = va_arg(conv, long int);
	else if (t->ll || t->j)
		nbr = va_arg(conv, intmax_t);
	else if (t->z)
		nbr = va_arg(conv, size_t);
	return (nbr);
}

uintmax_t				size_uox(va_list conv, t_data *t, t_conv *c)
{
	uintmax_t		nbr;

	nbr = 0;
	if (!t->h && !t->hh && !t->l && !t->ll && !t->j && !t->z && !c->um &&
			!c->om)
		nbr = va_arg(conv, unsigned int);
	else if (t->hh && c->um)
		nbr = (unsigned short int)va_arg(conv, unsigned int);
	else if (t->hh && c->om)
		nbr = (unsigned short int)va_arg(conv, unsigned int);
	else if (t->h && !(t->h && c->um))
		nbr = (unsigned short int)va_arg(conv, unsigned int);
	else if (t->hh)
		nbr = (unsigned char)va_arg(conv, unsigned int);
	else if (t->l || c->om || (t->h && c->um))
		nbr = va_arg(conv, unsigned long int);
	else if (t->ll || t->j || c->um)
		nbr = va_arg(conv, uintmax_t);
	else if (t->z)
		nbr = va_arg(conv, size_t);
	return (nbr);
}

int				handle_d_maj(va_list conv, t_data *t, t_conv *c)
{
	return (handle_d(conv, t, c));
}

int				handle_i(va_list conv, t_data *t, t_conv *c)
{
	return (handle_d(conv, t, c));
}

int				handle_u_maj(va_list conv, t_data *t, t_conv *c)
{
	return (handle_u(conv, t, c));
}
