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

int     print(t_opt *o, struct stat s)
{
  t_pars  *p;
  t_l     *l;

  l = getdir_nodes("./", s);
  p = init_data(o, l);
  while (p->l)
  {
    if (!p->o->a)
    {
      if (p->l->arg[0] != '.' && !is_opt(p->l->arg))
        ft_printf("%s\n", p->l->arg);
    }
    else if (!is_opt(p->l->arg))
        ft_printf("%s\n", p->l->arg);
    p->l = p->l->next;
  }
  free(p);
  free(l);
  return (1);
}

void    display_av(t_pars *p, t_l *lav, t_l *l)
{
  if (p->o->ac != 2)
    title(lav, p);
  while (p->l)
  {
    if (p->o->a)
        ft_printf("%s\n", p->l->arg);
    else if (p->l->arg[0] != '.')
        ft_printf("%s\n", p->l->arg);
    p->l = p->l->next;
  }
  if (!l)
  {
    if (!is_opt(lav->arg))
      ft_printf("%s\n", lav->arg);;
    if (!is_opt(lav->arg) && lav->next && is_dir(lav->next->arg))
      ft_putchar('\n');
  }
  if (lav->next && l)
    ft_putchar('\n');
}

int     print_av(t_opt *o, struct stat s)
{
  t_pars  *p;
  t_l     *lav;
  t_l     *l;

  lav = l_new(o->av[1], s);
  lav = initav_list(lav, o->av, s);
  display_error(lav);
  merge_sort(&lav);
  while (lav)
  {
    if (lstat(lav->arg, &s) != -1)
    {
      l = getdir_nodes(lav->arg, s);
      p = init_data(o, l);
      display_av(p, lav, l);
    }
    lav = lav->next;
  }
  free(lav);
  return (1);
}

int     main(int ac, char **av)
{
  struct  stat s;
  t_opt        *o;

  o = get_opt(ac, av);
  lstat(av[1], &s);
  if (ac != 1 && !(ac == 2 && (o->one || o->a)))
    print_av(o, s);
  else
    print(o, s);
  free(o);
  return (0);
}
