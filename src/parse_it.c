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

void				time_it(t_l *l)
{
	char	*t;
	char	**b;
	int		i;

	i = 0;
	t = ctime(&l->s.st_mtime);
	b = ft_strsplit(t, ' ');
	ft_printf(" %s %s ", b[1], b[2]);
	ft_printf("%c%c%c%c%c", b[3][0], b[3][1], b[3][2], b[3][3], b[3][4]);
}

static void			get_link(t_l *l)
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

void				l_option(t_l *l, t_opt *o)
{
	if (o->l)
	{
		print_rights(l);
		ft_printf("  %d", l->s.st_nlink);
		ft_printf(" %s", getpwuid(l->s.st_uid)->pw_name);
		ft_printf("  %s", getgrgid(l->s.st_gid)->gr_name);
		ft_printf("  %5d", l->s.st_size);
		time_it(l);
		get_link(l);
	}
	else
		ft_printf("%s\n", l->arg);
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

int					get_total(t_l *l, t_opt *o)
{
	int		size;

	if (!l->arg || !l)
		return (0);
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
