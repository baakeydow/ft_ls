/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 01:57:17 by bndao             #+#    #+#             */
/*   Updated: 2016/04/06 03:11:08 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void				stickybits_usr(t_l *l)
{
	struct stat		s;

	lstat(l->path, &s);
	if (s.st_mode & S_IXUSR && s.st_mode & S_ISUID)
		ft_printf("s");
	else if (s.st_mode & S_ISUID)
		ft_putchar('S');
	else if (s.st_mode & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
}

static void				stickybits_grp(t_l *l)
{
	struct stat		s;

	lstat(l->path, &s);
	if (s.st_mode & S_IXGRP && s.st_mode & S_ISGID)
		ft_putchar('s');
	else if (s.st_mode & S_ISGID)
		ft_putchar('S');
	else if (s.st_mode & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
}

static void				stickybits_others(t_l *l)
{
	struct stat		s;

	lstat(l->path, &s);
	if (s.st_mode & S_IXOTH && s.st_mode & S_ISVTX)
		ft_putchar('t');
	else if (s.st_mode & S_ISVTX)
		ft_putchar('T');
	else if (s.st_mode & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');
}

char					get_type(t_l *l)
{
	char			c;
	struct stat		s;

	lstat(l->path, &s);
	c = '-';
	c = S_ISDIR(s.st_mode) ? 'd' : c;
	c = S_ISCHR(s.st_mode) ? 'c' : c;
	c = S_ISBLK(s.st_mode) ? 'b' : c;
	c = S_ISFIFO(s.st_mode) ? 'p' : c;
	c = S_ISLNK(s.st_mode) ? 'l' : c;
	c = S_ISSOCK(s.st_mode) ? 's' : c;
	return (c);
}

void					print_rights(t_l *l)
{
	char			c;
	struct stat		s;

	lstat(l->path, &s);
	if (!l)
		return ;
	ft_putchar(get_type(l));
	ft_putchar(c = (s.st_mode & S_IRUSR ? 'r' : '-'));
	ft_putchar(c = (s.st_mode & S_IWUSR ? 'w' : '-'));
	stickybits_usr(l);
	ft_putchar(c = (s.st_mode & S_IRGRP ? 'r' : '-'));
	ft_putchar(c = (s.st_mode & S_IWGRP ? 'w' : '-'));
	stickybits_grp(l);
	ft_putchar(c = (s.st_mode & S_IROTH ? 'r' : '-'));
	ft_putchar(c = (s.st_mode & S_IWOTH ? 'w' : '-'));
	stickybits_others(l);
}
