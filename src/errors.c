/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 19:59:37 by bndao             #+#    #+#             */
/*   Updated: 2016/03/27 19:59:47 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			usage(char *str)
{
	int		i;

	i = 1;
	while (str[i] || !str[i])
	{
		if (str[i] != '1' && str[i] != 'l' && str[i] != 'R' &&
				str[i] != 'a' && str[i] != 'r' && str[i] != 't')
		{
			ft_putstr_fd("ft_ls: illegal option -- ", 2);
			ft_putchar_fd(str[i], 2);
			ft_putendl_fd("\nusage: ft_ls [-1lRart] [file ...]", 2);
			exit (EXIT_FAILURE);
		}
		i++;
	}
}

static int			look_for_it(char **av, t_l *l)
{
	int			w;
	int			c;
	struct stat s;

	w = 0;
	c = 0;
	while (l)
	{
		if (stat(av[1], &s) == 0 || !is_opt(av[1]))
			w = 1;
		if ((is_opt(l->arg) && w == 1) ||
				(stat(l->arg, &s) != 0 && !is_opt(l->arg)))
		{
			if (l->arg[0] == '-' && l->arg[1] && !is_opt(l->arg))
				usage(l->arg);
			else
			{
				ft_printf("ft_ls: ");
				perror(l->arg);
			}
			c = 1;
		}
		l = l->next;
	}
	free(l);
	return (c);
}

int				display_error(char **av, t_opt *o)
{
	t_l			*l;
	int			j;

	if (!o)
		return (1);
	if (av[1])
	{
		j = 2;
		l = l_new(NULL, av[1]);
		if (av[j])
			while (av[j])
				push_back_list(l, l_new(NULL, av[j++]));
		merge_sort(&l, o);
		return (look_for_it(av, l));
	}
	return (0);
}

int				thereis_files(t_opt *o)
{
	int			i;
	int			cmp;
	struct stat s;

	i = 1;
	cmp = 0;
	if (!o)
		return (0);
	if (o->ac == 1)
		return (0);
	while (o->av[i])
	{
		if (stat(o->av[i], &s) == 0)
			cmp++;
		i++;
	}
	if (cmp == 0)
		return (0);
	return (cmp);
}

int				no_option(t_opt *o)
{
	if (!o->l && !o->one && !o->rm && !o->a && !o->r && !o->t)
		return (1);
	return (0);
}
