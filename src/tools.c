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

void    title(int ac, t_pars *p)
{
  if (ac != 2 && is_dir(p->l->arg) && p->l->arg[0] != '.')
    ft_printf("%s:\n", p->l->arg);
}
