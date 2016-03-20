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

void  title(int ac, char *str)
{
  if (ac >= 3 && is_dir(str) && str[0] != '.')
    ft_printf("\n%s:\n", str);
}

void  dir_regfilenames(struct dirent *file, DIR *dir)
{
  while ((file = readdir(dir)))
  {
    if (file->d_name[0] != '.')
      ft_putendl(file->d_name);
  }
}

int   print_dir(DIR *dir, struct dirent *file, char *str)
{
  if ((dir = opendir(str)))
  {
      title(3, str);
      dir_regfilenames(file, dir);
  }
  return (close_dir(dir));
}

int   print_av(DIR *dir, struct dirent *file, char **av)
{
  int     i;

  i = 1;
  while (av[i])
  {
    if (is_dir(av[i]))
      print_dir(dir, file, av[i]);
    if (!is_dir(av[i]))
      ft_putendl(av[i]);
    i++;
  }
  return (close_dir(dir));
}

int   print(int all, int ac, char **av)
{
  DIR     *dir = NULL;
  struct  dirent *file = NULL;

  if (all == 0 && ac == 1)
    print_dir(dir, file, "./");
  if (all == 0 && ac != 1)
    print_av(dir, file, av);
  return (1);
}

int     main(int ac, char **av)
{
  t_mylist  *b;
  t_l       *l;
  t_pars    *p;
  struct  stat s;

  if (!(b = (t_mylist *)malloc(sizeof(t_mylist))))
    return (-1);
  if (ac >= 3)
  {
    l = l_new(av[1], s);
    b->begin = l;
    l = init_list(l, av, s);
    l = b->begin;
    p = init_data(l, b);
    while (p->l)
    {
      ft_putendl(p->l->arg);
      ft_putnbr(p->l->s.st_mode);
      p->l = p->l->next;
    }
  }
//  print(0, ac, av);
  return (0);
}
