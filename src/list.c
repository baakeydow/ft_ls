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

t_l	 				*l_new(char *arg, struct stat s)
{
	t_l		*node;

	if (!(node = (t_l *)malloc(sizeof(t_l))))
		return (NULL);
	node->arg = arg;
	node->s = s;
	node->next = NULL;
	return (node);
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
		new->next = NULL;
		tmp->next = new;
	}
}

void				push_back_list_mod(t_l *b_list, t_l *new)
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

t_l					*getdir_nodes(char *str, struct stat s)
{
	struct dirent	*f = NULL;
	struct dirent	*file = NULL;
	DIR				*dir = NULL;
	t_l				*l;

	if (!(dir = opendir(str)))
		return (NULL);
	f = readdir(dir);
	l = l_new(f->d_name, s);
	while ((file = readdir(dir)))
		push_back_list(l, l_new(file->d_name, s));
	merge_sort(&l);
	close_dir(dir);
	return (l);
}

t_l					*initav_list(char **av, struct stat s)
{
	int		i;
	t_l 	*start;

	if (no_dir_in(av) || just_dir_in(av))
	{
		i = 2;
		start = l_new(av[1], s);
		while (av[i])
			push_back_list(start, l_new(av[i++], s));
		merge_sort(&start);
		return (start);
	}
	else if (!is_dir(av[1]))
		return (not_by_dir(s, av));
	return (by_dir(s, av));
}
