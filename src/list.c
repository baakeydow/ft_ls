/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 14:40:29 by bndao             #+#    #+#             */
/*   Updated: 2016/04/13 08:10:18 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_opt				*get_opt(int ac, char **av)
{
	t_opt	*o;

	if (!(o = (t_opt *)malloc(sizeof(t_opt))))
		return (NULL);
	o->av = av;
	o->ac = ac;
	o->time_c = time(NULL);
	o->one = find_char(av, '1');
	o->l = find_char(av, 'l');
	o->rm = find_char(av, 'R');
	o->a = find_char(av, 'a');
	o->r = find_char(av, 'r');
	o->t = find_char(av, 't');
	return (o);
}

void				push_back_list(t_l *b_list, t_l *new)
{
	t_l		*tmp;

	if (b_list == NULL)
		b_list = new;
	else
	{
		tmp = b_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_l					*l_new(char *dir, char *arg)
{
	t_l			*node;
	struct stat	s;

	lstat(chams(dir, arg), &s);
	if (!(node = (t_l *)malloc(sizeof(t_l))))
		return (NULL);
	node->arg = arg;
	node->path = chams(dir, arg);
	node->s = s;
	node->next = NULL;
	return (node);
}

t_l					*getdir_nodes(char *str, t_opt *o)
{
	struct dirent	*f;
	struct dirent	*file;
	DIR				*dir;
	t_l				*l;

	f = NULL;
	file = NULL;
	dir = NULL;
	if (!(dir = opendir(str)))
	{
		ft_putstr("ft_ls: ");
		perror(str);
		return (NULL);
	}
	f = readdir(dir);
	l = l_new(str, ft_strdup(f->d_name));
	while ((file = readdir(dir)))
		push_back_list(l, l_new(str, ft_strdup(file->d_name)));
	merge_sort(&l, o);
	close_dir(dir);
	return (l);
}

t_l					*initav_list(char **av, t_opt *o)
{
	int		i;
	t_l		*start;

	if (no_dir_in(av) || just_dir_in(av))
	{
		i = 2;
		start = l_new(NULL, av[1]);
		while (av[i])
			push_back_list(start, l_new(NULL, av[i++]));
		merge_sort(&start, o);
		return (start);
	}
	else if (!is_dir(av[1]))
		return (not_by_dir(av, o));
	return (by_dir(av, o));
}
