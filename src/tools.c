/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 07:53:38 by bndao             #+#    #+#             */
/*   Updated: 2016/03/27 17:27:00 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				close_dir(DIR *dir)
{
	if (dir && closedir(dir) == -1)
	{
		perror("Error");
		return (EXIT_FAILURE);
	}
	return (1);
}

int				is_dir(char *str)
{
	struct stat s;

	if (lstat(str, &s) == 0)
		if (s.st_mode & S_IFDIR)
			return (1);
	return (0);
}

void			title(t_l *lav, t_pars *p)
{
	if (is_dir(lav->arg) && !p->o->a)
	{
		if (lav->arg[0]!= '.')
			ft_printf("%s:\n", lav->arg);
	}
	else if (is_dir(lav->arg) && p->o->a)
		ft_printf("%s:\n", lav->arg);
}

int				thereisno_file(t_opt *o)
{
	int			i;
	int			cmp;
	struct stat s;

	i = 1;
	cmp = 0;
	while (o->av[i])
	{
		if (stat(o->av[i], &s) == 0)
			cmp++;
		i++;
	}
	if (cmp == 0)
		return (1);
	return (0);
}

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

static void		look_for_it(char **av, t_l *l, struct stat s)
{
	int			w;

	w = 0;
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
		}
		l = l->next;
	}
	free(l);
}

void			display_error(char **av)
{
	t_l			*l;
	struct stat	s;
	int			j;

	if (av[1])
	{
		j = 2;
		lstat(av[1], &s);
		l = l_new(av[1], s);
		if (av[j])
			while (av[j])
				push_back_list(l, l_new(av[j++], s));
		merge_sort(&l);
		look_for_it(av, l, s);
	}
}
