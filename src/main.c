/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 07:24:05 by bndao             #+#    #+#             */
/*   Updated: 2016/04/06 02:57:22 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			ok(t_opt *o)
{
	if ((!display_error(o->av, o) &&
				!thereis_files(o) &&
				!no_option(o)) || o->ac == 1)
		return (1);
	return (0);
}

int					print_all_right(t_opt *o)
{
	t_l		*l;

	l = NULL;
	if (!o)
		return (0);
	if (ok(o))
	{
		l = getdir_nodes(".", o);
		if (o->rm)
			return (direcursive(l, o));
		just_print(l, o);
	}
	else if (o->ac != 1 && thereis_files(o))
	{
		l = initav_list(o->av, o);
		print_av(l, o);
	}
	return (1);
}

int					main(int ac, char **av)
{
	t_opt	*o;

	o = get_opt(ac, av);
	if (o)
		print_all_right(o);
	free(o);
	return (0);
}
