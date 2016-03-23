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

  lstat(arg, &s);
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

t_l      *init_list(t_l *start, char **av, struct stat s)
{
  int    i;

  i = 2;
	if (!av[i])
		return (start);
  while (av[i])
    push_back_list(start, l_new(av[i++], s));
  return (start);
}

t_pars    *init_data(int ac, t_l *l)
{
  t_pars		*ptr;

  if (!(ptr = (t_pars *)malloc(sizeof(t_pars))))
    return (NULL);
  ptr->l = l;
	ptr->ac = ac;
  return (ptr);
}

t_pars  	*init_current(int ac, t_l *l)
{
  t_pars    *p;

	merge_sort(&l);
	p = init_data(ac, l);
  return (p);
}
