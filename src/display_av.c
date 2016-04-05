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

void				print_file(t_l *la, t_opt *o, int *tab)
{
	if (o->a)
	{
		if (stat(la->path, &(la->s)) == 0)
			l_option(la, o, tab);
		if (stat(la->path, &(la->s)) == 0 && la->next && is_dir(la->next->path))
			ft_putchar('\n');
	}
	else if (la->arg[0] != '.')
	{
		if (stat(la->path, &(la->s)) == 0)
			l_option(la, o, tab);
		if (stat(la->path, &(la->s)) == 0 && la->next && is_dir(la->next->path))
			ft_putchar('\n');
	}
}

void				print_in(t_l *l, t_opt *o, int *tab)
{
	struct stat s;

	if ((stat(l->path, &s) == 0) && o->a && !is_opt(l->arg))
		l_option(l, o, tab);
	else if ((stat(l->path, &s) == 0) && l->arg[0] != '.' && !is_opt(l->arg))
		l_option(l, o, tab);
}

void				l_option(t_l *l, t_opt *o, int *tab)
{
	if (o->l)
	{
		print_rights(l);
		print_links(tab[0], l);
		print_name(tab[1], l);
		print_grpname(tab[2], l);
		print_size(tab[3], l);
		time_it(l, o);
		get_link(l);
	}
	else
		ft_printf("%s\n", l->arg);
}
