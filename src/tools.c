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

int					get_padding_size(t_l *l)
{
	int		len;

	len = 0;
	if (!l || (stat(l->path, &l->s) != 0))
		return (0);
	while (l)
	{
		if ((ft_strlen(ft_itoa(l->s.st_size)) >= (size_t)len))
			len = ft_strlen(ft_itoa(l->s.st_size));
		l = l->next;
	}
	return (len);
}

int					get_padding_links(t_l *l)
{
	int		len;

	len = 0;
	if (!l || (stat(l->path, &l->s) != 0))
		return (0);
	while (l)
	{
		if ((ft_strlen(ft_itoa(l->s.st_nlink)) >= (size_t)len))
			len = ft_strlen(ft_itoa(l->s.st_nlink));
		l = l->next;
	}
	return (len);
}

int					get_padding_grp(t_l *l)
{
	int		len;

	len = 0;
	if (!l || (stat(l->path, &l->s) != 0))
		return (0);
	while (l)
	{
		if ((ft_strlen(getgrgid(l->s.st_gid)->gr_name)) >= (size_t)len)
			len = ft_strlen(getgrgid(l->s.st_gid)->gr_name);
		l = l->next;
	}
	return (len);
}

int					get_padding_name(t_l *l)
{
	int		len;

	len = 0;
	if (!l || (stat(l->path, &l->s) != 0))
		return (0);
	while (l)
	{
		if ((ft_strlen(getpwuid(l->s.st_uid)->pw_name)) >= (size_t)len)
			len = ft_strlen(getpwuid(l->s.st_uid)->pw_name);
		l = l->next;
	}
	return (len);
}

int					*get_tab_spaces(t_l *l)
{
	int 	*tab;

	tab = (int *)malloc(sizeof(int) * 4);
	tab[0] = get_padding_links(l);
	tab[1] = get_padding_name(l);
	tab[2] = get_padding_grp(l);
	tab[3] = get_padding_size(l);
	return (tab);
}

void				print_grpname(int len, t_l *l)
{
	int		i;

	i = 0;
	if (!l || (stat(l->path, &l->s) != 0))
		return ;
	if ((size_t)len > ft_strlen(getgrgid(l->s.st_gid)->gr_name))
		i = len - ft_strlen(getgrgid(l->s.st_gid)->gr_name);
	ft_printf("  %s", getgrgid(l->s.st_gid)->gr_name);
	while (i--)
		ft_putchar(' ');
}

void				print_name(int len, t_l *l)
{
	int		i;

	i = 0;
	if (!l || (stat(l->path, &l->s) != 0))
		return ;
	if ((size_t)len > ft_strlen(getpwuid(l->s.st_uid)->pw_name))
		i = len - ft_strlen(getpwuid(l->s.st_uid)->pw_name);
	ft_printf(" %s", getpwuid(l->s.st_uid)->pw_name);
	while (i--)
		ft_putchar(' ');
}

void				print_links(int len, t_l *l)
{
	int		i;

	i = 0;
	if (!l || (stat(l->path, &l->s) != 0))
		return ;
	if ((size_t)len > ft_strlen(ft_itoa(l->s.st_nlink)))
		i = len - ft_strlen(ft_itoa(l->s.st_nlink));
	while (i--)
		ft_putchar(' ');
	ft_printf("  %s", ft_itoa(l->s.st_nlink));
}

void				print_size(int len, t_l *l)
{
	int		i;

	i = 0;
	if (!l || (stat(l->path, &l->s) != 0))
		return ;
	if ((size_t)len > ft_strlen(ft_itoa(l->s.st_size)))
		i = len - ft_strlen(ft_itoa(l->s.st_size));
	while (i--)
		ft_putchar(' ');
	ft_printf("  %s", ft_itoa(l->s.st_size));
}

char				*get_path(char *dir, char *file)
{
	size_t	len1;
	size_t	len2;
	char	*name;

	if (!dir || (!ft_strcmp(dir, "./") || !ft_strcmp(dir, ".")))
		return (file);
	len1 = ft_strlen(dir);
	len2 = ft_strlen(file);
	if (!(name = ft_strnew((len1 + len2) + 1)))
		return (NULL);
	ft_memcpy(name, dir, len1);
	if (ft_strcmp(dir, "/"))
	{
		name[len1] = '/';
		ft_memcpy((name + len1) + 1, file, len2);
	}
	else
		ft_memcpy((name + len1), file, len2);
	return (name);
}

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

int				is_opt(char *fmt)
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

	if (!str)
		return (0);
	if (lstat(str, &s) == 0)
		if (s.st_mode & S_IFDIR)
			return (1);
	return (0);
}

int				is_link(char *str)
{
	struct stat s;

	if (!str)
		return (0);
	if (lstat(str, &s) == 0)
		if (s.st_mode & S_IFLNK)
			return (1);
	return (0);
}

int 			no_dir_in(char **av)
{
	int 	i;
	int 	cmp;

	i = 1;
	cmp = 0;
	while (av[i])
	{
		if (is_dir(av[i]))
			cmp++;
		i++;
	}
	if (cmp == 0)
		return (1);
	return (0);
}

int 			just_dir_in(char **av)
{
	int 	i;
	int 	cmp;

	i = 1;
	cmp = 0;
	while (av[i])
	{
		if (is_dir(av[i]))
			cmp++;
		i++;
	}
	if (cmp == i - 1)
		return (1);
	return (0);
}
