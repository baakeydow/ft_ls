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

void				title(t_l *lav, t_opt *o)
{
	if (is_dir(lav->arg) && !o->a)
	{
		if (lav->arg[0]!= '.')
			ft_printf("%s:\n", lav->arg);
	}
	else if (is_dir(lav->arg) && o->a)
		ft_printf("%s:\n", lav->arg);
}

int				is_opt(char *fmt)
{
	int			i;
	struct stat s;

	i = 0;
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

char	*get_path(char *dir, char *file)
{
	size_t	len1;
	size_t	len2;
	char	*name;

	if (!dir || ft_strcmp(dir, "./") == 0)
		return (file);
	len1 = ft_strlen(dir);
	len2 = ft_strlen(file);
	if (!(name = ft_strnew((len1 + len2) + 1)))
		return (NULL);
	ft_memcpy(name, dir, len1);
	name[len1] = '/';
	ft_memcpy((name + len1) + 1, file, len2);
	return (name);
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
