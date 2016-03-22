/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 07:24:05 by bndao             #+#    #+#             */
/*   Updated: 2016/03/17 07:24:32 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    dir_regfilenames(struct dirent *file, DIR *dir)
{
  while ((file = readdir(dir)))
  {
    if (file->d_name[0] != '.')
      ft_putendl(file->d_name);
  }
}

int     print_dir(int ac, DIR *dir, struct dirent *file, t_pars *p)
{
  if ((dir = opendir(p->l->arg)))
  {
    title(ac, p);
    dir_regfilenames(file, dir);
  }
  return (close_dir(dir));
}

int     print_av(int ac, char **av, struct stat s)
{
  t_pars  *p;
  DIR     *dir = NULL;
  struct  dirent *file = NULL;

  p = init_all(av, s);
  while (p->l)
  {
    print_dir(ac, dir, file, p);
    p->l = p->l->next;
  }
  free(p);
  return (1);
}

int     print_no_av(int ac, struct stat s)
{
  DIR     *dir = NULL;
  struct  dirent *file = NULL;
  t_pars  *p;
  char    **str;

  if (!(str = (char **)malloc(sizeof(char *) * 3)))
    return (0);
  str[0] = "";
  str[1] = ".";
  str[2] = NULL;
  p = init_all(str, s);
  print_dir(ac, dir, file, p);
  free(str);
  free(p);
  return (1);
}

int     main(int ac, char **av)
{
  struct  stat s;

  if (ac != 1)
    print_av(ac, av, s);
  else
    print_no_av(ac, s);
  return (0);
}
