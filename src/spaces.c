/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bndao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 02:02:48 by bndao             #+#    #+#             */
/*   Updated: 2016/04/06 03:12:25 by bndao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int							get_padding_size(t_l *l)
{
	int				len;
	struct stat		s;

	len = 0;
	if (!l || (stat(l->path, &s) != 0))
		return (0);
	while (l)
	{
		lstat(l->path, &s);
		l->s = s;
		if ((ft_strlen(ft_itoa(l->s.st_size)) >= (size_t)len))
			len = ft_strlen(ft_itoa(l->s.st_size));
		l = l->next;
	}
	return (len);
}

int							get_padding_links(t_l *l)
{
	int				len;
	struct stat		s;

	len = 0;
	if (!l || (stat(l->path, &s) != 0))
		return (0);
	while (l)
	{
		lstat(l->path, &s);
		l->s = s;
		if ((ft_strlen(ft_itoa(l->s.st_nlink)) >= (size_t)len))
			len = ft_strlen(ft_itoa(l->s.st_nlink));
		l = l->next;
	}
	return (len);
}

int							get_padding_grp(t_l *l)
{
	int				len;
	struct stat		s;

	len = 0;
	if (!l || (stat(l->path, &s) != 0))
		return (0);
	while (l)
	{
		lstat(l->path, &s);
		l->s = s;
		if (getgrgid(l->s.st_gid))
		{
			if ((ft_strlen(getgrgid(l->s.st_gid)->gr_name)) >= (size_t)len)
				len = ft_strlen(getgrgid(l->s.st_gid)->gr_name);
		}
		else if ((ft_strlen(ft_itoa(l->s.st_gid))) >= (size_t)len)
			len = ft_strlen(ft_itoa(l->s.st_gid));
		l = l->next;
	}
	return (len);
}

int							get_padding_name(t_l *l)
{
	int				len;
	struct stat		s;

	len = 0;
	if (!l || (stat(l->path, &s) != 0))
		return (0);
	while (l)
	{
		lstat(l->path, &s);
		l->s = s;
		if (getpwuid(l->s.st_uid))
		{
			if ((ft_strlen(getpwuid(l->s.st_uid)->pw_name)) >= (size_t)len)
				len = ft_strlen(getpwuid(l->s.st_uid)->pw_name);
		}
		else if ((ft_strlen(ft_itoa(l->s.st_gid))) >= (size_t)len)
			len = ft_strlen(ft_itoa(l->s.st_gid));
		l = l->next;
	}
	return (len);
}

int							*get_tab_spaces(t_l *l)
{
	int		*tab;

	tab = (int *)malloc(sizeof(int) * 4);
	tab[0] = get_padding_links(l);
	tab[1] = get_padding_name(l);
	tab[2] = get_padding_grp(l);
	tab[3] = get_padding_size(l);
	return (tab);
}
