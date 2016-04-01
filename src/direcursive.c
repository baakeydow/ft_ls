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
    if (!l)
        return ;
    if (o->l)
        ft_printf("total %d\n", get_total(l, o));
    while (l)
    {
        print_in(o, l);
        l = l->next;
    }
}

// int             isnot_points(char *str)
// {
//     if (str[0] == '.')
//         return (0);
// }

int             direcursive(t_l *l, t_opt *o)
{
    t_l     *n;

    n = NULL;
    if (!l || !l->path)
        return (0);
    just_print(l, o);
    while (l)
    {
        if (is_dir(l->path) && l->arg[0] != '.')
        {
            if (l->path[0] != '.' && is_dir(l->path))
                ft_printf("\n%s:\n", l->path);
            n = getdir_nodes(l->path, l->s, o);
            direcursive(n->next, o);
        }
        l = l->next;
    }
    free(l);
    if (n)
        free(n);
    return (1);
}
