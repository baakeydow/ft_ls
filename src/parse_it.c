/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 06:59:50 by bndao             #+#    #+#             */
/*   Updated: 2016/03/23 07:00:05 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					find_char(char **av, char c)
{
	int				i;
  int       j;

  j = 1;
  while (av[j])
  {
    if (av[j][0] == '-')
    {
      i = 0;
	    while (av[j][i])
      {
		    if (av[j][i] == c)
			    return (1);
		    i++;
	    }
    }
    j++;
  }
	return (0);
}

t_opt      *get_opt(int ac, char **av)
{
  t_opt   *o;

  if (!(o = (t_opt *)malloc(sizeof(t_opt))))
    return (NULL);
  o->av = av;
  o->ac = ac;
  o->one = find_char(av, '1');
  o->l = find_char(av, 'l');
  o->rm = find_char(av, 'R');
  o->a = find_char(av, 'a');
  o->r = find_char(av, 'r');
  o->t = find_char(av, 't');
  return (o);
}
