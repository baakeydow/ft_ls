/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 06:59:50 by bndao             #+#    #+#             */
/*   Updated: 2016/04/06 02:58:09 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				title(t_l *lav, t_opt *o)
{
	if (lav && is_dir(lav->path) && !o->a)
	{
		if (lav->arg[0] != '.')
			ft_printf("%s:\n", lav->path);
	}
	else if (is_dir(lav->path) && o->a)
		ft_printf("%s:\n", lav->path);
}

int					is_opt(char *fmt)
{
	int			i;
	struct stat s;

	i = 0;
	if (!fmt)
		return (0);
	if (fmt[0] == '-' && !fmt[1] && stat(fmt, &s) != 0)
		return (0);
	if (fmt[0] != '-' || !fmt[1] || fmt[1] == '-')
		return (0);
	while (fmt[i])
	{
		if (fmt[i] != '-' && fmt[i] != '1' && fmt[i] != 'l' && fmt[i] != 'R' &&
				fmt[i] != 'a' && fmt[i] != 'r' && fmt[i] != 't' &&
				fmt[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}

void				get_link(t_l *l)
{
	int		t;
	char	*buffer;

	buffer = ft_strnew(1024);
	t = 0;
	if (is_link(l->path))
	{
		if ((t = readlink(l->path, buffer, 1024)) && t > 0)
			ft_printf(" %s -> %s\n", l->arg, buffer);
		else
			ft_printf(" %s\n", l->arg);
	}
	else
		ft_printf(" %s\n", l->arg);
	free(buffer);
}

int					get_total(t_l *l, t_opt *o)
{
	int		size;
	struct stat		s;

	if (!l->arg || !l)
		return (0);
	size = 0;
	while (l)
	{
		lstat(l->path, &s);
		if (o->a)
			size += s.st_blocks;
		else if (l->arg[0] != '.')
			size += s.st_blocks;
		l = l->next;
	}
	return (size);
}

int					find_char(char **av, char c)
{
	int				i;
	int				j;
	struct stat		s;

	j = 1;
	while (av[j])
	{
		if (stat(av[j], &s) == 0)
			return (0);
		if (av[j][0] == '-')
		{
			i = 0;
			while (av[j][i])
			{
				if (av[j][i] == c && is_opt(av[j]))
					return (1);
				i++;
			}
		}
		j++;
	}
	return (0);
}
