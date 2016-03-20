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

void				push_back_node(t_l *b_list, t_l *list)
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

t_l      *init_list(t_l *start, char **av, struct stat s)
{
  int    i;

  i = 2;
  while (av[i])
    push_back_node(start, l_new(av[i++], s));
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
