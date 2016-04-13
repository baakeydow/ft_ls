/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 02:07:04 by bndao             #+#    #+#             */
/*   Updated: 2016/04/06 03:13:58 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_links(int len, t_l *l)
{
	int			i;
	struct stat	s;

	i = 0;
	if (!l || (stat(l->path, &s) != 0))
		return ;
	lstat(l->path, &s);
	if ((size_t)len > ft_strlen(ft_itoa(s.st_nlink)))
		i = len - ft_strlen(ft_itoa(s.st_nlink));
	while (i--)
		ft_putchar(' ');
	ft_printf("  %s", ft_itoa(s.st_nlink));
}

void				print_name(int len, t_l *l)
{
	int			i;
	struct stat s;

	i = 0;
	if (!l || (stat(l->path, &s) != 0))
		return ;
	lstat(l->path, &s);
	if (getpwuid(s.st_uid))
	{
		if ((size_t)len > ft_strlen(getpwuid(s.st_uid)->pw_name))
			i = len - ft_strlen(getpwuid(s.st_uid)->pw_name);
		ft_printf(" %s", getpwuid(s.st_uid)->pw_name);
		while (i--)
			ft_putchar(' ');
	}
	else
	{
		if ((size_t)len > ft_strlen(ft_itoa(s.st_uid)))
			i = len - ft_strlen(ft_itoa(s.st_uid));
		ft_printf(" %d", s.st_uid);
		while (i--)
			ft_putchar(' ');
	}
}

void				print_grpname(int len, t_l *l)
{
	int			i;
	struct stat s;

	i = 0;
	if (!l || (stat(l->path, &s) != 0))
		return ;
	lstat(l->path, &s);
	if (getgrgid(s.st_gid))
	{
		if ((size_t)len > ft_strlen(getgrgid(s.st_gid)->gr_name))
			i = len - ft_strlen(getgrgid(s.st_gid)->gr_name);
		ft_printf("  %s", getgrgid(s.st_gid)->gr_name);
		while (i--)
			ft_putchar(' ');
	}
	else
	{
		if ((size_t)len > ft_strlen(ft_itoa(s.st_gid)))
			i = len - ft_strlen(ft_itoa(s.st_gid));
		ft_printf("  %d", s.st_gid);
		while (i--)
			ft_putchar(' ');
	}
}

void				print_size(int len, t_l *l)
{
	int			i;
	struct stat s;

	i = 0;
	if (!l || (stat(l->path, &s) != 0))
		return ;
	lstat(l->path, &s);
	if ((size_t)len > ft_strlen(ft_itoa(s.st_size)))
		i = len - ft_strlen(ft_itoa(s.st_size));
	while (i--)
		ft_putchar(' ');
	if (S_ISBLK(s.st_mode) || S_ISCHR(s.st_mode))
		ft_printf("%3d, %3d", major(s.st_rdev), minor(s.st_rdev));
	else
		ft_printf("  %s", ft_itoa(s.st_size));
}

void				print_space(t_l *l, t_opt *o)
{
	if (l && o->a)
	{
		if (l->next && is_dir(l->path) && !is_link(l->path))
			ft_putchar('\n');
	}
	else if (l && l->next && is_dir(l->path) && !is_link(l->path) && l->arg[0] != '.')
		ft_putchar('\n');
}
