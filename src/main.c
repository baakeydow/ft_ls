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

int					print_av(t_opt *o, struct stat s)
{
	t_l			*lav;
	t_l			*l;

	lav = initav_list(o->av, s);
	while (lav)
	{
		if (stat(lav->arg, &s) == 0)
		{
			l = getdir_nodes(lav->arg, s);
			display_av(o, lav, l);
			free(l);
		}
		if (o->a)
		{
			if (lav->next && is_dir(lav->arg))
				ft_putchar('\n');
		}
		else if (lav->next && is_dir(lav->arg) && lav->arg[0] != '.')
			ft_putchar('\n');
		lav = lav->next;
	}
	free(lav);
	return (1);
}

int					print(t_opt *o, char *str)
{
	struct stat	s;
	t_l					*l;

	lstat(str, &s);
	if (!(l = getdir_nodes(str, s)))
		return (0);
	if (o->l)
		ft_printf("total %d\n", get_total(l, o));
	while (l)
	{
		print_in(o, l);
		l = l->next;
	}
	free(l);
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
		print(o, "./");
	free(o);
	return (0);
}
