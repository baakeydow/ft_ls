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
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void				push_back_list(t_l *b_list, t_l *list)
{
	t_l    		*tmp;

	if (b_list == NULL)
		b_list = list;
	else
	{
		tmp = b_list;
		while (tmp->next)
			tmp = tmp->next;
		list->prev = tmp;
		list->next = NULL;
		tmp->next = list;
	}
}

void					swap_elem_data(t_l *elem1, t_l *elem2)
{
  t_l		      tmp;

  tmp.arg = elem1->arg;
  elem1->arg = elem2->arg;
  elem2->arg = tmp.arg;
  tmp.s = elem1->s;
  elem1->s = elem2->s;
  elem2->s = tmp.s;
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

t_pars    *init_data(t_l *l, t_mylist *b)
{
  t_pars		*ptr;

  if (!(ptr = (t_pars *)malloc(sizeof(t_pars))))
    return (NULL);
  ptr->l = l;
  ptr->b = b;
  return (ptr);
}

t_pars  	*init_all(char **av, struct stat s)
{
  t_mylist  *b;
  t_l       *l;
  t_pars    *p;

	if (!(b = (t_mylist *)malloc(sizeof(t_mylist))))
    return (NULL);
  l = l_new(av[1], s);
	merge_sort(&l);
  b->begin = l;
  l = init_list(l, av, s);
  l = b->begin;
  p = init_data(l, b);
  return (p);
}
