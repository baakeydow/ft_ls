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

void				print_file(t_l *la, t_opt *o)
{
	if (o->a)
	{
		if (stat(la->path, &(la->s)) == 0)
			l_option(la, o);
		if (stat(la->path, &(la->s)) == 0 && la->next && is_dir(la->next->path))
			ft_putchar('\n');
	}
	else if (la->arg[0] != '.')
	{
		if (stat(la->path, &(la->s)) == 0)
			l_option(la, o);
		if (stat(la->path, &(la->s)) == 0 && la->next && is_dir(la->next->path))
			ft_putchar('\n');
	}
}

void				print_in(t_l *l, t_opt *o)
{
	struct stat s;

	if ((stat(l->path, &s) == 0) && o->a && !is_opt(l->path))
		l_option(l, o);
	else if ((stat(l->path, &s) == 0) && l->arg[0] != '.' && !is_opt(l->path))
		l_option(l, o);
	else if ((stat(l->path, &s) == 0) && l->arg[0] != '.' && !is_opt(l->path))
		l_option(l, o);
	else if ((stat(l->path, &s) == 0) && o->a && !is_opt(l->path))
		l_option(l, o);
}
