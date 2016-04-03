/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 14:40:29 by bndao             #+#    #+#             */
/*   Updated: 2016/03/27 17:45:50 by bndao            ###   ########.fr       */
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

t_l	 				*l_new(char *dir, char *arg)
{
	t_l		*node;
	struct stat	s;

	lstat(get_path(dir, arg), &s);
	if (!(node = (t_l *)malloc(sizeof(t_l))))
		return (NULL);
	node->arg = arg;
	node->path = get_path(dir, arg);
	node->s = s;
	node->next = NULL;
	return (node);
}

t_l					*getdir_nodes(char *str, t_opt *o)
{
	struct dirent	*f = NULL;
	struct dirent	*file = NULL;
	DIR				*dir = NULL;
	t_l				*l;

	if (!(dir = opendir(str)))
		return (NULL);
	f = readdir(dir);
	l = l_new(str, ft_strdup(f->d_name));
	while ((file = readdir(dir)))
		push_back_list(l, l_new(str, ft_strdup(file->d_name)));
	merge_sort(&l, o);
	close_dir(dir);
	return (l);
}
