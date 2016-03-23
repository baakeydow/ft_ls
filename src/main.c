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

void    display_av(t_pars *p, t_l *lav, t_l *l)
{
  if (p->ac != 2)
    title(lav);
  while (p->l)
  {
    ft_printf("%s\n", p->l->arg);
    p->l = p->l->next;
  }
  if (!l)
  {
    ft_printf("%s\n", lav->arg);
    if (lav->next && is_dir(lav->next->arg))
      ft_putchar('\n');
  }
  if (lav->next && l)
    ft_putchar('\n');
}

int     print_av(int ac, char **av, struct stat s)
{
  t_pars  *p;
  t_l     *lav;
  t_l     *l;

  lav = l_new(av[1], s);
  lav = initav_list(lav, av, s);
  merge_sort(&lav);
  while (lav)
  {
    l = getdir_nodes(lav->arg, s);
    p = init_data(ac, l);
    display_av(p, lav, l);
    free(p);
    free(l);
    lav = lav->next;
  }
  free(lav);
  return (1);
}

int     print(int ac, struct stat s)
{
  t_pars  *p;
  t_l     *l;

  l = getdir_nodes("./", s);
  p = init_data(ac, l);
  while (p->l)
  {
    ft_printf("%s\n", p->l->arg);
    p->l = p->l->next;
  }
  free(p);
  free(l);
  return (1);
}

int     main(int ac, char **av)
{
  struct  stat s;

  lstat(av[1], &s);
  if (ac != 1 && !(ac == 2 && ft_strcmp(av[1], "-1") == 0))
    print_av(ac, av, s);
  else
    print(ac, s);
  return (0);
}
