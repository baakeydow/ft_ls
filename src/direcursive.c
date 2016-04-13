/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direcursive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 20:21:01 by bndao             #+#    #+#             */
/*   Updated: 2016/04/13 05:12:26 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				isnot_points(char *str)
{
	if (!str)
		return (0);
	if (ft_strlen(str) == 1 && str[0] == '.')
		return (0);
	if (ft_strlen(str) == 2 && str[0] == '.' && str[1] == '.')
		return (0);
	return (1);
}

int				direcursive(t_l *l, t_opt *o)
{
	t_l		*n;
	t_l		*tmp;

	n = NULL;
	if (!l)
		return (0);
	just_print(l, o);
	while (l)
	{
		tmp = l->next;
		if (is_dir(l->path) && isnot_points(l->arg))
		{
			ft_putchar('\n');
			title(l, o);
			if (o->a)
				n = getdir_nodes(l->path, o);
			else if (l->arg[0] != '.')
				n = getdir_nodes(l->path, o);
			if (n)
				direcursive(n, o);
		}
		free(l);
		l = tmp;
	}
	return (1);
}
