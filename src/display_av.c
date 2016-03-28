/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_av.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 05:13:04 by bndao             #+#    #+#             */
/*   Updated: 2016/03/28 05:13:25 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	           title(t_l *lav, t_opt *o)
{
	if (is_dir(lav->arg) && !o->a)
	{
		if (lav->arg[0]!= '.')
			ft_printf("%s:\n", lav->arg);
	}
	else if (is_dir(lav->arg) && o->a)
		ft_printf("%s:\n", lav->arg);
}

void				print_in(t_opt *o, char *str)
{
	if (o->a && !is_opt(str))
		ft_printf("%s\n", str);
	else if (str[0] != '.' && !is_opt(str))
		ft_printf("%s\n", str);
}

void				codekeepin(t_opt *o, t_l *la)
{
	if (o->a)
	{
		if (stat(la->arg, &(la->s)) == 0)
			ft_printf("%s\n", la->arg);;
		if (stat(la->arg, &(la->s)) == 0 && la->next && is_dir(la->next->arg))
			ft_putchar('\n');
	}
	else if (la->arg[0] != '.')
	{
		if (stat(la->arg, &(la->s)) == 0)
			ft_printf("%s\n", la->arg);;
		if (stat(la->arg, &(la->s)) == 0 && la->next && is_dir(la->next->arg))
			ft_putchar('\n');
	}
	if (o->a)
	{
		if (la->next && is_dir(la->arg))
			ft_putchar('\n');
	}
	else if (la->next && is_dir(la->arg) && la->arg[0] != '.')
		ft_putchar('\n');
}

void				display_av(t_opt *o, t_l *lav, t_l *l)
{
	if (thereis_files(o) >= 2)
		title(lav, o);
	if (l)
	{
		while (l)
		{
			print_in(o, l->arg);
			l = l->next;
		}
		free(l);
	}
	else
		codekeepin(o, lav);
}
