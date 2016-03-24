/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 14:40:29 by bndao             #+#    #+#             */
/*   Updated: 2016/03/20 14:40:50 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_l	 			*l_new(char *arg, struct stat s)
{
	t_l  		*node;

	if (!(node = (t_l *)malloc(sizeof(t_l))))
		return (NULL);
	node->arg = arg;
  node->s = s;
	node->next = NULL;
	return (node);
}

void				push_back_list(t_l *b_list, t_l *new)
{
	t_l    		*tmp;

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

t_l     *getdir_nodes(char *str, struct stat s)
{
  struct dirent *f = NULL;
  struct dirent *file = NULL;
  DIR           *dir = NULL;
  t_l           *l;

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

t_l      *initav_list(t_l *start, char **av, struct stat s)
{
  int    i;

  i = 2;
	if (!av[i])
		return (start);
  while (av[i])
    push_back_list(start, l_new(av[i++], s));
  return (start);
}

t_pars    *init_data(t_opt *o, t_l *l)
{
  t_pars		*ptr;

  if (!(ptr = (t_pars *)malloc(sizeof(t_pars))))
    return (NULL);
  ptr->l = l;
	ptr->o = get_opt(o->ac, o->av);
  return (ptr);
}
