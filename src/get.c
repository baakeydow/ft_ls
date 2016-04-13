/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 02:11:43 by bndao             #+#    #+#             */
/*   Updated: 2016/04/06 03:10:28 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void			date(char *s)
{
	char	*c;
	char	y[6];

	c = ft_strrchr(s, ' ');
	if (c == NULL)
		return ;
	ft_strncpy(y + 1, c + 1, 4);
	y[0] = ' ';
	y[5] = '\0';
	c = ft_strchr(s, ':');
	if (c == NULL)
		return ;
	ft_strcpy(c - 2, y);
	c = ft_strchr(s, ' ');
	if (c == NULL)
		return ;
	c++;
	ft_printf(" %s", c);
}

void				time_it(t_l *l, t_opt *o)
{
	char		*t;
	char		**b;
	int			i;
	struct stat	s;

	i = 0;
	if (!l)
		return ;
	lstat(l->path, &s);
	t = ctime(&s.st_mtime);
	b = ft_strsplit(t, ' ');
	if (s.st_mtime > o->time_c - ((6 * 30 + 2) * 24 * 3600) &&
				s.st_mtime < o->time_c + ((6 * 30 + 2) * 24 * 3600))
	{
		ft_printf(" %s %2d ", b[1], ft_atoi(b[2]));
		ft_printf("%c%c%c%c%c", b[3][0], b[3][1], b[3][2], b[3][3], b[3][4]);
	}
	else
		date(t);
}

char				*chams(char *dir, char *file)
{
	size_t	len1;
	size_t	len2;
	char	*name;

	if (!dir)
		return (file);
	len1 = ft_strlen(dir);
	len2 = ft_strlen(file);
	if (!(name = ft_strnew((len1 + len2) + 1)))
		return (NULL);
	ft_memcpy(name, dir, len1);
	if (ft_strcmp(dir, "/") && dir[ft_strlen(dir) - 1] != '/')
	{
		name[len1] = '/';
		ft_memcpy((name + len1) + 1, file, len2);
	}
	else
		ft_memcpy((name + len1), file, len2);
	return (name);
}

int					thereis_files(t_opt *o)
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

int					no_option(t_opt *o)
{
	if (!o->l && !o->one && !o->rm && !o->a && !o->r && !o->t)
		return (1);
	return (0);
}
