/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 07:53:38 by bndao             #+#    #+#             */
/*   Updated: 2016/03/17 07:54:02 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int   close_dir(DIR *dir)
{
  if (dir && closedir(dir) == -1)
  {
    perror("Error ");
    return(EXIT_FAILURE);
  }
  return (1);
}

int   is_dir(char *str)
{
  struct  stat s;

  if (lstat(str, &s) == 0)
    if (s.st_mode & S_IFDIR)
      return (1);
  return (0);
}

t_l	 			*l_new(char *arg)
{
	t_l  		*node;

	if (!(node = (t_l *)malloc(sizeof(t_l))))
		return (NULL);
	node->arg = arg;
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
