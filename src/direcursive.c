/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direcursive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 20:21:01 by bndao             #+#    #+#             */
/*   Updated: 2016/03/27 20:21:12 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void  		   just_print(t_l *l, t_opt *o)
{
    if (o->l)
        ft_printf("total %d\n", get_total(l, o));
    while (l)
    {
        print_in(o, l);
        l = l->next;
    }
    free(l);
}

int             direcursive(t_l *l, t_opt *o)
{
    if (!l || !l->path)
        return (0);
    if (is_dir(l->path) && l->arg[0] != '.')
    {
        ft_printf("\n%s:\n", l->path);
        just_print(getdir_nodes(l->arg, l->s, o), o);
    }
    direcursive(l->next, o);
    return (1);
}
