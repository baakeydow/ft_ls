/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_av.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 05:13:04 by bndao             #+#    #+#             */
/*   Updated: 2016/04/06 02:53:50 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int						print_av(t_l *lav, t_opt *o)
{
	struct stat		s;
	t_l				*l;

	while (lav)
	{
		if (stat(lav->path, &s) == 0)
		{
			if (/*is_dir(lav->path)*/go_in(lav->path, o))
			{
				if (thereis_files(o) >= 2)
					title(lav, o);
				l = getdir_nodes(lav->path, o);
				if (o->rm)
					direcursive(l, o);
				else
					just_print(l, o);
			}
			else
				print_file(lav, o, get_tab_spaces(lav));
			print_space(lav, o);
		}
		lav = lav->next;
	}
	return (1);
}

void					l_option(t_l *l, t_opt *o, int *tab)
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

void					print_in(t_l *l, t_opt *o, int *tab)
{
	struct stat s;

	if ((stat(l->path, &s) == 0) && o->a && !is_opt(l->arg))
		l_option(l, o, tab);
	else if ((stat(l->path, &s) == 0) && l->arg[0] != '.' && !is_opt(l->arg))
		l_option(l, o, tab);
}

void					just_print(t_l *l, t_opt *o)
{
	int		*tab;

	if (!l)
		return ;
	tab = get_tab_spaces(l);
	if (thereis_files(o) >= 2)
		title(l, o);
	if (o->l && get_total(l, o) != 0)
		ft_printf("total %d\n", get_total(l, o));
	while (l)
	{
		print_in(l, o, tab);
		l = l->next;
	}
}

void					print_file(t_l *la, t_opt *o, int *tab)
{
	if (o->a)
	{
		if (stat(la->path, &(la->s)) == 0)
			l_option(la, o, tab);
		if (stat(la->path, &(la->s)) == 0 && la->next &&
				!is_link(la->path) && is_dir(la->next->path))
			ft_putchar('\n');
	}
	else if (la->arg[0] != '.')
	{
		if (stat(la->path, &(la->s)) == 0)
			l_option(la, o, tab);
		if (stat(la->path, &(la->s)) == 0 && la->next &&
				!is_link(la->path) && is_dir(la->next->path))
			ft_putchar('\n');
	}
}
