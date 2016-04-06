/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 02:07:04 by bndao             #+#    #+#             */
/*   Updated: 2016/04/06 02:07:22 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				print_links(int len, t_l *l)
{
	int		i;
	struct stat s;

	i = 0;
	if (!l || (stat(l->path, &s) != 0))
		return ;
	l->s = s;
	if ((size_t)len > ft_strlen(ft_itoa(l->s.st_nlink)))
		i = len - ft_strlen(ft_itoa(l->s.st_nlink));
	while (i--)
		ft_putchar(' ');
	ft_printf("  %s", ft_itoa(l->s.st_nlink));
}

void				print_name(int len, t_l *l)
{
	int		i;
	struct stat s;

	i = 0;
	if (!l || (stat(l->path, &s) != 0))
		return ;
	l->s = s;
	if (getpwuid(l->s.st_uid))
	{
		if ((size_t)len > ft_strlen(getpwuid(l->s.st_uid)->pw_name))
			i = len - ft_strlen(getpwuid(l->s.st_uid)->pw_name);
		ft_printf(" %s", getpwuid(l->s.st_uid)->pw_name);
		while (i--)
			ft_putchar(' ');
	}
	else
	{
		if ((size_t)len > ft_strlen(ft_itoa(l->s.st_uid)))
			i = len - ft_strlen(ft_itoa(l->s.st_uid));
		ft_printf(" %d", l->s.st_uid);
		while (i--)
			ft_putchar(' ');
	}
}

void				print_grpname(int len, t_l *l)
{
	int		i;
	struct stat s;

	i = 0;
	if (!l || (stat(l->path, &s) != 0))
		return ;
	l->s = s;
	if (getgrgid(l->s.st_gid))
	{
		if ((size_t)len > ft_strlen(getgrgid(l->s.st_gid)->gr_name))
			i = len - ft_strlen(getgrgid(l->s.st_gid)->gr_name);
		ft_printf("  %s", getgrgid(l->s.st_gid)->gr_name);
		while (i--)
			ft_putchar(' ');
	}
	else
	{
		if ((size_t)len > ft_strlen(ft_itoa(l->s.st_gid)))
			i = len - ft_strlen(ft_itoa(l->s.st_gid));
		ft_printf("  %d", l->s.st_gid);
		while (i--)
			ft_putchar(' ');
	}
}

void				print_size(int len, t_l *l)
{
	int		i;
	struct stat s;

	i = 0;
	if (!l || (stat(l->path, &s) != 0))
		return ;
	l->s = s;
	if ((size_t)len > ft_strlen(ft_itoa(l->s.st_size)))
		i = len - ft_strlen(ft_itoa(l->s.st_size));
	while (i--)
		ft_putchar(' ');
	if (S_ISBLK(l->s.st_mode) || S_ISCHR(l->s.st_mode))
		ft_printf("%3d, %3d", major(l->s.st_rdev), minor(l->s.st_rdev));
	else
		ft_printf("  %s", ft_itoa(l->s.st_size));
}

void				print_space(t_l *l, t_opt *o)
{
	if (l && o->a)
	{
		if (l->next && is_dir(l->path))
			ft_putchar('\n');
	}
	else if (l && l->next && is_dir(l->path) && l->arg[0] != '.')
		ft_putchar('\n');
}
