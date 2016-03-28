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
    t_l			*l;
    struct stat s;
	DIR				*dir = NULL;

    if (!lav)
        return (0);
    if (stat(lav->arg, &s) == 0)
    {
        display_av(o, lav, l);
        if (is_dir(lav->arg))
            l = getdir_nodes(lav->arg, s);
        direcursive(l->next, o);
        free(l);
        free(p);
    }
    direcursive(lav->next, o);
    return (1);
}
