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

int					print_av(t_l *lav, t_opt *o)
{
	struct stat s;
	t_l			*l;

	while (lav)
	{
		if (stat(lav->path, &s) == 0)
		{
			if (is_dir(lav->path))
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

void  		   just_print(t_l *l, t_opt *o)
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

int							print_all_right(t_opt *o)
{
	t_l					*l;

	l = NULL;
	if (o->ac != 1 && thereis_files(o))
	{
		l = initav_list(o->av, o);
		print_av(l, o);
	}
	else if ((!thereis_files(o) && !no_option(o)) || o->ac == 1)
	{
		l = getdir_nodes(".", o);
		if (o->rm)
			return (direcursive(l, o));
		just_print(l, o);
	}
	return (1);
}

int					main(int ac, char **av)
{
	t_opt			*o;

	o = get_opt(ac, av);
	if (!display_error(av, o))
		print_all_right(o);
	free(o);
	return (0);
}
