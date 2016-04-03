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

int             isnot_points(char *str)
{
    if (!str)
        return (0);
    if (str[0] == '.')
        return (0);
    if (ft_strlen(str) > 2 && str[0] == '.' && str[1] == '.')
        return (0);
    return (1);
}

int             direcursive(t_l *l, t_opt *o)
{
    t_l     *n;

    n = NULL;
    if (!l)
        return (0);
    just_print(l, o);
    while (l)
    {
        if (is_dir(l->path) && isnot_points(l->arg))
        {
            ft_putchar('\n');
            title(l, o);
            n = getdir_nodes(l->path, o);
            direcursive(n->next, o);
        }
        l = l->next;
    }
    return (1);
}
