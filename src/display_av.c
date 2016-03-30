/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_av.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 05:13:04 by bndao             #+#    #+#             */
/*   Updated: 2016/03/28 05:13:25 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				codekeepin(t_opt *o, t_l *la)
{
	if (o->a)
	{
		if (stat(la->arg, &(la->s)) == 0)
			l_option(la, o);
		if (stat(la->arg, &(la->s)) == 0 && la->next && is_dir(la->next->arg))
			ft_putchar('\n');
	}
	else if (la->arg[0] != '.')
	{
		if (stat(la->arg, &(la->s)) == 0)
			l_option(la, o);
		if (stat(la->arg, &(la->s)) == 0 && la->next && is_dir(la->next->arg))
			ft_putchar('\n');
	}
	if (o->a)
	{
		if (la->next && is_dir(la->arg))
			ft_putchar('\n');
	}
	else if (la->next && is_dir(la->arg) && la->arg[0] != '.')
		ft_putchar('\n');
}

void				print_in(t_opt *o, t_l *l)
{
	if (o->a && !is_opt(l->arg))
		l_option(l, o);
	else if (l->arg[0] != '.' && !is_opt(l->arg))
		l_option(l, o);
	else if (l->arg[0] != '.' && !is_opt(l->arg))
		l_option(l, o);
	else if (o->a && !is_opt(l->arg))
		l_option(l, o);
}

void				display_av(t_opt *o, t_l *lav, t_l *l)
{
	if (thereis_files(o) >= 2)
		title(lav, o);
	if (l)
	{
		if (o->l)
			ft_printf("total %d\n", get_total(l, o));
		while (l)
		{
			print_in(o, l);
			l = l->next;
		}
		free(l);
	}
	else
		codekeepin(o, lav);
}
