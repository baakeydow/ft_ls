/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 07:24:05 by bndao             #+#    #+#             */
/*   Updated: 2016/03/27 17:23:36 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					print(t_opt *o, struct stat s)
{
	t_pars		*p;
	t_l			*l;

	l = getdir_nodes("./", s);
	p = init_data(o, l);
	while (p->l)
	{
		if (!p->o->a)
		{
			if (p->l->arg[0] != '.' && !is_opt(p->l->arg))
				ft_printf("%s\n", p->l->arg);
		}
		else if (!is_opt(p->l->arg))
			ft_printf("%s\n", p->l->arg);
		p->l = p->l->next;
	}
	free(p);
	free(l);
	return (1);
}

void				display_av(t_pars *p, t_l *lav, t_l *l)
{
	if (thereis_files(p->o) >= 2)
		title(lav, p);
	while (p->l)
	{
		if (p->o->a)
			ft_printf("%s\n", p->l->arg);
		else if (p->l->arg[0] != '.')
			ft_printf("%s\n", p->l->arg);
		p->l = p->l->next;
	}
	if (!l)
	{
		if (stat(lav->arg, &(lav->s)) == 0)
			ft_printf("%s\n", lav->arg);;
		if (stat(lav->arg, &(lav->s)) == 0 && lav->next && is_dir(lav->next->arg))
			ft_putchar('\n');
	}
	if (lav->next && l)
		ft_putchar('\n');
}

int					print_av(t_opt *o, struct stat s)
{
	t_pars		*p;
	t_l			*lav;
	t_l			*l;

	lav = l_new(o->av[1], s);
	lav = initav_list(lav, o->av, s);
	merge_sort(&lav);
	if (o->rm)
		return (direcursive(lav, o));
	while (lav)
	{
		if (stat(lav->arg, &s) == 0)
		{
			l = getdir_nodes(lav->arg, s);
			p = init_data(o, l);
			display_av(p, lav, l);
			free(l);
			free(p);
		}
		lav = lav->next;
	}
	free(lav);
	return (1);
}

int					main(int ac, char **av)
{
	struct stat		s;
	t_opt			*o;

	display_error(av);
	o = get_opt(ac, av);
	lstat(av[0], &s);
	if (ac != 1 && thereis_files(o))
		print_av(o, s);
	else if ((!thereis_files(o) && !no_option(o)) || ac == 1)
		print(o, s);
	free(o);
	return (0);
}
