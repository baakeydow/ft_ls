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

void     display_error(t_l *lav)
{
  struct stat s;

  while (lav)
  {
    if (stat(lav->arg, &s) != 0 && !is_opt(lav->arg))
    {
      ft_printf("ft_ls: ");
      perror(lav->arg);
    }
    lav = lav->next;
  }
}

int   close_dir(DIR *dir)
{
  if (dir && closedir(dir) == -1)
  {
    perror("Error");
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

void    title(t_l *lav, t_pars *p)
{
  if (is_dir(lav->arg) && !p->o->a)
  {
    if (lav->arg[0]!= '.')
      ft_printf("%s:\n", lav->arg);
  }
  else if (is_dir(lav->arg) && p->o->a)
      ft_printf("%s:\n", lav->arg);
}

int     thereisno_file(t_opt *o)
{
  int i;
  int cmp;
  struct stat s;

  i = 1;
  cmp = 0;
  while (o->av[i])
  {
    if (stat(o->av[i], &s) == 0)
      cmp++;
    i++;
  }
  if (cmp == 0)
    return (1);
  return (0);
}

int     is_opt(char *fmt)
{
  int  i;

  i = 0;
  if (fmt[0] != '-' || !fmt[1])
    return (0);
  while (fmt[i])
  {
    if (fmt[i] != '-' && fmt[i] != '1' && fmt[i] != 'l' && fmt[i] != 'R' &&
                         fmt[i] != 'a' && fmt[i] != 'r' && fmt[i] != 't' &&
                       fmt[i] != '\0')
      return (0);
    i++;
  }
  return (1);
}
