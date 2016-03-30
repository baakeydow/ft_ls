/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 06:59:50 by bndao             #+#    #+#             */
/*   Updated: 2016/03/27 17:45:23 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

int					get_total(t_l *l, t_opt *o)
{
	int		size;

	size = 0;
	while (l)
	{
		if (o->a)
			size += l->s.st_blocks;
		else if (l->arg[0] != '.')
			size += l->s.st_blocks;
		l = l->next;
	}
	return (size);
}

char				get_type(t_l *l)
{
	char	c;

	c = '-';
	c = S_ISDIR(l->s.st_mode) ? 'd' : c;
	c = S_ISCHR(l->s.st_mode) ? 'c' : c;
	c = S_ISBLK(l->s.st_mode) ? 'b' : c;
	c = S_ISFIFO(l->s.st_mode) ? 'p' : c;
	c = S_ISLNK(l->s.st_mode) ? 'l' : c;
	c = S_ISSOCK(l->s.st_mode) ? 's' : c;
	return (c);
}

void				print_rights(t_l *l)
{
	char	c;

	ft_putchar(get_type(l));
	ft_putchar(c = (l->s.st_mode & S_IRUSR ? 'r' : '-'));
	ft_putchar(c = (l->s.st_mode & S_IWUSR ? 'w' : '-'));
	ft_putchar(c = (l->s.st_mode & S_IXUSR ? 'x' : '-'));
	ft_putchar(c = (l->s.st_mode & S_IRGRP ? 'r' : '-'));
	ft_putchar(c = (l->s.st_mode & S_IWGRP ? 'w' : '-'));
	ft_putchar(c = (l->s.st_mode & S_IXGRP ? 'x' : '-'));
	ft_putchar(c = (l->s.st_mode & S_IROTH ? 'r' : '-'));
	ft_putchar(c = (l->s.st_mode & S_IWOTH ? 'w' : '-'));
	ft_putchar(c = (l->s.st_mode & S_IXOTH ? 'x' : '-'));
}
