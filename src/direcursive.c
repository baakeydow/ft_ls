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

int             direcursive(t_l *lav, t_opt *o)
{
    t_pars		*p;
    t_l			*l;
    struct stat s;

    if (!lav)
        return (0);
    while (lav)
    {
        if (stat(lav->arg, &s) == 0)
        {
            l = getdir_nodes(lav->arg, s);
            p = init_data(o, l);
            display_av(p, lav, l);
            free(l);
            free(p);
        }
        lav = lav->next;
    }
    free(lav);
    return (1);
}
