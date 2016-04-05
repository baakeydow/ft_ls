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

static void	date(char *s)
{
	char *c;
	char year[6];

	c = ft_strrchr(s, ' ');
	if (c == NULL)
		return ;
	ft_strncpy(year + 1, c + 1, 4);
	year[0] = ' ';
	year[5] = '\0';
	c = ft_strchr(s, ':');
	if (c == NULL)
		return ;
	ft_strcpy(c - 2, year);
	c = ft_strchr(s, ' ');
	if (c == NULL)
		return ;
	c++;
	ft_printf(" %s", c);
}


void				time_it(t_l *l, t_opt *o)
{
	char	*t;
	char	**b;
	int		i;

	i = 0;
	if (!l)
		return ;
	t = ctime(&l->s.st_mtime);
	b = ft_strsplit(t, ' ');
	if (l->s.st_mtime > o->time_c - ((6 * 30 + 2) * 24 * 3600)  &&
				l->s.st_mtime < o->time_c + ((6 * 30 + 2) * 24 * 3600))
	{
		ft_printf(" %s %2d ", b[1], ft_atoi(b[2]));
		ft_printf("%c%c%c%c%c", b[3][0], b[3][1], b[3][2], b[3][3], b[3][4]);
	}
	else
		date(t);
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

static void 				stickybits_usr(t_l *l)
{
	if (l->s.st_mode & S_IXUSR && l->s.st_mode & S_ISUID)
		ft_printf("s");
	else if (l->s.st_mode & S_ISUID)
		ft_putchar('S');
	else if (l->s.st_mode & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
}

static void 				stickybits_grp(t_l *l)
{
	if (l->s.st_mode & S_IXGRP && l->s.st_mode & S_ISGID)
		ft_putchar('s');
	else if (l->s.st_mode & S_ISGID)
		ft_putchar('S');
	else if (l->s.st_mode & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
}

static void 				stickybits_others(t_l *l)
{
	if (l->s.st_mode & S_IXOTH && l->s.st_mode & S_ISVTX)
		ft_putchar('t');
	else if (l->s.st_mode & S_ISVTX)
		ft_putchar('T');
	else if (l->s.st_mode & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void				print_rights(t_l *l)
{
	char	c;

	if (!l)
		return ;
	ft_putchar(get_type(l));
	ft_putchar(c = (l->s.st_mode & S_IRUSR ? 'r' : '-'));
	ft_putchar(c = (l->s.st_mode & S_IWUSR ? 'w' : '-'));
	stickybits_usr(l);
	ft_putchar(c = (l->s.st_mode & S_IRGRP ? 'r' : '-'));
	ft_putchar(c = (l->s.st_mode & S_IWGRP ? 'w' : '-'));
	stickybits_grp(l);
	ft_putchar(c = (l->s.st_mode & S_IROTH ? 'r' : '-'));
	ft_putchar(c = (l->s.st_mode & S_IWOTH ? 'w' : '-'));
	stickybits_others(l);
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
